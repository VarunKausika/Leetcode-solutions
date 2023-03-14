# Write your MySQL query statement below
WITH new_table AS (SELECT num, count(num) FROM MyNumbers GROUP BY num HAVING count(num)=1) SELECT max(num) AS num FROM new_table;