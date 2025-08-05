#include <stdio.h>

int main()
{
    float salario,somaS=0, mediaS,contS=0,somaF=0, mediaF, contF=0;
    int filho;
    

    while (1)
    {
       
    printf("Informe o seu salario: \n");
    scanf("%f", &salario);
     
    if (salario < 0){
            break;
        }

    printf("Informe quantos filhos voce tem: \n");
    scanf("%d", &filho);
    somaF = somaF + filho;
    contF = contF + 1;
    }
    mediaS = somaS/contS;
    mediaF = somaF/contF;

    printf("Media salarios: %f", mediaS);
    printf("Media filhos: %f", mediaF);
    
return 0;
}   