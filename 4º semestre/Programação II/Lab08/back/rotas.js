const express = require("express");
const bodyParser = require('body-parser');
const horarioA = require("./arrayHorarios")
const cursosA = require("./arrayCursos")
const cors = require("cors");
const app = express();

const pgp = require("pg-promise")({});
const usuario = "postgres";
const senha = "joao2004";
const db = pgp(`postgres://${usuario}:${senha}@localhost:5433/lab08`);


app.use(cors());
app.use(bodyParser.json());

app.listen(3002, () => console.log("Servidor rodando na porta 3002"));


app.get("/cursosA",(req, res) => {
    res.json(cursosA);
});

app.get("/cursos", async (req, res) => {
    try {
       // res.json(cursosA);
        const cursos = await db.any("SELECT * FROM cursos;");
        console.log('Retornando todos cursos.');
        res.json(cursos).status(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
    
});
app.get("/curso", async (req, res) => {
    try {
        const cursoId = parseInt(req.query.id);
        console.log(`Retornando ID: ${cursoId}.`);
        const cursos = await db.one(
            "SELECT id, nome, descr FROM cursos WHERE id = $1;",
            cursoId
        );
        res.json(cursos).status(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
});


app.get("/horarios",(req, res) => {
    res.json(horarioA);
    // try {
       
    //     const horarios = await db.any("SELECT * FROM horarios;");
    //     console.log('Retornando todos horarios.');
    //     res.json(horarios).status(200);
    // } catch (error) {
    //     console.log(error);
    //     res.sendStatus(400);
    // }
});

app.post("/curso", async (req, res) => {
    try {
        const cursoNome = req.body.nome;
        const cursoDescr = req.body.descr;
        console.log(`Nome: ${cursoNome} - Descr: ${cursoDescr}`);
        db.none(
            "INSERT INTO cursos (nome, descr) VALUES ($1, $2);",
            [cursoNome, cursoDescr]
        );
        res.sendStatus(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
});


app.post('/follow', (req, res) => {
    console.log('Recebi um follow');
 });
  
app.post('/unfollow', (req, res) => {
    console.log('Recebi unfollow');
  });