let numFat = parseInt(prompt('Digite um numero : '))

function calcular(numFat){
    if (numFat ===0){
        return 1 
    }else{
        return numFat * calcular(numFat-1)
    }
}

console.log(`A resposta é ${calcular(numFat)}`)