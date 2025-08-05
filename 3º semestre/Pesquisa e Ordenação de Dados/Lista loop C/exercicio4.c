#include <stdio.h>

int main(){
    
    int a,b,resultado;
    char comando = 'x';
    
    while (1){
    
    if (comando == '@'){
        break;
    }

    printf("Digite 'x'para multiplicacao\nDigite '/' para divisao\nDigite '+' para adicao\nDigite '-' para subtracao\nDigite '@' para encerrar\n");
    scanf("%c", &comando);

    printf("DIGITE UM NUMERO: \n");
    scanf("%d",&a);

    printf("DIGITE UM NUMERO: \n");
    scanf("%d",&b);

    if (comando == '+'){
        resultado = a + b;
        printf("%d\n", resultado);
    }
    else if(comando == 'x'){
        resultado = a * b;
        printf("%d\n", resultado);
    }
    else if(comando == '/'){
        resultado = a/b;
        printf("%d\n", resultado);
    }
    else if (comando == '-'){
        resultado = a - b;
        printf("%d\n", resultado);
    }
    
   // codigo certo problema no c

}
return 0;
}