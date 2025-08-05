#include <stdio.h>

int main(){
    int n=1, contador = 0, acumulador=0;
    float p;
    while (1){
        if (n<=0){
            break;
        }
    printf("Digite um numero:\n");
    scanf("%d", &n);
    acumulador = acumulador + 1;
        if (n>=10 || n<=20){
            contador = contador + 1;
        }
    }
    printf("%d", acumulador);
    p = (contador*100)/acumulador;

    printf("%f por cento", p/100);

return 0;
}