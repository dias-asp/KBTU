create database lab8;

create table salesman (
    salesman_id int primary key ,
    name varchar(50),
    city varchar(50),
    commission decimal(5, 2)
);

create table customers (
    customer_id int primary key ,
    cust_name varchar(50),
    city varchar(50),
    grade int,
    salesman_id int references salesman(salesman_id)
);

create table orders (
    ord_no int primary key ,
    purch_amt decimal(10, 2),
    ord_date date,
    customer_id int references customers(customer_id),
    salesman_id int references salesman(salesman_id)
);

insert into salesman values
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'Mc Lyon', 'Paris', 0.14),
(5003, 'Lauson Hen', 'Rome', 0.12),
(5007, 'Paul Adam', 'Rome', 0.13);

insert into customers values
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3001, 'Brad Guzan', 'London', 100, 5005),
(3004, 'Fabian Johns', 'Paris', 300, 5006),
(3007, 'Geoff Camero', 'Berlin', 100, 5003),
(3009, 'Julian Green', 'London', 300, 5005);

insert into orders values
(70001, 150.5, '2012-10-05', 3005, 5002),
(70009, 270.65, '2012-09-10', 3001, 5005),
(70002, 65.26, '2012-10-05', 3002, 5001),
(70004, 110.5, '2012-08-17', 3009, 5005),
(70007, 948.5, '2012-09-10', 3005, 5002),
(70005, 2400.6, '2012-07-27', 3007, 5003),
(70008, 5760, '2012-09-10', 3002, 5001);

create role junior_dev login;

create view new_york as
    select *
    from salesman
    where city = 'New York';

create view order_customer_salesman as
    select customers.cust_name, salesman.name
    from orders join customers on orders.customer_id = customers.customer_id join salesman on orders.salesman_id = salesman.salesman_id;
grant all privileges on order_customer_salesman to junior_dev;

create view customers_highest_grade as
    select * from customers
    where grade = (select max(grade) from customers);
grant select on customers_highest_grade to junior_dev;

create view count_salesman_city as
    select city, count(*) from salesman
    group by city;

create view salesman_more_1_customer as
    select customers.salesman_id, salesman.name from customers join salesman on customers.salesman_id = salesman.salesman_id
    group by customers.salesman_id, salesman.name
    having count(*) > 1;

create role intern;
grant junior_dev to intern;