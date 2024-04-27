# Function that returns all records based on a pattern: prefix of phone number
"""
create or replace function get_by_phone_prefix(pr varchar)
returns TABLE(name varchar(255), phone varchar(255)) as
$$
begin
    return query
    select phonebook.name, phonebook.phone from phonebook 
	where phonebook.phone like concat(pr, '%');
end;
$$
language plpgsql;
"""

# Procedure to insert new user by name and phone, update phone if user already exists
"""
create or replace procedure insert_update(
    username varchar(255),
    phone_new varchar(255)
)
as $$
begin
    IF EXISTS(SELECT id FROM phonebook WHERE name = username) THEN
    UPDATE phonebook SET phone = phone_new WHERE name = username;
    ELSE
    INSERT INTO phonebook(name, phone)
    VALUES(username, phone_new);
    END IF;

end;
$$
language plpgsql;
"""

# Procedure to insert many new users by list of name and phone. Use loop and if statement in stored procedure. 
# Check correctness of phone in procedure
"""
create or replace procedure insert_many(
    username varchar(255)[],
    phone_new varchar(255)[]
)
as $$
begin
    FOR i IN 1..array_length(username, 1) LOOP
	IF LENGTH(phone_new[i]) < 12 THEN 
		INSERT INTO phonebook(name, phone) VALUES(username[i], phone_new[i]);
	END IF;
	END LOOP;
end;
$$
language plpgsql;
"""