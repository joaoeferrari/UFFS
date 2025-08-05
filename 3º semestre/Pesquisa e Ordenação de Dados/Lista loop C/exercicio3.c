#include <stdio.h>

int main()
{
    int n, acumulador;
    printf("INFORME UM VALOR:\n");
    scanf("%d",&n);

    acumulador = 0;
    for (int i=1; i<=n;i++){
        acumulador = acumulador + i;
    }
    printf("%d",acumulador);
}

//Complexidade N