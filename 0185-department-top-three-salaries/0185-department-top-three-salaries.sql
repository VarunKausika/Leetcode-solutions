# Write your MySQL query statement below
WITH Rank_table AS (SELECT Department.name AS "Department", Employee.name AS "Employee", Employee.salary AS "Salary", (dense_rank() over (PARTITION BY departmentId ORDER BY salary DESC)) AS "Rank" FROM (Employee INNER JOIN Department ON Employee.departmentId=Department.id)) SELECT Department, Employee, Salary FROM Rank_table WHERE `Rank` IN (1, 2, 3);
