//fatorial

#include <stdio.h>


int main()
{
    int f, resultado = 1;

    printf("Digite um numero para descobrir seu fatorial:\n");
    scanf("%d", &f);

    if (f == 0){
        printf("O fatorial de 0 e igual a %d",resultado);
    }else{
    for(int i=1; i<=f;i++){
        resultado = resultado * i;
    }
    printf("O fatorial de %d e igual a %d", f, resultado);
}
return 0;   
}