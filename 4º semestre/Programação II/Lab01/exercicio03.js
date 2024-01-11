let horaInicio = parseInt(prompt('Informe a hora de inicio: '))
let horaFinal = parseInt(prompt('Informe a hora do termino: '))

function calcula(){
    let duracao = horaFinal - horaInicio
    if(horaFinal < horaInicio){
        duracao = 24+ horaFinal-horaInicio
        return duracao
    }else{
        return duracao
    }
    
}

console.log(calcula(horaInicio,horaFinal))