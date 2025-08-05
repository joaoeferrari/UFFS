#include <stdio.h>

int main(){
    int altA = 150, altC = 110;
    int crA = 2, crC = 3; 
    int anos=0;

    while (altC<altA)
    {
        altA = altA + crA;
        altC = altC + crC;
        anos = anos + 1;
    }


    printf(" Serao necessarios %d anos para as alturas de Antonio e Carlos serem iguais", anos);
    // 40 anos

return 0;
}