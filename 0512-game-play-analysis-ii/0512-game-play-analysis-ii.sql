# Write your MySQL query statement below
WITH new_table AS (SELECT player_id, device_id, event_date, (dense_rank() OVER (PARTITION BY player_id ORDER BY event_date ASC)) AS "first_login" FROM Activity) SELECT player_id, device_id FROM new_table WHERE first_login = 1;
