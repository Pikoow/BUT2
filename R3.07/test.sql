DROP SCHEMA IF EXISTS test CASCADE;

CREATE SCHEMA test;

CREATE TABLE test._user (
    nickname VARCHAR(30) CONSTRAINT _user_pk PRIMARY KEY,
    pass VARCHAR(20) NOT NULL,
    email VARCHAR(40) NOT NULL
);

CREATE TABLE test._document (
    iddoc SERIAL CONSTRAINT _document_pk PRIMARY KEY,
    content VARCHAR(128) NOT NULL,
    create_date TIMESTAMP NOT NULL DEFAULT now(),
    author VARCHAR(30) NOT NULL
    CONSTRAINT _document_fk_author
      FOREIGN KEY (author) REFERENCES test._user(nickname)
);

CREATE TABLE test._post (
    iddoc INTEGER,
    CONSTRAINT _post_pk PRIMARY KEY (iddoc),
    CONSTRAINT _post_fk_inherit
      FOREIGN KEY (iddoc) REFERENCES test._document(iddoc)
);

CREATE TABLE test._comment (
    iddoc INTEGER,
    ref INTEGER NOT NULL,
    CONSTRAINT _comment_pk PRIMARY KEY (iddoc),
    CONSTRAINT _comment_fk_inherit
      FOREIGN KEY (iddoc) REFERENCES test._document(iddoc),
    CONSTRAINT _comment_fk_ref
      FOREIGN KEY (ref) REFERENCES test._document(iddoc),  
    CONSTRAINT _comment_ck_iddoc_ref
      CHECK (iddoc <> ref)
);

INSERT INTO test._document(iddoc, content, author) VALUES (1, "Je suis Alex", "Alex");
INSERT INTO test._post(iddoc) VALUES (1);

INSERT INTO test._document(iddoc, content, author) VALUES (2, "Je suis Bob", "Bob");
INSERT INTO test._post(iddoc) VALUES (2);

INSERT INTO test._document(iddoc, content, author) VALUES (1, "Commentaire 1", "Alex");
INSERT INTO test._comment(iddoc, ref) VALUES (3, 1);

INSERT INTO test._document(iddoc, content, author) VALUES (1, "Commentaire 1", "Bob");
INSERT INTO test._comment(iddoc, ref) VALUES (4, 3);

INSERT INTO test._document(iddoc, content, author) VALUES (1, "Commentaire 1", "Dog");
INSERT INTO test._comment(iddoc, ref) VALUES (5, 1);

SELECT setval('test._document_iddoc_seq', 14);

DROP SEQUENCE IF EXISTS test._document_iddoc_seq;

CREATE SEQUENCE IF NOT EXISTS _document_iddoc_seq
  AS integer
  INCREMENT BY 1
  MINVALUE 1
  MAXVALUE 2147483647
  CACHE 1
  NO CYCLE
  OWNED BY test._document.iddoc;

