#include <stdio.h>

int main()
{
    int n1,n2, soma;

    printf("DIGITE UM NUMERO: \n");
    scanf("%d", &n1);

    printf("DIGITE OUTRO NUMERO: \n");
    scanf("%d", &n2);

    soma = n1;
    for(int i=1; i<n2; i++){
        soma = soma + n1;
    }
printf("%d",soma);
    
return 0;
}
//complexidade N