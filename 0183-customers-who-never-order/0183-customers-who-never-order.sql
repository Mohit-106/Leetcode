# Write your MySQL query statement below

-- Step 1 get all customer record
-- Whether they ordered something or not ordered something
select c.name as Customers
from Customers c
left join Orders o
on c.id = o.customerId
where o.customerId is NULL