
CREATE TABLE users (
    user_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    role VARCHAR(20) CHECK (role IN ('admin', 'manager', 'customer')),
    password_hash VARCHAR(255) NOT NULL,
    loyalty_level INTEGER DEFAULT 0 CHECK (loyalty_level IN (0, 1))
);

CREATE TABLE products (
    product_id SERIAL PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    price DECIMAL(10, 2) CHECK (price > 0),
    stock_quantity INTEGER DEFAULT 0 CHECK (stock_quantity >= 0)
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    user_id INTEGER REFERENCES users(user_id) ON DELETE CASCADE,
    status VARCHAR(20) DEFAULT 'pending' CHECK (status IN ('pending', 'completed', 'canceled', 'returned')),
    total_price DECIMAL(10, 2) DEFAULT 0,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE order_items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INTEGER REFERENCES orders(order_id) ON DELETE CASCADE,
    product_id INTEGER REFERENCES products(product_id) ON DELETE RESTRICT,
    quantity INTEGER NOT NULL CHECK (quantity > 0),
    price DECIMAL(10, 2) NOT NULL
);

CREATE TABLE order_status_history (
    history_id SERIAL PRIMARY KEY,
    order_id INTEGER REFERENCES orders(order_id) ON DELETE CASCADE,
    old_status VARCHAR(20),
    new_status VARCHAR(20),
    changed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    changed_by INTEGER REFERENCES users(user_id) ON DELETE SET NULL
);

CREATE TABLE audit_log (
    log_id SERIAL PRIMARY KEY,
    entity_type VARCHAR(20) CHECK (entity_type IN ('order', 'product', 'user')),
    entity_id INTEGER,
    operation VARCHAR(20) CHECK (operation IN ('insert', 'update', 'delete')),
    performed_by INTEGER,
    performed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
CREATE OR REPLACE FUNCTION update_order_status(
    p_order_id INTEGER,
    p_new_status VARCHAR,
    p_user_id INTEGER
) RETURNS VOID AS $$
DECLARE
    v_old_status VARCHAR;
BEGIN
    SELECT status INTO v_old_status FROM orders WHERE order_id = p_order_id;
    
    UPDATE orders SET status = p_new_status WHERE order_id = p_order_id;
    
    INSERT INTO order_status_history (order_id, old_status, new_status, changed_by)
    VALUES (p_order_id, v_old_status, p_new_status, p_user_id);
    
    INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
    VALUES ('order', p_order_id, 'update', p_user_id);
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_order_status_history(p_order_id INTEGER)
RETURNS TABLE(
    old_status VARCHAR,
    new_status VARCHAR,
    changed_at TIMESTAMP,
    changed_by INTEGER
) AS $$
BEGIN
    RETURN QUERY
    SELECT osh.old_status, osh.new_status, osh.changed_at, osh.changed_by
    FROM order_status_history osh
    WHERE osh.order_id = p_order_id
    ORDER BY osh.changed_at;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_order_status(p_order_id INTEGER)
RETURNS VARCHAR AS $$
DECLARE
    v_status VARCHAR;
BEGIN
    SELECT status INTO v_status FROM orders WHERE order_id = p_order_id;
    RETURN v_status;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_user_order_count(p_user_id INTEGER)
RETURNS INTEGER AS $$
DECLARE
    v_count INTEGER;
BEGIN
    SELECT COUNT(*) INTO v_count FROM orders WHERE user_id = p_user_id;
    RETURN v_count;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_total_spent_by_user(p_user_id INTEGER)
RETURNS DECIMAL AS $$
DECLARE
    v_total DECIMAL;
BEGIN
    SELECT COALESCE(SUM(total_price), 0) INTO v_total 
    FROM orders 
    WHERE user_id = p_user_id AND status = 'completed';
    RETURN v_total;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION can_return_order(p_order_id INTEGER)
RETURNS BOOLEAN AS $$
DECLARE
    v_status VARCHAR;
    v_order_date TIMESTAMP;
    v_days_passed INTEGER;
BEGIN
    SELECT status, order_date INTO v_status, v_order_date
    FROM orders WHERE order_id = p_order_id;
    
    v_days_passed := EXTRACT(DAY FROM (CURRENT_TIMESTAMP - v_order_date));
    
    RETURN v_status = 'completed' AND v_days_passed <= 30;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_audit_log_by_user(p_user_id INTEGER)
RETURNS TABLE(
    log_id INTEGER,
    entity_type VARCHAR,
    entity_id INTEGER,
    operation VARCHAR,
    performed_at TIMESTAMP
) AS $$
BEGIN
    RETURN QUERY
    SELECT al.log_id, al.entity_type, al.entity_id, al.operation, al.performed_at
    FROM audit_log al
    WHERE al.performed_by = p_user_id
    ORDER BY al.performed_at DESC;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION create_order(
    p_user_id INTEGER,
    p_items JSON
) RETURNS INTEGER AS $$
DECLARE
    v_order_id INTEGER;
    v_item JSON;
    v_product_id INTEGER;
    v_quantity INTEGER;
    v_price DECIMAL;
    v_stock INTEGER;
    v_total DECIMAL := 0;
BEGIN
    
    INSERT INTO orders (user_id, status, total_price)
    VALUES (p_user_id, 'pending', 0)
    RETURNING order_id INTO v_order_id;
    
    FOR v_item IN SELECT * FROM json_array_elements(p_items)
    LOOP
        v_product_id := (v_item->>'product_id')::INTEGER;
        v_quantity := (v_item->>'quantity')::INTEGER;
        
        SELECT price, stock_quantity INTO v_price, v_stock
        FROM products WHERE product_id = v_product_id;
        
        IF v_stock < v_quantity THEN
            RAISE EXCEPTION 'Недостаточно товара на складе для продукта %', v_product_id;
        END IF;
        
        INSERT INTO order_items (order_id, product_id, quantity, price)
        VALUES (v_order_id, v_product_id, v_quantity, v_price);
        
        UPDATE products SET stock_quantity = stock_quantity - v_quantity
        WHERE product_id = v_product_id;
        
        v_total := v_total + (v_price * v_quantity);
    END LOOP;
    
    UPDATE orders SET total_price = v_total WHERE order_id = v_order_id;
    
    INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
    VALUES ('order', v_order_id, 'insert', p_user_id);
    
    RETURN v_order_id;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION update_order_date_on_status_change()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.status != OLD.status THEN
        NEW.order_date := CURRENT_TIMESTAMP;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_update_order_date
BEFORE UPDATE ON orders
FOR EACH ROW
EXECUTE FUNCTION update_order_date_on_status_change();

CREATE OR REPLACE FUNCTION update_order_total_on_price_change()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.price != OLD.price THEN
        UPDATE orders o
        SET total_price = (
            SELECT SUM(oi.quantity * p.price)
            FROM order_items oi
            JOIN products p ON oi.product_id = p.product_id
            WHERE oi.order_id = o.order_id
        )
        WHERE o.order_id IN (
            SELECT DISTINCT order_id 
            FROM order_items 
            WHERE product_id = NEW.product_id
        );
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_update_order_total
AFTER UPDATE ON products
FOR EACH ROW
EXECUTE FUNCTION update_order_total_on_price_change();

CREATE OR REPLACE FUNCTION audit_products()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
        VALUES ('product', NEW.product_id, 'insert', 1);
    ELSIF TG_OP = 'UPDATE' THEN
        INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
        VALUES ('product', NEW.product_id, 'update', 1);
    ELSIF TG_OP = 'DELETE' THEN
        INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
        VALUES ('product', OLD.product_id, 'delete', 1);
    END IF;
    RETURN COALESCE(NEW, OLD);
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_audit_products
AFTER INSERT OR UPDATE OR DELETE ON products
FOR EACH ROW
EXECUTE FUNCTION audit_products();

CREATE OR REPLACE FUNCTION audit_users()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
        VALUES ('user', NEW.user_id, 'insert', 1);
    ELSIF TG_OP = 'UPDATE' THEN
        INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
        VALUES ('user', NEW.user_id, 'update', 1);
    ELSIF TG_OP = 'DELETE' THEN
        INSERT INTO audit_log (entity_type, entity_id, operation, performed_by)
        VALUES ('user', OLD.user_id, 'delete', 1);
    END IF;
    RETURN COALESCE(NEW, OLD);
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_audit_users
AFTER INSERT OR UPDATE OR DELETE ON users
FOR EACH ROW
EXECUTE FUNCTION audit_users();

INSERT INTO users (name, email, role, password_hash, loyalty_level) VALUES
('Ivan Adminov', 'admin@store.com', 'admin', 'hash1', 1),
('Petr Managerov', 'manager@store.com', 'manager', 'hash2', 0),
('Alexey Buyers', 'customer@store.com', 'customer', 'hash3', 0),
('Maria Klientova', 'client@store.com', 'customer', 'hash4', 1);
-- Добавление продуктов
INSERT INTO products (name, price, stock_quantity) VALUES
('ASUS Laptop', 45000.00, 10),
('Logitech Mouse', 1500.00, 50),
('Razer Keyboard', 3500.00, 30),
('Samsung 24" Monitor', 15000.00, 15),
('Logitech Webcam', 4500.00, 25),
('Sony Headphones', 8000.00, 40),
('USB Cable', 300.00, 100),
('500GB SSD', 5000.00, 20),
('16GB RAM', 6000.00, 35),
('Mouse Pad', 500.00, 60);


INSERT INTO orders (user_id, status, total_price, order_date) VALUES
(3, 'completed', 50000.00, CURRENT_TIMESTAMP - INTERVAL '5 days'),
(4, 'pending', 7500.00, CURRENT_TIMESTAMP - INTERVAL '1 day'),
(3, 'completed', 15000.00, CURRENT_TIMESTAMP - INTERVAL '15 days');


INSERT INTO order_items (order_id, product_id, quantity, price) VALUES
(1, 1, 1, 45000.00),
(1, 3, 1, 3500.00),
(1, 2, 1, 1500.00),
(2, 4, 1, 15000.00),
(3, 6, 1, 8000.00),
(3, 8, 1, 5000.00),
(3, 9, 1, 6000.00);


INSERT INTO order_status_history (order_id, old_status, new_status, changed_by) VALUES
(1, 'pending', 'completed', 1),
(3, 'pending', 'completed', 2);

COMMIT;

SELECT 'База данных успешно создана и инициализирована!' as message;
SELECT COUNT(*) as users_count FROM users;
SELECT COUNT(*) as products_count FROM products;
SELECT COUNT(*) as orders_count FROM orders;
