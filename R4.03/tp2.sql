create schema if not exists tp2;
set schema 'tp2';

-- EXERCICE 1

-- Ecrire le script SQL permettant de créer la table test df.
drop table if exists test_df cascade;
create table test_df(
    A VARCHAR(2),
    B VARCHAR(2),
    C VARCHAR(2),
    D VARCHAR(2),
    primary key (A)
);

insert into test_df(A, B, C, D)
values
    ('a1', 'b1', 'c1', 'd1'),
    ('a2', 'b1', 'c2', 'd2'),
    ('a3', 'b2', 'c1', 'd3'),
    ('a4', 'b2', 'c1', 'd3'),
    ('a5', 'b2', 'c2', 'd4');
    
SELECT * FROM test_df;

-- Ecrire la requête permettant pour chaque valeur de C de compter le nombre de valeurs de D.
SELECT C, COUNT(D) 
FROM test_df
GROUP BY C;

-- Ecrire une requête SQL permettant de vérifier que A → B. Un indice, il ne peut y avoir plus d'une valeur différente de B par valeur de A.
SELECT A
FROM test_df
GROUP BY A
HAVING COUNT(DISTINCT B) > 1;

-- Ecrire le script SQL permettant de créer la table test_df2.
drop table if exists test_df2 cascade;
create table test_df2(
    A VARCHAR(2),
    B VARCHAR(2),
    C VARCHAR(2),
    D VARCHAR(2),
    primary key (A)
);

insert into test_df2(A, B, C, D)
values
    ('a1', 'b1', 'c1', 'd1'),
    ('a2', 'b1', 'c2', 'd2'),
    ('a3', 'b2', 'c1', 'd3'),
    ('a4', 'b2', 'c1', 'd5'),
    ('a5', 'b2', 'c2', 'd4');
    
SELECT * FROM test_df2;

-- Ecrire une requête permettant de lister les violations de la dépendance fonctionnelle B, C → D.
SELECT t1.*
FROM test_df2 t1
JOIN test_df2 t2
    ON t1.B = t2.B AND t1.C = t2.C
WHERE t1.D != t2.D AND t1.A != t2.A;

-- Ecrire une requête permettant de compter le nombre d'enregistrements concernés par la violation de la dépendance fonctionnelle B, C → D est violée.
SELECT COUNT(*)
FROM test_df2 t1
JOIN test_df2 t2
    ON t1.B = t2.B AND t1.C = t2.C
WHERE t1.D != t2.D AND t1.A != t2.A;

-- EXERCICE 2

drop table if exists pokemon cascade;
create table pokemon(
    NumPokémon INT,
    Nom        VARCHAR(50),
    Type       VARCHAR(20),
    Niveau     INT,
    Attaque    VARCHAR(50),
    PV         INT,
    Dresseur   VARCHAR(50),
    primary key (NumPokémon)
);

insert into pokemon(NumPokémon, Nom, Type, Niveau, Attaque, PV, Dresseur)
values
    ('001', 'Bulbasaur', 'Grass', 10, 'Tackle', 45, 'Ash Ketchum'),
    ('002', 'Charmander', 'Fire', 8, 'Ember', 39, 'Gary Oak'),
    ('003', 'Squirtle', 'Water', 9, 'Water Gun', 44, 'Misty');
    
SELECT * FROM pokemon;

-- 1. Identifier des dépendances fonctionnelles dans la relation "Pokémon".
-- NumPokémon -> Nom
-- NumPokémon -> Type
-- NumPokémon -> Niveau
-- NumPokémon -> Attaque
-- NumPokémon -> PV
-- NumPokémon -> Dresseur

-- 2. Montrer à l'aide de plusieurs requêtes SQL que NumPokemon est une clé.
-- NumPokémon est unique
SELECT NumPokémon, COUNT(*)
FROM pokemon
GROUP BY NumPokémon
HAVING COUNT(*) > 1;

-- NumPokémon est non nul
SELECT *
FROM pokemon
WHERE NumPokémon IS NULL;

-- 3. Proposer une décomposition en plusieurs relations supprimant les anomalies de conception.
-- NumPokémon -> (Nom, Niveau, Dresseur)
drop table if exists PokemonBase cascade;
create table PokemonBase (
    NumPokémon INT PRIMARY KEY,
    Nom        VARCHAR(50) NOT NULL,
    Niveau     INT NOT NULL,
    Dresseur   VARCHAR(50)
);

-- Nom -> (Type, Attaque)
drop table if exists PokemonTypeAttaque cascade;
create table PokemonTypeAttaque (
    Nom     VARCHAR(50) PRIMARY KEY,
    Type    VARCHAR(20) NOT NULL,
    Attaque VARCHAR(50) NOT NULL
);

-- Nom, Niveau -> (PV)
drop table if exists PokemonNiveauPV cascade;
create table PokemonNiveauPV (
    Nom     VARCHAR(50),
    Niveau  INT,
    PV      INT NOT NULL,
    PRIMARY KEY (Nom, Niveau),
    FOREIGN KEY (Nom) REFERENCES PokemonTypeAttaque(Nom)
);

-- EXERCICE 3

-- Lister les dépendances fonctionnelles et en déduire une décomposition BCNF.
-- Name -> Type
-- Name -> Level
-- Name -> Move
-- Name -> Power
-- Name -> Trainer
-- Name -> Location

drop table if exists Pokemon3 cascade;
create table Pokemon3 (
    Name     VARCHAR(50) PRIMARY KEY,
    Type     VARCHAR(20),
    Level    INT,
    Move     VARCHAR(50),
    Trainer  VARCHAR(50),
    Location VARCHAR(50)
);

drop table if exists Move_Power cascade;
create table Move_Power (
    Name  VARCHAR(50),
    Move  VARCHAR(50),
    Power INT,
    PRIMARY KEY (Name, Move),
    FOREIGN KEY (Name) REFERENCES Pokemon3(Name)
);
