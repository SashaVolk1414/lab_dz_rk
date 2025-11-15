CREATE DATABASE order_management;

CREATE TABLE products(
    id INT PRIMARY KEY,
	name VARCHAR(255) NOT NULL,
	price DECIMAL(10,2) NOT NULL
);
CREATE TABLE orders(
    order_id INT PRIMARY KEY,
	order_date DATE NOT NULL
);
CREATE TABLE order_items(
    order_item_id INT PRIMARY KEY,
	order_id INT NOT NULL,
	product_id INT NOT NULL,
	quantity INT NOT NULL,
	total_price DECIMAL(10,2) NOT NULL,
	FOREIGN KEY (order_id) REFERENCES orders(order_id),
	FOREIGN KEY (product_id) REFERENCES products(id)
);
INSERT INTO products (id,name, price) VALUES
(1,'Ноутбук ASUS', 75000.00),
(2,'Смартфон iPhone', 89990.00),
(3,'Наушники Sony', 12900.00),
(4,'Клавиатура механическая', 5500.00),
(5,'Компьютерная мышь', 2500.00),
(6,'Монитор 24"', 32000.00);
INSERT INTO orders (order_id,order_date) VALUES
(1,'2024-01-10'),
(2,'2024-01-15'),
(3,'2024-01-20'),
(4,'2024-01-25'),
(5,'2024-02-01');
INSERT INTO order_items (order_item_id,order_id, product_id, quantity, total_price) VALUES
(1,1, 1, 1, 75000.00), 
(2,1, 3, 1, 12900.00), 
(3,2, 2, 1, 89990.00), 
(4,2, 4, 1, 5500.00),  
(5,2, 5, 2, 5000.00),  
(6,3, 6, 1, 32000.00),  
(7,3, 4, 2, 11000.00), 
(8,4, 1, 1, 75000.00), 
(9,4, 2, 1, 89990.00),  
(10,5, 3, 3, 38700.00); 


SELECT * FROM products;

SELECT products.name, order_items.quantity,order_items.total_price
FROM products
JOIN order_items ON products.id=order_items.product_id
WHERE order_items.order_id =2;

SELECT orders.order_id, orders.order_date, SUM(order_items.total_price) AS "общая_стоимость"
FROM orders
JOIN order_items ON order_items.order_id=orders.order_id
WHERE orders.order_id=2
GROUP BY orders.order_id, orders.order_date;

SELECT orders.order_id, orders.order_date, SUM(order_items.total_price) AS "общая_стоимость"
FROM orders 
JOIN order_items ON order_items.order_id=orders.order_id
WHERE orders.order_date BETWEEN '2024-01-15' AND '2024-01-31'
GROUP BY orders.order_id, orders.order_date;

SELECT products.name, SUM(order_items.quantity)
FROM order_items
JOIN products ON order_items.product_id = products.id
JOIN orders ON order_items.order_id = orders.order_id
WHERE orders.order_date BETWEEN '2024-01-01' AND '2024-01-31'
GROUP BY products.id, products.name;


UPDATE products 
SET price = 13900.00
WHERE id=3;

SELECT id,name,price FROM products
WHERE id=3;

DELETE FROM order_items
WHERE order_item_id=5;
SELECT * FROM order_items;

