let valor = parseInt(prompt('Informe um valor'))

const somaComArrowReturn = (valor) =>{
    valorFinal = 0
    for(let i=1; i<=valor; i++){
        valorFinal += i 
    }
    
    return valorFinal
}

console.log(somaComArrowReturn(valor))