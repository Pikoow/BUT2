-- Listez les utilisateurs.
SELECT nickname FROM forum1._user;

-- Listez les documents publiés par Félix en les classant par ordre chornologique croissant.
SELECT * FROM forum1._document
WHERE author = 'Félix'
ORDER BY create_date asc;

-- Listez la hiérarchie des commentaires associés au post numéro 1 (celui de Félix disant bonjour à tout le monde. S'il
-- possède un identifiant différent, vous adapterez la requête). Cette hiérarchie est composée de l'id d'un commentaire
-- et de l'id du document auquel il répond.
(SELECT *, 'post' AS type
FROM forum1._document d
WHERE author = 'Félix'
  AND iddoc in (SELECT iddoc from forum1._post)
UNION
SELECT *, 'comment' as type
FROM forum1._document d
WHERE author = 'Félix'
  AND iddoc in (SELECT iddoc from forum1._comment))
ORDER BY create_date DESC;

-- 
CREATE OR REPLACE FUNCTION commentaires_sql(ref_in integer)
  returns table (iddoc integer, ref integer) as $$
WITH RECURSIVE refset(iddoc, ref) AS (
  SELECT iddoc, ref
  FROM forum1._comment
  WHERE ref = ref_in
  UNION
  SELECT c.iddoc, c.ref
  FROM refset r INNER JOIN forum1._comment c
  ON r.iddoc = c.ref)
SELECT * FROM refset;
$$ language 'sql';

CREATE OR REPLACE FUNCTION commentaires(ref_in integer)
  returns table (iddoc integer, ref integer) as $$
BEGIN
  perform * from forum1._document d where d.iddoc = ref_in;
  if not found then
    raise notice 'LE document % n''existe pas', ref_in;
   end if;
   return query
    select *
    from commentaires_sql(ref_in);
end;
$$ language 'plpgsql';

SELECT * FROM commentaires(1);

CREATE OR REPLACE FUNCTION user_delete() returns trigger as $$
BEGIN
  if old.nickname = 'Anonymous' then
    raise exception 'L''utilisateur Anonymous n''existe pas';
  end if;
  update forum1._document
  set author = 'Anonymous'
  where author = old.nickname;
  return old;
end;
$$ language 'plpgsql';

create trigger tg_user_delete
before delete
on forum1._user for each row
execute procedure user_delete();
