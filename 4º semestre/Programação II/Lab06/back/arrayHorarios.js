function createData(horario, ccr1, ccr2, ccr3, ccr4, ccr5) {
    return {horario, ccr1, ccr2, ccr3, ccr4, ccr5};
  }
  
  const horarios = [
    createData('07:00', 'Matemática C','Estatística Básica', 'Algoritmos', 'Filosofia', 'Informática Básica'),
    createData('08:00', 'Matemática C','Estatística Básica', 'Algoritmos', 'Filosofia', 'Informática Básica'),
    createData('09:00', 'Matemática C','Estatística Básica', 'Algoritmos', 'Filosofia', 'Informática Básica'),
    createData('10:00', 'Matemática C','Estatística Básica', 'Algoritmos', 'Filosofia', 'Informática Básica'),
    createData('11:00', 'Matemática C','Estatística Básica', 'Algoritmos', 'Filosofia', 'Informática Básica'),
    createData('12:00', 'Matemática C','Estatística Básica', 'Algoritmos', 'Filosofia', 'Informática Básica')
  ]

  module.exports = horarios;