# Write your MySQL query statement below
select
    sell_date,
    COUNT(DISTINCT product) as num_sold,
     GROUP_CONCAT(DISTINCT product) as products
from Activities
group by sell_date;