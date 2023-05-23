#include <stdio.h>
#include <stdlib.h>

int* mergeSort(int* vetor, int tamanhoVetor);
int* merge(int* vetorEsq, int* vetorDir, int tamanhoVetor1, int tamanhoVetor2);
int* sliceArray(int* vetor, int inicio, int fim);
void inputMerge(int* vetor, int* tamanhoVetor);
void outputMerge(int* vetor, int tamanhoVetor);
void MergeSortMain(void);

int* mergeSort(int* vetor, int tamanhoVetor) {
    if (tamanhoVetor <= 1) {
        return vetor;
    }

    int* vetorDir = sliceArray(vetor, tamanhoVetor / 2, tamanhoVetor - 1);
    int* vetorEsq = sliceArray(vetor, 0, tamanhoVetor / 2 - 1);

    vetorDir = mergeSort(vetorDir, tamanhoVetor / 2);
    vetorEsq = mergeSort(vetorEsq, tamanhoVetor - tamanhoVetor / 2);

    return merge(vetorEsq, vetorDir, tamanhoVetor / 2, tamanhoVetor - tamanhoVetor / 2);
}

int* sliceArray(int* vetor, int inicio, int fim) {
    int novoTamanho = fim - inicio + 1;
    int* novoVetor = (int*)malloc(novoTamanho * sizeof(int));

    for (int i = 0; i < novoTamanho; i++, inicio++) {
        novoVetor[i] = vetor[inicio];
    }

    return novoVetor;
}

int* merge(int* vetorEsq, int* vetorDir, int tamanhoVetor1, int tamanhoVetor2) {
    int novoTamanho = tamanhoVetor1 + tamanhoVetor2;
    int* merged = (int*)malloc(novoTamanho * sizeof(int));
    int indexDir = 0;
    int indexEsq = 0;
    int i = 0;

    while (indexEsq < tamanhoVetor1 && indexDir < tamanhoVetor2) {
        if (vetorEsq[indexEsq] <= vetorDir[indexDir]) {
            merged[i] = vetorEsq[indexEsq];
            indexEsq++;
        } else {
            merged[i] = vetorDir[indexDir];
            indexDir++;
        }
        i++;
    }

    while (indexEsq < tamanhoVetor1) {
        merged[i] = vetorEsq[indexEsq];
        indexEsq++;
        i++;
    }
    while (indexDir < tamanhoVetor2) {
        merged[i] = vetorDir[indexDir];
        indexDir++;
        i++;
    }

    return merged;
}

void inputMerge(int* vetor, int* tamanhoVetor) {
    int i, n = 0;
    printf("Por favor escolha o tamanho do vetor (não maior que 50): ");
    scanf("%d", tamanhoVetor);
    if (*tamanhoVetor <= 1) {
        printf("Tamanho Muito Pequeno");
    } else {
        for (i = 0; i < *tamanhoVetor; i++) {
            printf("Por favor digite o numero a ser colocado no vetor: ");
            scanf("%d", &n);
            vetor[i] = n;
            n = 0;
        }
    }
}

void outputMerge(int* vetor, int tamanhoVetor) {
    int i;
    printf("Vetor arrumado: ");
    for (i = 0; i < tamanhoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void MergeSortMain(void) {
    int vetor[50] = {};
    int tamanhoVetor;

    inputMerge(vetor, &tamanhoVetor);
    int* sortedArr = mergeSort(vetor, tamanhoVetor);
    outputMerge(sortedArr, tamanhoVetor);
}
