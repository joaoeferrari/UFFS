#include <stdio.h>

int main(){

    int matricula, contadorNotas = 0, alunos=0;
    float nota, notaFinal=0, mediaAluno, mediaTurma;

    printf("Informe sua matricula:\n");
    scanf("%d", &matricula);
    while (1){
        if (matricula == 0){
            break;
        }
    for (int i = 1; i<11; i++){
        printf("Nota %d:\n", i);
        scanf("%f", &nota);
        notaFinal = notaFinal + nota;
        contadorNotas = contadorNotas + 1;
        
    }
    mediaAluno = notaFinal/contadorNotas;
    alunos = alunos + 1;
    printf("Matricula: %d , media: %f\n", matricula, mediaAluno);

    

    printf("Informe sua matricula:\n");
    scanf("%d", &matricula);
    }

    mediaTurma = mediaAluno/alunos;
    printf("Media geral da turma: %f", mediaTurma);

return 0;
}