# Write your MySQL query statement below
SELECT USER_ID,   CONCAT(UPPER(SUBSTR(NAME,1,1)),LOWER(SUBSTR(NAME,2))) AS name FROM USERS order by user_id;