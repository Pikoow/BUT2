SET SCHEMA 'td2';

start transaction;

select classe from enfant where nopers = 1;

commit;
