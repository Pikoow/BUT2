DROP SCHEMA IF EXISTS bob CASCADE;

CREATE SCHEMA bob;

SET SCHEMA 'bob';

CREATE TABLE _ligne_eau(
  no_ligne INT CONSTRAINT NO_LIGNE_PK PRIMARY KEY
);

CREATE TABLE _epreuve(
  num_epreuve INT CONSTRAINT EPREUVE_PK PRIMARY KEY,
  heure_epr TIME
);

CREATE TABLE _competiteur(
  id_competiteur INT CONSTRAINT COMPETITEUR_PK PRIMARY KEY
);

CREATE TABLE _competition(
  num_compet INT CONSTRAINT COMPETITION_PK PRIMARY KEY,
  date_compet DATE
);

CREATE TABLE _participe(
  num_compet INT,
  no_ligne INT not null,
  id_competiteur INT,
  num_epreuve INT,
  constraint _participe_pk primary key (num_compet, num_epreuve, id_competiteur),
  constraint _participe_ak unique (num_compet, num_epreuve, no_ligne),
  constraint _participe_fk_competiteur
    foreign key (num_compet, id_competiteur) references _competiteur(num_compet, id_competiteur),
  constraint _participe_fk_epreuve
    foreign key (num_compet, num_epreuve) references _epreuve(num_compet, num_epreuve),
  constraint _participe_fk_ligne
    foreign key (no_ligne) references _ligne_eau(no_ligne)
);

CREATE TABLE _gagne(
  num_compet INT,
  num_epreuve INT,
  id_competiteur INT not null,
  chrono time not null,
  constraint _gagne_pk primary key (num_compet, num_epreuve),
  constraint _gagne_fk_participe
    foreign key (num_compet, num_epreuve, id_competiteur) references _participe
);
