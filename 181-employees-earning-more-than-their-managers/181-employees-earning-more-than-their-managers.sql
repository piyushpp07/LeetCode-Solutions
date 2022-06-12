# Write your MySQL query statement below
select name as Employee from employee e where e.salary > (select salary from employee s where e.managerid = s.id);