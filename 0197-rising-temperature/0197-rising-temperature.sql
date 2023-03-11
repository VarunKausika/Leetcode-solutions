# Write your MySQL query statement below
# SELECT id FROM (SELECT id, temperature - LAG(temperature, 1) OVER (ORDER BY recordDate ASC) AS tempDifference, recordDate - LAG(recordDate, 1) OVER (ORDER BY recordDate ASC) AS dateDifference, temperature, recordDate FROM Weather) AS A WHERE tempDifference>0 AND dateDifference=1;

SELECT w1.id
FROM Weather w1
JOIN Weather w2 ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature

# SELECT id, temperature, recordDate from Weather ORDER BY recordDate ASC;