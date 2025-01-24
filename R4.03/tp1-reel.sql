create schema if not exists tp12;
set schema 'tp12';

create table if not exists table_globale(
  gameid INT,
  gametitle varchar(70),
  gamerelease DATE,
  compname VARCHAR(70),
  charname VARCHAR(40)
);

--wbimport -type=text -table="table_globale" -file="/tmp/design_tp_games.csv" -header="true" -delimiter=";";

-- EXERCICE 1

-- Q1 - Illustrer à l'aide de requêtes les anomalies.
-- Anomalie de redondance
SELECT gametitle, gamerelease, compname, COUNT(*) AS repetition
FROM table_globale
GROUP BY gametitle, gamerelease, compname
HAVING COUNT(*) > 1;
-- Il y a énromément de redondance des données.

-- Anomalie de suppression
SELECT gameid, gametitle, COUNT(charname) AS char_count
FROM table_globale
GROUP BY gameid, gametitle
HAVING COUNT(charname) = 1;
-- Si on supprime le personnage d'une de ces lignes, toutes les autres données de cette ligne sont supprimées.

-- Anomalie de mise à jour
SELECT compname, COUNT(DISTINCT gametitle) AS game_count
FROM table_globale
GROUP BY compname
HAVING COUNT(DISTINCT gametitle) > 1;
-- SI on modifie le nom de l'entreprise sur une des lignes, on doit le changer pour toutes les autres lignes.

-- Q2 - Proposer une décomposition qui corrige ces anomalies.
-- games(gameId, gameTitle, gameRelease);
-- companies(compId, compName);
-- characters(charId, charName);
-- game_characters(gameId, charId);
-- game_companies(gameId, compId);

-- EXERCICE 2

-- Q1 - Créer les différentes tables au sein du SGBD selon les deux modèles précédents.
drop table if exists games cascade;
create table if not exists games (
  gameId int primary key,
  gameTitle varchar(70),
  gameRelease date
);

drop table if exists companies cascade;
create table if not exists companies (
  compId serial primary key,
  compName varchar(70)
);

drop table if exists characters cascade;
create table if not exists characters (
  charId serial primary key,
  charName varchar(40)
);

create table if not exists game_characters (
  gameId int,
  charId int,
  primary key (gameId, charId),
  foreign key (gameId) references games(gameId) on delete cascade,
  foreign key (charId) references characters(charId) on delete cascade
);

create table if not exists game_companies (
  gameId int,
  compId int,
  primary key (gameId, compId),
  foreign key (gameId) references games(gameId) on delete cascade,
  foreign key (compId) references companies(compId) on delete cascade
);

-- Insertions

insert into games (gameId, gameTitle, gameRelease)
select distinct gameid, gametitle, gamerelease
from table_globale;

insert into companies (compName)
select distinct compname
from table_globale;

insert into characters (charName)
select distinct charname
from table_globale;

insert into game_characters (gameId, charId)
select distinct g.gameid, c.charid
from table_globale t
join games g on t.gameTitle = g.gameTitle and t.gameRelease = g.gameRelease
join characters c on t.charName = c.charName;

insert into game_companies (gameId, compId)
select distinct g.gameId, co.compId
from table_globale t
join games g on t.gameTitle = g.gameTitle and t.gameRelease = g.gameRelease
join companies co on t.compName = co.compName;

-- Q2 - Calculer la taille de la base selon le modèle choisi en nombre de n-uplets.
SELECT COUNT(*) AS games_count FROM games; -- 611
SELECT COUNT(*) AS companies_count FROM companies; -- 424
SELECT COUNT(*) AS characters_count FROM characters; -- 6604
SELECT COUNT(*) AS game_characters_count FROM game_characters; -- 12738
SELECT COUNT(*) AS game_companies_count FROM game_companies; -- 1113
-- Total = 21490

SELECT COUNT(*) AS table_globale_count FROM table_globale;
-- Total = 24209

-- Q3 - Calculer la taille de la base selon le mod`ele choisi en octets.
SELECT pg_size_pretty(pg_table_size('games')) AS games_size; -- 64kb
SELECT pg_size_pretty(pg_table_size('companies')) AS companies_size; -- 48kb
SELECT pg_size_pretty(pg_table_size('characters')) AS characters_size; -- 328kb
SELECT pg_size_pretty(pg_table_size('game_characters')) AS game_characters_size; -- 488kb
SELECT pg_size_pretty(pg_table_size('game_companies')) AS game_companies_size; -- 72kb
-- Total = 1000 Ko = 1 MO

SELECT pg_size_pretty(pg_table_size('table_globale')) AS table_globale_size;
-- Total = 11 MO
