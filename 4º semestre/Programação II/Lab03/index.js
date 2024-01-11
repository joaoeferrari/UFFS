const express = require('express');
const bodyParser = require('body-parser');
const app = express();



app.use(bodyParser.json());
app.listen(3001,() => console.log("Servidor rodando na porta 3001"));

app.use(express.static(`${__dirname}/public`))
app.get("/horarios", (req, res) => {
    res.sendFile(`${__dirname}/public/index.html`)
   
    });

/*
app.post("/horarios", (req, res) =>{
    db.ccrs.push(req.body);
    res.send(db);
});


app.put("/horarios", (req, res) => {
    db.ccrs.forEach(ccrs => {
        if(ccrs.id == req.body.id){
            ccrs.id = (req.body.id) ? req.body.id : ccrs.id;
            ccrs.nome = (req.body.nome) ? req.body.nome : ccrs.nome;
        }
    })
    res.send(db);
    });


app.delete("/horarios", (req, res) => {

    for (let i=0;i < db.ccrs.length;i++){
        if (db.ccrs[i].id == req.body.id){
            db.ccrs.splice(i,1);
            res.send(db);
        }
    res.send("Não encontrado")
    
    }
});

*/



