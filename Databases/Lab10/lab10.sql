create database lab10;
create table books(
    book_id integer primary key,
    title varchar,
    author varchar,
    price decimal,
    quantity integer
);
create table orders(
    order_id integer primary key,
    book_id integer references books,
    customer_id integer,
    order_date date,
    quantity integer
);
create table customers(
    customer_id integer primary key,
    name varchar,
    email varchar
);

insert into books (book_id, title, author, price, quantity) values
    (1, 'Database 101', 'A. Smith', 40.0, 10),
    (2, 'Learn SQL', 'B. Johnson', 35.0, 15),
    (3, 'Advanced DB', 'C. Lee', 50.0, 5);
insert into customers (customer_id, name, email) values
    (101, 'John Doe', 'johndoe@example.com'),
    (102, 'Jane Doe', 'janedoe@example.com');

---1
begin;
insert into orders (order_id, book_id, customer_id, order_date, quantity) values
    (1, 1, 101, now(), 2);
update books set quantity = quantity - 2
where book_id = 1;
commit;

-- delete from orders where order_id = 2;
---2
begin transaction isolation level read committed;
savepoint save;
insert into orders (order_id, book_id, customer_id, order_date, quantity) values
    (2, 3, 102,now(), 10);
-- rollback;
do $$
begin
    if (select books.quantity from books where book_id = 3) < 10 then rollback;
     else update books set quantity = quantity - 10 where book_id = 3;
    end if;
end$$;
commit;

---3
begin transaction isolation level read committed;
update books set price = 100.0 where book_id = 2;
commit;

---4
begin;
update customers set email = 'joedoe@example.com' where name = 'John Doe';
commit;

select * from customers;

