-- Last updated: 3/18/2026, 2:29:30 PM
# Write your MySQL query statement below

select Max(salary) as SecondHighestSalary from Employee 
where salary<(select max(salary) from employee)