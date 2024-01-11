const express = require('express');
const bodyParser = require('body-parser');
const app = express();


// console.log(db.cursos[0]);
app.use(bodyParser.json());
app.listen(3001,() => console.log("Servidor rodando na porta 3001"));

const db = require('./database'); //importação do banco de dados

//curso
app.get("/curso", (req, res) => {
    res.send(db);
    });
    
app.post("/curso", (req, res) =>{
    db.cursos.push(req.body);
    res.send(db);
});

app.put("/curso", (req, res) => {
        db.cursos.forEach(cursos => {
            if(cursos.id == req.body.id){
                cursos.id = (req.body.id) ? req.body.id : cursos.id;
                cursos.turno = (req.body.turno) ? req.body.turno : cursos.turno;
                cursos.nome = (req.body.nome) ? req.body.nome : cursos.nome;
                cursos.id_campus = (req.body.id_campus) ? req.body.id_campus : cursos.id_campus; 
            }
        })
        res.send(db);
        });


// db.cursos.splice(0, 1) remove um elemento a partir do índice 0
app.delete("/curso", (req, res) => {

    for (let i=0;i < db.cursos.length;i++){
        if (db.cursos[i].id == req.body.id){
            db.cursos.splice(i,1);
            res.send(db);
        }
    res.send("Não encontrado")
    
    }
});


//ccr

app.get("/ccrs", (req, res) => {
    res.send(db);
    });
    
app.post("/ccrs", (req, res) =>{
    db.ccrs.push(req.body);
    res.send(db);
});

app.put("/ccrs", (req, res) => {
    db.ccrs.forEach(ccrs => {
        if(ccrs.id == req.body.id){
            ccrs.id = (req.body.id) ? req.body.id : ccrs.id;
            ccrs.nome = (req.body.nome) ? req.body.nome : ccrs.nome;
        }
    })
    res.send(db);
    });

// db.cursos.splice(0, 1) remove um elemento a partir do índice 0
app.delete("/ccrs", (req, res) => {

    for (let i=0;i < db.ccrs.length;i++){
        if (db.ccrs[i].id == req.body.id){
            db.ccrs.splice(i,1);
            res.send(db);
        }
    res.send("Não encontrado")
    
    }
});





// para inserir na lista, use push:
// db.cursos.push({ ... })


// para remover da lista, use splice passando o índice do elemento e a quantidade de
// elementos a serem removidos. Exemnplo para remover o primeiro elemento:

