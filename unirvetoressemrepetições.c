#include <stdio.h>
#include <stdlib.h> // Adicione esta linha para incluir a biblioteca necessária

// Função recursiva que une dois vetores supondo que não há elementos repetidos nem iguais nesses vetores
int* unirlista(int* lista1, int n1, int* lista2, int n2, int* novotamanho) {
    *novotamanho = n1 + n2;
    int* listajunta = (int*)malloc((*novotamanho) * sizeof(int)); // Corrigido aqui

    if (listajunta == NULL) {
        perror("Erro na alocação de memória");
        exit(1); // Adicionei uma saída do programa em caso de erro na alocação de memória
    }

    int i = 0, j = 0, k = 0; // Iteradores

    // Junte as listas na lista nova
    while (i < n1 && j < n2) {
        if (lista1[i] <= lista2[j]) {
            listajunta[k++] = lista1[i++];
        } else {
            listajunta[k++] = lista2[j++];
        }
    }

    while (i < n1) {
        listajunta[k++] = lista1[i++];
    }

    while (j < n2) {
        listajunta[k++] = lista2[j++];
    }

    return listajunta;
}

// Função para remover elementos repetidos de um vetor
int* tirar_repetidos(int* vetor, int tamanho, int* tamanhototal) {
    if (tamanho <= 1) {
        *tamanhototal = tamanho;
        return vetor;
    }

    int* vetor_sem_repeticao = (int*)malloc(tamanho * sizeof(int));

    if (vetor_sem_repeticao == NULL) {
        perror("Erro na alocação de memória");
        exit(1); // Adicionei uma saída do programa em caso de erro na alocação de memória
    }

    int i, j, encontrado;

    vetor_sem_repeticao[0] = vetor[0];
    int novo_tam = 1;

    for (i = 1; i < tamanho; i++) {
        encontrado = 0;
        for (j = 0; j < novo_tam; j++) {
            if (vetor[i] == vetor_sem_repeticao[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            vetor_sem_repeticao[novo_tam++] = vetor[i];
        }
    }

    *tamanhototal = novo_tam;
    return vetor_sem_repeticao;
}

int main() {
    int n1, n2; // Tamanhos das listas

    // Lendo as listas com alocação dinâmica
    scanf("%d", &n1);
    int* lista1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &lista1[i]);
    }

    scanf("%d", &n2);
    int* lista2 = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &lista2[i]);
    }

    int novotamanho;
    // Usando a função de unir listas
    int* listajunta = unirlista(lista1, n1, lista2, n2, &novotamanho);

    int tamanho_sem_repeticao;
    int* resultado_sem_repeticao = tirar_repetidos(listajunta, novotamanho, &tamanho_sem_repeticao);
    for (int i = 0; i < tamanho_sem_repeticao; i++) {
        printf("%d ", resultado_sem_repeticao[i]);
    }
    printf("\n");

    // Liberando a memória alocada
    free(lista1);
    free(lista2);
    free(listajunta);
    free(resultado_sem_repeticao);

    return 0;
}

