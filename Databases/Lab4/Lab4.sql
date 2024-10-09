create database lab4;

select * from warehouses;

select * from boxes where
                        value > 150;

select contents
from
    boxes
group by contents;

select
    *
from boxes where code in(
    select distinct on (contents) code from boxes
    );

select boxes.warehouse, count(*)
from boxes
group by warehouse;

select boxes.warehouse, count(*)
from boxes
group by warehouse
having count(*) > 2;

insert into warehouses (code, location, capacity)
values (6, 'New York', 3);

insert into boxes (code, contents, value, warehouse)
values ('H5RT', 'Papers', 200, 2);

update boxes
set value = value * 0.85
where code in (
    select code from boxes
                order by value desc
                limit 1 offset 2
    );

delete from boxes
where value < 150;

delete from boxes
where warehouse in (select code from warehouses where location = 'New York')
returning *;