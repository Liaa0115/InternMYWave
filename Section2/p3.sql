SELECT
    SUM(s.quantity * i.price) AS total_sales,
    AVG(s.quantity * i.price) AS avg_sales,
    SUM(s.quantity) AS total_sold,
    AVG(s.quantity) AS avg_per_order
FROM
    sales s
JOIN
    inventories i ON s.product_id = i.product_id;