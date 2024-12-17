set schema 'bieres';

-- 1.

create or replace view bieres.buveur_pro as
  select * 
  from bieres._buveur natural join bieres._buveur_pro;

create or replace view bieres.buveur_amateur as
  select * 
  from bieres._buveur natural join bieres._buveur_amateur;
  
select * from buveur_pro;
select * from buveur_amateur;

-- 2.

create or replace view bieres.tout_buveur as
  SELECT idbuveur, nomb, prenomb, 'P' as typebuveur, idbarprefere FROM bieres.buveur_pro
  UNION
  SELECT idbuveur, nomb, prenomb, 'A' as typebuveur, '0' as idbarprefere FROM bieres.buveur_amateur;
  
select * from tout_buveur;

-- 3.
drop function if exists ftg_buveur_pro_create();
create or replace function ftg_buveur_pro_create() returns trigger as $$
declare
  idbuveurtemp buveur_pro.idbuveur%type;
begin
  insert into buveur_pro(idbuveur, nomb, prenomb, idbarprefere)
    values (new.idbuveur, new.nomb, new.prenomb, new.idbarprefere)
    returning idbuveur into idbuveurtemp;
  insert into bieres.buveur(idbuveur, nomb, prenomb) values (idbuveurtemp, new.nomb, new.prenomb);
  return new;
end;
$$ language 'plpgsql';

drop trigger if exists tg_buveur_pro_create on bieres.buveur_pro;
create trigger tg_buveur_pro_create
instead of insert
on bieres.buveur_pro for each row
execute procedure ftg_buveur_pro_create();

insert into bieres.buveur_pro(idbuveur, nomb, prenomb, idbarprefere) values (7, 'Douglas', 'Kirk', 5);

-- 4.
alter table bieres._aimer 
  drop constraint _aime_fk_biere;
alter table bieres._aimer
  add constraint _aime_fk_biere 
    foreign key (idbiere) references bieres._biere(idbiere) on delete cascade;
alter table bieres._servir
  drop constraint _servir_fk_biere;
alter table bieres._servir
  add constraint _servir_fk_biere 
    foreign key (idbiere) references bieres._biere(idbiere) on delete cascade;

drop function if exists ftg_biere_delete();
create or replace function ftg_biere_delete() returns trigger as $$
begin
  delete from _biere where idbiere = old.idbiere;
  return old;
end;
$$ language 'plpgsql';

create trigger tg_biere_delete
after delete 
on _biere for each row
execute procedure ftg_biere_delete();

delete from bieres._biere where idbiere = 1;

-- 5.
create or replace function ftg_check_nb_bars() returns trigger as $$
begin
  if (select COUNT(idbar) from bieres._buveur natural join _frequenter) > 3 then
    raise 'Un buveur ne peut pas fréquenter plus de trois bars !' using errcode = 23521;
  end if;
end;
$$ language 'plpgsql';

create trigger tg_check_nb_bars
before update
on bieres._frequenter for each row
execute procedure ftg_check_nb_bars();

-- 6.
select nombiere
from bieres._buveur
join bieres._aimer on bieres._buveur.idbuveur = bieres._aimer.idbuveur
join bieres._biere on bieres._aimer.idbiere = bieres._biere.idbiere
where nomb = 'Eastwood' and prenomb = 'Clint';

-- 7
-- J'envisagerais de créer un trigger qui empêche d'ajouter plus d'une bière par idbar.
