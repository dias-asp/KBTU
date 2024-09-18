create database lab2;
create table countries (
    country_id serial primary key,
    country_name varchar(100),
    region_id integer,
    population integer
);

insert into countries (country_name, region_id, population)
values ('Russia', 1, 500000000);

insert into countries (country_name)
values ('USA');

insert into countries (country_name, region_id)
values ('China', null);

insert into countries (country_name, region_id, population)
values ('Norway', 2, 100),
       ('Sweden', 2, 1000),
       ('Finland', 2, 10000);

alter table countries
alter column country_name set default 'Kazakhstan';

insert into countries (country_name)
values (default);

insert into countries
default values;

create table countries_new (
    like countries
);

insert into countries_new
select * from countries;

update countries
set region_id = 1
where region_id is null;

select countries.country_name,  countries.population * 1.1 as "New population"
from countries;

delete from countries
where population < 100000;

delete from countries_new using countries
where countries_new.country_id = countries.country_id
returning *;

delete from countries
returning *;

