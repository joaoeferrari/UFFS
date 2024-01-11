const express = require("express");
const bodyParser = require('body-parser');
const horario = require("./arrayHorarios")
const cursos = require("./arrayCursos")

const cors = require("cors");

const app = express();

app.use(cors());
app.use(bodyParser.json());

app.listen(3002, () => console.log("Servidor rodando na porta 3002"));

app.get("/cursos", (req, res) => {
    res.json(cursos);
});


app.get("/horarios", (req, res) => {
    res.json(horario);
});

app.post('/follow', (req, res) => {
    console.log('Recebi um follow');
 });
  
app.post('/unfollow', (req, res) => {
    console.log('Recebi unfollow');
  });