-- DROP TABLE cursos;


CREATE TABLE cursos
(
    id SERIAL PRIMARY KEY,
    nome VARCHAR,
    descr VARCHAR
);
INSERT INTO cursos (nome, descr) VALUES ('Ciencia da Computacao','Atraves de bases solidas da area de computacao, formar cientistas capazes de terem um papel importante em areas da tecnologia da informacao (TI), tanto na indústria quanto na academia.');
INSERT INTO cursos (nome, descr) VALUES ('Medicina', 'Tem como pressupostos basicos o direito universal a saude, a atencao integral, equitativa e de qualidade, contribuindo no fortalecimento da participacao e autonomia dos sujeitos na producao da sua propria saude individual e coletiva.');

-- SELECT * FROM cursos;