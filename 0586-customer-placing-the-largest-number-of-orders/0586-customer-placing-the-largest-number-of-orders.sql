# Write your MySQL query statement below
# SELECT customer_number, count(order_number) OVER (PARTITION BY customer_number) AS n_orders FROM Orders;
WITH new_table AS (SELECT customer_number, count(order_number) AS n_orders FROM Orders GROUP BY customer_number) SELECT customer_number FROM new_table WHERE n_orders = (SELECT MAX(n_orders) FROM new_table);