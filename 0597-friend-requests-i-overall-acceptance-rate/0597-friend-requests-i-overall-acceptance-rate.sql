# Write your MySQL query statement below
SELECT CASE
    WHEN (SELECT count(sender_id) FROM FriendRequest) > 0 THEN ROUND((WITH new_table1 AS (SELECT (10*requester_id+accepter_id) AS ID FROM RequestAccepted) SELECT COUNT(DISTINCT(ID)) AS total_requests FROM new_table1)/(WITH new_table2 AS (SELECT (10*sender_id+send_to_id) AS ID FROM FriendRequest) SELECT COUNT(DISTINCT(ID)) AS total_requests FROM new_table2), 2)
    ELSE 0 
END AS accept_rate;