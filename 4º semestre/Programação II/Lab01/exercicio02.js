let preço = parseFloat(prompt('Informe o preço do produto'))
let opcao = parseInt(prompt('Digite 1 para a vista e 2 para a prazo'))

const vendaComArrowReturn = (preço, opcao) =>{
    if (opcao == 1){
        let precoFinal = preço - ((5/100)*preço)
        return precoFinal
        
    } else{
        let precoFinal = preço + ((10/100)*preço)
        return precoFinal
    }
    
}

console.log(vendaComArrowReturn(preço, opcao))