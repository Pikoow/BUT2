DROP SCHEMA IF EXISTS td2;

CREATE SCHEMA td2;

SET SCHEMA 'td2';

CREATE TABLE enfant(
  nopers INTEGER,
  prenom VARCHAR(20),
  points INTEGER,
  classe VARCHAR(10)
);
