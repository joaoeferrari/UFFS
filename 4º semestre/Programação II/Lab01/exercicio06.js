
let quant =0
let numerosEsc = 0
while (true){
    let numero = parseInt(prompt('Digite um numero, 0 encerra'))
    if (numero === 0){
        console.log((numerosEsc/quant)*100 + '%')
        break
    }
    quant++
    if (numero >= 10 && numero<=20){
        numerosEsc++
    }              
}



