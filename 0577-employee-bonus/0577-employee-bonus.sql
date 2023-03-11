# Write your MySQL query statement below
# WITH Bonus_table AS (SELECT name, bonus FROM Bonus WHERE bonus<1000) SELECT Employee.name AS name, Bonus_table.bonus AS bonus FROM Employee LEFT JOIN

SELECT Employee.name, Bonus.bonus FROM Employee LEFT JOIN Bonus ON Employee.empId = Bonus.empId WHERE bonus is null OR bonus<1000;