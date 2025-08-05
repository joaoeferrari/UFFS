#include <stdio.h>

int main()
{
    int n;                              
    printf("DIGITE UM NUMERO:\n");
    scanf("%d", &n);

    for(int i=1; i<n+1; i++){ 
        printf("%d ", i);
        if (i==(n/2)){
            printf("METADE ");
        }
    }
    return 0;
}

//complexidade N
