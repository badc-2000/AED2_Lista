#include <stdio.h>
#include <stdbool.h>

bool inputBubble(int *tamanhoVetor, int *vetor) {
    int valor, i;
    printf("Informe o tamanho do vetor (obs: nao pode ser maior que 50): ");
    scanf("%d", tamanhoVetor);
    if (*tamanhoVetor <= 2) {
        return false;
    }
    for (i = 0; i < *tamanhoVetor; i++) {
        printf("Informe o valor a ser inserido no vetor: ");
        scanf("%d", &valor);
        vetor[i] = valor;
    }
    return true;
}

void processamentoBubble(int *vetor, int tamanhoVetor) {
    int contador, aux, i;
    for (contador = 1; contador < tamanhoVetor; contador++) {
        for (i = 0; i < tamanhoVetor - 1; i++) {
            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

bool verificarSorteB(int *vetor, int tamanhoVetor) {
    int i;
    for (i = 0; i < tamanhoVetor - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return true;
        }
    }
    return false;
}

void outputBubble(int tamanhoVetor, int *vetor) {
    int i;
    printf("Vetor arrumado: ");
    for (i = 0; i < tamanhoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubbleSort(void) {
    int tamanhoVetor;
    int vetor[50] = {0};

    if (!inputBubble(&tamanhoVetor, vetor)) {
        printf("Vetor muito pequeno\n");
    } else {
        if (verificarSorteB(vetor, tamanhoVetor)) {
            processamentoBubble(vetor, tamanhoVetor);
        }
        outputBubble(tamanhoVetor, vetor);
    }
}
