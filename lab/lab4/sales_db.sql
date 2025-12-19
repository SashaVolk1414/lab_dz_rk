


CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255),
    price DECIMAL(10,2)
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    order_date DATE DEFAULT CURRENT_DATE
);

CREATE TABLE order_items (
    order_item_id SERIAL PRIMARY KEY,
    order_id INTEGER REFERENCES orders(order_id),
    product_id INTEGER REFERENCES products(id),
    quantity INTEGER,
    total_price DECIMAL(10,2)
);


CREATE INDEX idx_date ON orders(order_date);
CREATE INDEX idx_product ON order_items(product_id);
INSERT INTO products (name,price) VALUES
    ('Laptop', 999.99),
    ('Mouse', 25.50),
    ('Keyboard', 75.00),
    ('Monitor', 299.99),
    ('USB Cable', 9.99);
