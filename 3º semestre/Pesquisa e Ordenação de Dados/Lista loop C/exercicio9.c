#include <stdio.h>

int main(){
    char time, time1, time2, A,B,C,D;
    int gol1, gol2, pontuacao1=0, pontuacao2=0 ;


    while (1)
    {
        if (time != A|B|C|D){
            break;
        } 

    printf("Time: \n");
    scanf("%c", &time1);

    printf("Gols: \n");
    scanf("%d", &gol1);

    printf("Time: \n");
    scanf("%c", &time2);

    printf("Gols: \n");
    scanf("%d", &gol2);


    if (gol1>gol2){
        pontuacao1 = pontuacao1 + 3;
    }else if (gol1 == gol2){
        pontuacao1 = pontuacao1 + 1;
        pontuacao2 = pontuacao2 + 1;
    }else if (gol2>gol1)
    {
        pontuacao2 = pontuacao2 + 3;
    }
    
    }

    printf("Campeao: %c", )
    return 0;
    }
    
    


