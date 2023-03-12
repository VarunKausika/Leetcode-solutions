# Write your MySQL query statement below
WITH new_table AS (SELECT class, COUNT(student) as n_students FROM Courses GROUP BY class HAVING n_students>=5) SELECT class FROM new_table;