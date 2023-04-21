#include <stdlib.h>
#include <stdio.h>
#include "questao05.h"

void entrada05(float *salarioBase, int *qtdDependentes){
    printf("Digite seu salario base: ");
    scanf("%f", salarioBase);
    printf("Digite numero de dependentes: ");
    scanf("%d", qtdDependentes);
}

void processamento05(float *salarioBase, int *qtdDependentes, float *saida){
        *saida  = *salarioBase+(*qtdDependentes*32,0);
        *saida = *saida-((*saida*27,5)/100);
}

void saida05(float saida){
    printf("Salario Liquido: %f", saida);
}

void questao05(void){
    float salarioBase;
    int qtdDependentes;
    float resultado;

    entrada(&salarioBase,&qtdDependentes);
    processamento(&salarioBase, &qtdDependentes, &resultado);
    saida(resultado);
}
