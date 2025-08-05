
/**
 * @file externaOrdenacao.c
 * @author João Eduardo Pelegrini Ferrari
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 02 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma ordenação externa utilizando a restrição de que somente 5
 *  elementos podem ser armazenados em memória (vetores de teste no template). A
 *  definição deste limite está na variável MAX_IN_MEMORY abaixo.
 *
 *      Utilize os vetores comentados no código para realizar seus testes.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */

/*Instrucoes adicionais
Compilar o arquivo usando -lm como parametro para importar as bibliotecas math.h*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IN_MEMORY 5

#if defined(_WIN32)
#define PLATFORM "windows"
#elif defined(__unix__)
#define PLATFORM "linux"
#endif

void sort(int *arr);
int menor(int *arr);
int numeroHas(int *arr);

int main()
{
    int vet[] = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    int vetLen = sizeof(vet) / sizeof(int);

    FILE *inputArquivos[MAX_IN_MEMORY];
    FILE *outputFiles[MAX_IN_MEMORY];

    
    for (int i = 0; i < MAX_IN_MEMORY; i++)
    {
        char inputDiretorio[30];
        char outputDiretorio[30];

        if (strcmp(PLATFORM, "windows") == 0)
        {
            sprintf(inputDiretorio, ".\\bin\\inputs\\input%d.txt", i);
            sprintf(outputDiretorio, ".\\bin\\outputs\\output%d.txt", i);
        }
        else
        {
            sprintf(inputDiretorio, "./bin/inputs/input%d.txt", i);
            sprintf(outputDiretorio, "./bin/outputs/output%d.txt", i);
        }

        inputArquivos[i] = fopen(inputDiretorio, "w+");
        outputFiles[i] = fopen(outputDiretorio, "w+");
    }

    
    int vetIndex = 0;

    while (vetIndex < vetLen)
    {
        
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            int arr[MAX_IN_MEMORY] = {0};
            int arrActualLen = 0;
            for (int j = 0; j < MAX_IN_MEMORY; j++)
            {
                if (vetIndex < vetLen)
                {
                    arr[j] = vet[(vetIndex)++];
                    arrActualLen++;
                }
                else
                    arr[j] = __INT32_MAX__;
            }

            
            sort(arr);

            
            for (int j = 0; j < arrActualLen; j++)
            {
                if (arr[j] == __INT32_MAX__)
                    break;

                if (j == arrActualLen - 1)
                {
                    fprintf(inputArquivos[i], ",%d, ", arr[j]);
                    continue;
                }
                else
                    fprintf(inputArquivos[i], ",%d", arr[j]);
            }
        }
    }

    
    int contagemOutput = ((int)ceil(sqrt(vetLen)) % 5) + 1;

    for (int k = 0; k < contagemOutput; k++)
    {
        int arr[MAX_IN_MEMORY];
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            if (k == 0)
                fseek(inputArquivos[i], 1, SEEK_SET);

            fscanf(inputArquivos[i], "%d,", &arr[i]);
        }
        while (numeroHas(arr) == 1)
        {
            int menorIndex = menor(arr);
            fprintf(outputFiles[k], ",%d", arr[menorIndex]);
            int n;
            arr[menorIndex] = (fscanf(inputArquivos[menorIndex], "%d,", &n) == 1) ? n : __INT32_MAX__;
        }

        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            fseek(inputArquivos[i], 1, SEEK_CUR);
        }
    }

    for (int i = 0; i < contagemOutput; i++)
    {
        fprintf(outputFiles[i], ",");
    }

    contagemOutput--;

    for (int i = 0; i < MAX_IN_MEMORY; i++)
    {
        voltar(inputArquivos[i]);
        voltar(outputFiles[i]);
    }

    for (int k = 0; k < contagemOutput; k++)
    {
        int arr[MAX_IN_MEMORY];
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            arr[i] = __INT32_MAX__;
        }
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            fseek(outputFiles[i], 1, SEEK_SET);
            fscanf(outputFiles[i], "%d,", &arr[i]);
        }
        while (numeroHas(arr) == 1)
        {
            int menorIndex = menor(arr);
            fprintf(inputArquivos[k], ",%d", arr[menorIndex]);
            int n;
            arr[menorIndex] = (fscanf(outputFiles[menorIndex], "%d,", &n) == 1) ? n : __INT32_MAX__;
        }

        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            fseek(outputFiles[i], 1, SEEK_CUR);
        }
    }

    for (int i = 0; i < contagemOutput; i++)
    {
        fprintf(inputArquivos[i], ",");
    }

    
    int farr[vetLen];
    int farrActualLen = 0;

    fseek(inputArquivos[0], 1, SEEK_SET);

    while(farrActualLen < vetLen)
    {
        fscanf(inputArquivos[0], "%d,", &farr[farrActualLen++]);
    }

    printf("ARRAY INICIAL:\n");
    for(int i = 0; i < vetLen; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\nSORTED ARRAY:\n");
    for(int i = 0; i < vetLen; i++)
    {
        printf("%d ", farr[i]);
    }
    printf("\n");

    return 0;
}

void sort(int *arr)
{
    int menor;
    for (int i = 0; i < MAX_IN_MEMORY - 1; i++)
    {
        menor = i;
        for (int j = i + 1; j < MAX_IN_MEMORY; j++)
        {
            if (arr[menor] > arr[j])
                menor = j;
        }
        int c = arr[i];
        arr[i] = arr[menor];
        arr[menor] = c;
    }
}

int menor(int *arr)
{
    int menor = 0;
    for (int i = 1; i < MAX_IN_MEMORY; i++)
    {
        if (arr[i] < arr[menor])
            menor = i;
    }

    return menor;
}

int numeroHas(int *arr)
{
    int flag = 0;
    for (int i = 0; i < MAX_IN_MEMORY; i++)
    {
        if (arr[i] != __INT32_MAX__)
            return 1;
    }
    return flag;
}