-- Last updated: 3/18/2026, 2:29:27 PM
select score, dense_rank() over(order by score desc) as "Rank"
from scores;
