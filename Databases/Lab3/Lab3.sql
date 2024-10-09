create database lab3;

select distinct lastname from employees;

select * from employees where lastname = 'Smith';

select * from employees where lastname in ('Smith', 'Doe');

select * from employees where department = 14;

select lastname from employees;

select * from employees where department in (37, 77);

select SUM(budget) from departments;

select
    d.code, COUNT(*)
from departments d
    left join employees e
        on e.department = d.code
group by d.code;

select
    d.code
from departments d
    left join employees e
        on e.department = d.code
group by d.code
having COUNT(e) > 2;

select
    d.name
from departments d
order by budget desc
offset 1
limit 1;

select
    e.name, e.lastname
from employees e
where e.department in (
    select code
    from departments
    where budget in (select min(budget)
                       from departments)
);

select name from employees where city = 'Almaty';

select * from departments
    where budget > 60000
order by budget asc, code desc;

update departments
    set budget = budget * 0.9
where code in (
    select code
    from departments
    where budget in (select min(budget)
                       from departments)
);

update
    employees
set department = (select code from departments where name = 'IT' limit 1)
where department = (select code from departments where name = 'Research' limit 1);

delete from employees where department = (select code from departments where name = 'IT');

delete from employees;