#include <stdlib.h>
#include <stdio.h>
#include "questao01.h"

void entrada(int *num1, int *num2, int *num3){
    printf("Digite o primerio numero: ");
    scanf("%d",num1);
    printf("Digite o segundo numero: ");
    scanf("%d",num2);
    printf("Digite o terceiro numero: ");
    scanf("%d",num3);
}

void processamento(int *num1, int *num2, int *num3, int *saida){
    *saida = *num1 + *num2 + *num3;
}

void saida(int saida){
    printf("Resultado: %d", saida);
}

void questao01(void){
    int num1;
    int num2;
    int num3;
    int resultado;

    entrada(&num1,&num2,&num3);
    processamento(&num1,&num2,&num3,&resultado);
    saida(resultado);
}
