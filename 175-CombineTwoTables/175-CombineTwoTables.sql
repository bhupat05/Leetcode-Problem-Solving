-- Last updated: 3/18/2026, 2:29:31 PM
# Write your MySQL query statement below

select person.firstName,person.lastName,Address.city,Address.state
from person 
left join Address on person.personId = Address.personId;
