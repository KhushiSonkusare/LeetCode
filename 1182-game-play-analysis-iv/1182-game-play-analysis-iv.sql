with x as (
    select 
        player_id,
        event_date,
        rank() over(partition by player_id order by event_date) as rn
    from Activity
),
FirstLogin as (
    select player_id, event_date
    from x
    where rn = 1
)
select 
    round(
        count(*) / (select count(distinct player_id) from Activity),
        2
    ) as fraction
from FirstLogin f
join Activity a
  on f.player_id = a.player_id
 and datediff(a.event_date, f.event_date) = 1;
