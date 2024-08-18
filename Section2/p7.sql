ALTER TABLE orders
ADD CONSTRAINT fk_orders_customer_id FOREIGN KEY (customer_id)
REFERENCES customers(customer_id) ON DELETE CASCADE;

ALTER TABLE sales
ADD CONSTRAINT fk_sales_customer_id FOREIGN KEY (customer_id)
REFERENCES customers(customer_id) ON DELETE CASCADE;



DELETE FROM customers
WHERE customer_id = 15;



BEGIN;

DELETE FROM orders
WHERE customer_id = specific_customer_id;

DELETE FROM sales
WHERE customer_id = specific_customer_id;

DELETE FROM customers
WHERE customer_id = specific_customer_id;

COMMIT;
