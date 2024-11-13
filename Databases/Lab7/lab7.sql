create index countries_name on countries(name);

create index employees_name_surname on employees(name, surname);

create unique index employees_salary on employees(salary);

create index employees_name_substring on employees(substring(name from 1 for 4));

create index employees_departmentid_salary on employees(department_id, salary);
create index departments_departmentid_budget on departments(department_id, budget);