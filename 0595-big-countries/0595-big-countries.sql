# Write your MySQL query statement below
select name,population, World.area 
from World
where World.area >= 3000000 or population >= 25000000