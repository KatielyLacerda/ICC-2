#include <stdio.h>
#include <stdlib.h>

// Função para converter um inteiro para sua representação binária
void intToBinary(int num, int vetorbits[], int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        vetorbits[i] = num % 2; // Armazena o bit menos significativo
        num /= 2;
    }
}

// Função para contar o número de bits "1" em uma representação binária
int countOnes(int vetorbits[], int tamanho) {
    int count = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetorbits[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int q; // quantidade de números a serem dados
    int *vetor; // ponteiro para o vetor de elementos
    scanf("%d", &q);

    // Lendo o vetor com alocação dinâmica e já inserindo os elementos ordenados
    vetor = (int *)malloc(q * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1; // Sai do programa com código de erro
    }

    // Lendo vetor
    for (int i = 0; i < q; i++) {
        int elemento;
        scanf("%d", &elemento);

        // Inserção ordenada (usando ordenação por inserção)
        int j = i - 1;
        while (j >= 0 && elemento < vetor[j]) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = elemento;
    }

//agr o vetor está ordenado

    // Alocar memória para o vetor de representações binárias
    int **vetorbits = (int **)malloc(q * sizeof(int *));
    if (vetorbits == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;  // Se der erro na memória
    }

    // Vou supor que o tamanho máximo de 32 + o bit de sinal (33 bits)
    int tamanhoBinario = 33;

    // Converter cada inteiro em sua representação binária
    for (int i = 0; i < q; i++) {
        vetorbits[i] = (int *)malloc(tamanhoBinario * sizeof(int));
        if (vetorbits[i] == NULL) {
            printf("Erro na alocação de memória.\n");
            return 1;
        }
        intToBinary(vetor[i], vetorbits[i], tamanhoBinario);
    }

    // Agora temos um vetor de vetores (cada vetorzinho é o binário de um inteiro)
    // Imprimir as representações binárias
    // Encontrar o maior número de bits "1" em qualquer número binário
    int maiorNumeroDeUns = 0;
    for (int i = 0; i < q; i++) {
        int numeroDeUns = countOnes(vetorbits[i], tamanhoBinario);
        if (numeroDeUns > maiorNumeroDeUns) {
            maiorNumeroDeUns = numeroDeUns;
        }
    }
   //agr sabemos quantos buckets vamos ter
  // Vetor de buckets para armazenar os números com a mesma contagem de bits "1"
    int total = maiorNumeroDeUns + 1; // Total de buckets (baseado no maior número de bits "1")
    int **buckets = (int **)malloc(total * sizeof(int *));
    if (buckets == NULL) {
        printf("Erro na alocação de memória para buckets.\n");
        return 1;
    }

    // Inicializa os vetores de buckets
    for (int i = 0; i < total; i++) {
        buckets[i] = (int *)malloc(q * sizeof(int));
        if (buckets[i] == NULL) {
            printf("Erro na alocação de memória para buckets.\n");
            return 1;
        }
        // Inicializa os elementos do bucket como 0
        for (int j = 0; j < q; j++) {
            buckets[i][j] = 0;
        }
    }

    // Separa os números nos buckets com base na contagem de bits "1"
    int *bucketPositions = (int *)malloc(total * sizeof(int));
    if (bucketPositions == NULL) {
        printf("Erro na alocação de memória para bucketPositions.\n");
        return 1;
    }

    // Inicializa as posições dos buckets como 0
    for (int i = 0; i < total; i++) {
        bucketPositions[i] = 0;
    }

    // Separa os números nos buckets com base na contagem de bits "1"
    for (int i = 0; i < q; i++) {
        int numeroDeUns = countOnes(vetorbits[i], tamanhoBinario);
        buckets[numeroDeUns][bucketPositions[numeroDeUns]] = vetor[i];
        bucketPositions[numeroDeUns]++;
    }

   // Imprime os buckets
   for (int i = 0; i < total; i++) {
       if (bucketPositions[i] > 0) {
          for (int j = 0; j < bucketPositions[i]; j++) {
               printf("%d ", buckets[i][j]);
           }
           printf("\n");
       }
       free(buckets[i]); // Libera a memória alocada para o bucket
   }
  // Vetor ordenado
   for (int i = 0; i < q; i++) {
      printf("%d ", vetor[i]);
   }
  printf("\n");

    // Libera a memória alocada
    free(bucketPositions);
    for (int i = 0; i < q; i++) {
        free(vetorbits[i]);
    }
    free(vetorbits);
    free(vetor);
    free(buckets);

    return 0;
}