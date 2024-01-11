let n1 = parseInt(prompt('Digite um numero'))
let n2 = parseInt(prompt('Digite outro numero'))

function somaMultiplacado(){
    let soma =0
    for(let i=1; i<=n2;i++){
        soma+=n1
    }
    return soma
}

console.log(somaMultiplacado(n1,n2))