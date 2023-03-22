# Write your MySQL query statement below
WITH new_table_2 AS (WITH new_table AS (SELECT D.name AS "Department", E.name AS "Employee", E.salary FROM Department D INNER JOIN Employee E ON D.id=E.departmentId) SELECT *, dense_rank() OVER (PARTITION BY Department ORDER BY salary DESC) AS "rank" FROM new_table) SELECT Department, Employee, salary AS "Salary" FROM new_table_2 WHERE `rank`=1;