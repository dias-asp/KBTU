create database lab5;

select sum(amount) from orders;
select avg(amount) from orders;
select count(distinct customer_name) from customers;
select min(amount) from orders;

select * from customers
where customer_name like '%b';

select ord_no, amount, date, orders.customer_id, customer_name from orders join customers on orders.customer_id = customers.customer_id
where city = 'New York';

select distinct customers.customer_name, customers.customer_id, city, grade, customers.salesman_id from customers join orders on orders.customer_id = customers.customer_id
where amount > 10;

select sum(grade) from customers;

select distinct customer_name from customers group by customer_name;

select max(customers.grade) from customers;