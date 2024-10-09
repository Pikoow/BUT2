SET SCHEMA 'td2';

START TRANSACTION ;

SELECT points FROM enfant WHERE nopers = 1 FOR UPDATE ;

UPDATE enfant SET points = points + 8 WHERE nopers = 1 ;

COMMIT ;
