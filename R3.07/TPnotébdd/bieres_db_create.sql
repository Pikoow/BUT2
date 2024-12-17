DROP SCHEMA IF EXISTS bieres CASCADE;

CREATE SCHEMA bieres;
SET SCHEMA 'bieres';

/* Creation des tables */
create table bieres._buveur
(
		idbuveur 	integer,
		nomb 		varchar(50) 	NOT NULL,
		prenomb 	varchar(50)		NOT NULL,
		constraint _buveur_pk primary key(idbuveur)
);

create table bieres._biere
(
		idbiere 	integer,
		nombiere 	varchar(50) 	NOT NULL,
		degre 		integer			NOT NULL,
		typebiere 	varchar(50)		NOT NULL,
		constraint _biere_pk primary key(idbiere)
);

create table bieres._bar
(
		idbar 		integer,
		nombar 		varchar(50)		NOT NULL,
		villebar 	varchar(50)		NOT NULL,
		constraint _bar_pk primary key(idbar)
);

create table bieres._frequenter
(
		idbuveur 	integer,
		idbar 		integer,
		constraint _freq_pk primary key(idbuveur, idbar),
		constraint _freq_fk_buveur foreign key(idbuveur) references bieres._buveur(idbuveur),
		constraint _freq_fk_bar foreign key(idbar) references bieres._bar(idbar)
);

create table bieres._aimer
(
		idbuveur 	integer,
		idbiere		integer,
		constraint _aime_pk primary key(idbuveur, idbiere),
		constraint _aime_fk_buveur foreign key(idbuveur) references bieres._buveur(idbuveur),
		constraint _aime_fk_biere foreign key(idbiere) references bieres._biere(idbiere)
);

create table bieres._servir
(
		idbar 		integer,
		idbiere 	integer,
		constraint _servir_pk primary key(idbiere, idbar),
		constraint _servir_fk_bar foreign key(idbar)  references bieres._bar(idbar),
		constraint _servir_fk_biere foreign key(idbiere) references bieres._biere(idbiere)
);

/* Remplissage des tables */
insert into bieres._buveur(idbuveur, nomb, prenomb) values(1,'Eastwood', 'Clint');
insert into bieres._buveur(idbuveur, nomb, prenomb) values(2, 'Abitbol', 'Georges');
insert into bieres._buveur(idbuveur, nomb, prenomb) values(3, 'DeNice', 'Brice');
insert into bieres._buveur(idbuveur, nomb, prenomb) values(4, 'Bricot', 'Juda');
insert into bieres._buveur(idbuveur, nomb, prenomb) values(5, 'Meurdesoif', 'Jean');
insert into bieres._buveur(idbuveur, nomb, prenomb) values(6, 'Kollyck', 'Al');

insert into bieres._biere(idbiere,nombiere,degre,typebiere) values(1, 'kronembourg', 4, 'pils');
insert into bieres._biere(idbiere,nombiere,degre,typebiere) values(2, 'pilsener', 3, 'pils');
insert into bieres._biere(idbiere,nombiere,degre,typebiere) values(3, 'heinecken', 4, 'pils');
insert into bieres._biere(idbiere,nombiere,degre,typebiere) values(4, 'leffe', 6, 'triple');
insert into bieres._biere(idbiere,nombiere,degre,typebiere) values(5, 'smirnoff', 4, 'arromatisee');
insert into bieres._biere(idbiere,nombiere,degre,typebiere) values(6, 'dremmwel', 6,' al');


insert into bieres._bar(idbar,nombar,villebar) values(2, 'Bar des sports', 'Lannion');
insert into bieres._bar(idbar,nombar,villebar) values(3, 'Chez momo', 'Morlaix');
insert into bieres._bar(idbar,nombar,villebar) values(4, 'Bar du bon coin', 'Morlaix');
insert into bieres._bar(idbar,nombar,villebar) values(1, 'Anti soif', 'Lannion');
insert into bieres._bar(idbar,nombar,villebar) values(6, 'Chti canon', 'Tregastel');
insert into bieres._bar(idbar,nombar,villebar) values(5, 'Bar Aine', 'Lannion');

insert into bieres._frequenter(idbuveur, idbar) values(1, 1); 
insert into bieres._frequenter(idbuveur, idbar) values(1, 2); 
insert into bieres._frequenter(idbuveur, idbar) values(1, 3);
insert into bieres._frequenter(idbuveur, idbar) values(1, 4);
insert into bieres._frequenter(idbuveur, idbar) values(1, 5); 
insert into bieres._frequenter(idbuveur, idbar) values(1, 6);   
insert into bieres._frequenter(idbuveur, idbar) values(2, 2); 
insert into bieres._frequenter(idbuveur, idbar) values(4, 1); 
insert into bieres._frequenter(idbuveur, idbar) values(4, 4); 
insert into bieres._frequenter(idbuveur, idbar) values(5, 1); 
insert into bieres._frequenter(idbuveur, idbar) values(5, 2); 
insert into bieres._frequenter(idbuveur, idbar) values(5, 3); 
insert into bieres._frequenter(idbuveur, idbar) values(5, 4); 
insert into bieres._frequenter(idbuveur, idbar) values(5, 5); 
insert into bieres._frequenter(idbuveur, idbar) values(6, 2);

insert into bieres._servir(idbar, idbiere) values(1, 1);
insert into bieres._servir(idbar, idbiere) values(1, 3);
insert into bieres._servir(idbar, idbiere) values(1, 4);
insert into bieres._servir(idbar, idbiere) values(2, 1);
insert into bieres._servir(idbar, idbiere) values(4, 3);
insert into bieres._servir(idbar, idbiere) values(5, 4);
insert into bieres._servir(idbar, idbiere) values(3, 1);
insert into bieres._servir(idbar, idbiere) values(3, 3);
insert into bieres._servir(idbar, idbiere) values(3, 5);
insert into bieres._servir(idbar, idbiere) values(5, 5);
insert into bieres._servir(idbar, idbiere) values(4, 5);
insert into bieres._servir(idbar, idbiere) values(6, 5);
insert into bieres._servir(idbar, idbiere) values(4, 1);
insert into bieres._servir(idbar, idbiere) values(4, 4);
insert into bieres._servir(idbar, idbiere) values(4, 6);


insert into bieres._aimer(idbuveur, idbiere) values(1, 2);
insert into bieres._aimer(idbuveur, idbiere) values(1, 3);
insert into bieres._aimer(idbuveur, idbiere) values(2, 3);
insert into bieres._aimer(idbuveur, idbiere) values(3, 1);
insert into bieres._aimer(idbuveur, idbiere) values(3, 2);
insert into bieres._aimer(idbuveur, idbiere) values(3, 3);
insert into bieres._aimer(idbuveur, idbiere) values(3, 4);
insert into bieres._aimer(idbuveur, idbiere) values(3, 5);
insert into bieres._aimer(idbuveur, idbiere) values(3, 6);
insert into bieres._aimer(idbuveur, idbiere) values(4, 1);
insert into bieres._aimer(idbuveur, idbiere) values(6, 1);
insert into bieres._aimer(idbuveur, idbiere) values(6, 3);
insert into bieres._aimer(idbuveur, idbiere) values(6, 5);


-- Heritage

create table bieres._buveur_amateur(
  idbuveur integer primary key references bieres._buveur
);

insert into bieres._buveur_amateur
  select idbuveur
  from bieres._buveur
  where idbuveur > 3; 

create table bieres._buveur_pro(
  idbuveur 		  integer primary key references bieres._buveur,
  idbarprefere    integer not null references bieres._bar
);

insert into bieres._buveur_pro
  select idbuveur, idbuveur -- oui le bar qui porte son numero de buveur
  from bieres._buveur
  where idbuveur <= 3;
