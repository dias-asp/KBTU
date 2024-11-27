create database lab9;
create function increase_value(val integer) returns integer as
$$ begin
    return val + 10;
end; $$
language plpgsql;

create or replace function compare_numbers(a real, b real, out res varchar) as
$$ begin
    if a > b then
        res := 'GREATER';
    elseif a < b then
        res := 'LESSER';
    else
        res := 'EQUAL';
    end if;
end; $$
language plpgsql;

drop function number_series;
create or replace function number_series(n integer) returns text as
$$ declare
    t text := '';
    begin
    for x in 1..n loop
        t := t || x || ' ';
    end loop;
    return t;
end;$$
language plpgsql;

select number_series(10);

create table employees(
    name varchar,
    id integer primary key,
    salary integer
);
insert into employees values(
    'Dias', 1, 1000
);
create or replace function find_employee(name_to_find varchar)
    returns table (
        name varchar,
        id integer,
        salary integer
    )
    as
$$ begin
    return query select * from employees
    where employees.name = name_to_find;
end;$$
language plpgsql;

select * from find_employee('Dias');

create table products(
    name varchar,
    price integer,
    amount integer,
    category varchar
);
create or replace function list_products(list_category varchar)
    returns table(
        name varchar,
        price integer,
        amount integer,
        category varchar
    ) as
$$ begin
    return query select * from products
    where products.category = list_category;
end;$$
language plpgsql;

select * from list_products('Electronics');


create or replace function calculate_bonus(salary integer) returns integer as
$$ begin
    return random() * salary;
end;$$
language plpgsql;
create or replace function update_salary(id integer) returns void as
$$ begin
    update employees set
        salary = salary + calculate_bonus(salary)
    where employees.id = update_salary.id;
end;$$
language plpgsql;

select update_salary(1);
select * from employees;

drop function complex_calculation(a integer, b integer, c integer, x integer, y integer);
drop function complex_calculation(integer, integer, integer, out integer, integer);
create or replace function complex_calculation(a integer, b integer, c text, out x integer, out y text) as
$$
begin
    <<add>>
    begin
        x := a + b;
    end add;

    <<alter_text>>
    begin
        y := c || c;
    end alter_text;
end;$$
language plpgsql;

select complex_calculation(1, 2, 'asd');


do $$
<<test>>
declare
    s integer := 0;
    n varchar := '';
begin
    select salary, name into s, n from employees
    where id = 1;
    raise notice 'salary is ', s, n;
end test$$;