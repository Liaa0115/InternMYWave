CREATE TABLE employees (
    id INTEGER,
    name TEXT NOT NULL,
    position TEXT NOT NULL,
    department TEXT NOT NULL,
    salary NUMERIC NOT NULL
);

CREATE TABLE sales (
    order_id INTEGER,
    customer_id INTEGER NOT NULL,
    product_id INTEGER NOT NULL,
    quantity INTEGER NOT NULL,
    sale_date DATE NOT NULL
);

CREATE TABLE customers (
    customer_id INTEGER,
    customer_name TEXT NOT NULL,
    city TEXT NOT NULL
);

CREATE TABLE orders (
    order_id INTEGER,
    order_date DATE NOT NULL,
    customer_id INTEGER NOT NULL,
    total_amount NUMERIC NOT NULL
);

CREATE TABLE inventories (
    product_id INTEGER,
    product_name TEXT NOT NULL,
    quantity INTEGER NOT NULL,
    price NUMERIC NOT NULL
);

ALTER TABLE employees
ADD CONSTRAINT pk_employees_id PRIMARY KEY (id);

ALTER TABLE customers
ADD CONSTRAINT pk_customers_id PRIMARY KEY (customer_id);

ALTER TABLE inventories
ADD CONSTRAINT pk_inventories_id PRIMARY KEY (product_id);

ALTER TABLE orders
ADD CONSTRAINT pk_orders_id PRIMARY KEY (order_id);

ALTER TABLE sales
ADD CONSTRAINT pk_sales PRIMARY KEY (order_id, product_id);

ALTER TABLE orders
ADD CONSTRAINT fk_orders_customer_id FOREIGN KEY (customer_id)
REFERENCES customers(customer_id);

ALTER TABLE sales
ADD CONSTRAINT fk_sales_order_id FOREIGN KEY (order_id)
REFERENCES orders(order_id);

ALTER TABLE sales
ADD CONSTRAINT fk_sales_customer_id FOREIGN KEY (customer_id)
REFERENCES customers(customer_id);

ALTER TABLE sales
ADD CONSTRAINT fk_sales_product_id FOREIGN KEY (product_id)
REFERENCES inventories(product_id);