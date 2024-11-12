set schema 'forum2';

create or replace view forum2.user as
  select * 
  from forum2._user
  where nickname <> 'Anonymous';

----- USER

-- CREATE
start transaction;
insert into forum2.user(nickname, pass, email)
  values ('Vladimir', 'russia4ever', 'theboss@krml.ru');

-- READ
select * from forum2.user;
rollback;


-- UPDATE  
start transaction;
update forum2.user
set pass = '12345678'
where nickname = 'Alex';
rollback;

-- Trigger sur vue user
create or replace function forum2.user_update() returns trigger as $$
begin
  if (old.nickname <> new.nickname) then 
    raise exception 'Vous ne pouvez pas modifier le nickname.';
  end if;
  update forum2._user
  set pass = new.pass,
      email = new.email
  where nickname = new.nickname;
  return old;
end;
$$ language 'plpgsql';

create trigger tg_user_update
instead of update
on forum2.user
for each row
execute procedure forum2.user_update();

start transaction;
update forum2.user
set pass = '789456123'
where nickname = 'Alex';

update forum2._user
set nickname = 'Alexandre'
where nickname = 'Alex';
rollback;

-- DELETE
create or replace function forum2.user_delete() returns trigger as $$
begin
  perform * from forum2._user where nickname = 'Anonymous';
  if not found then
    insert into forum2._user(nickname, email, pass) 
      values ('Anonymous', 'VGilo6VKjhcv', 'null@nowhere.space');
  end if;
  update forum2._document
  set author = 'Anonymous'  
  where author = old.nickname;
  delete from forum2._user
  where nickname = old.nickname;
  return old;
end;
$$ language 'plpgsql';

create trigger tg_user_delete
instead of delete
on forum2.user
for each row
execute procedure forum2.user_delete();

start transaction;
delete from forum2.user where nickname = 'Alex';
select * from forum2._document;
select * from forum2.user;
rollback;

---- POST

create or replace view forum2.post as
  select *
  from forum2._post natural join forum2._document;

-- CREATE
create or replace function forum2.post_create() returns trigger as $$
declare
  iddoctemp forum2._document.iddoc%type; -- ou integer
begin
  insert into forum2._document (content, author) 
    values (new.content, new.author)
    returning iddoc into iddoctemp;
  insert into forum2._post(iddoc) values (iddoctemp);
  return new;
end;
$$ language 'plpgsql';

create trigger tg_post_create
instead of insert
on forum2.post for each row
execute procedure forum2.post_create();

start transaction;
insert into forum2.post(content,author)
values('Lorem ipsum dolor sit amet, consectetur adipiscing elit. ','Félix');
select * from forum2.post;
rollback;

-- READ
select * from forum2.post;

-- UPDATE
create or replace function forum2.post_update() returns trigger as $$
begin
  if (new.iddoc <> old.iddoc) or (new.create_date <> old.create_date) or (new.author <>old.author) then
    raise exception 'Vous n''avez le droit de changer que le contenu.'; 
  end if;
  update forum2._document
  set content = new.content
  where iddoc = new.iddoc;
  return new;
end;
$$ language 'plpgsql';

create trigger tg_post_update
instead of update
on forum2.post for each row
execute procedure forum2.post_update();

start transaction;
update forum2.post set content = 'seiryoku zenyo !' where iddoc = 2;
select * from forum2.post;
update forum2.post set author = 'Félix' where author = 'Arthur';
rollback;

-- DELETE

-- EVOCATION DES DIFFERENTES SOLUTIONS : YAPUKA

---- COMMENT

create or replace view forum2.comment as
  select *
  from forum2._comment natural join forum2._document;
  
