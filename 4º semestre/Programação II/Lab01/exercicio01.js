let horasTrabalhadas = parseInt(window.prompt('Informe o número de horas trabalhadas: '))
let valorHora = parseFloat(window.prompt('Informe o valor da hora trabalhada'))
let res = document.querySelector('section#res')

function salario(horasTrabalhadas, valorHora){
    return valorHora * horasTrabalhadas
}

let sal = salario(horasTrabalhadas, valorHora)

if (horasTrabalhadas > 200){
    sal += (5/100)*sal
    res.innerHTML = `O salário será ${sal} (contém aumento de 5%)`
}else{
    res.innerHTML = `O salário será ${sal}`
}

console.log(sal)