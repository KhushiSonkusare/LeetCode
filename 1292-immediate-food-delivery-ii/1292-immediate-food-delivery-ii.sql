# Write your MySQL query statement below
with X as (select *, row_number() over (partition by customer_id order by order_date) as rn from Delivery),
FirstOrders as (select * from X where rn=1)
select round(sum(if(order_date=customer_pref_delivery_date, 1, 0))/count(*)*100, 2) as immediate_percentage from FirstOrders