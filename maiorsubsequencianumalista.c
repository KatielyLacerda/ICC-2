#include <stdio.h>
#include <stdlib.h>

int main() {
  int tam; // tamanho
  
  scanf("%d", &tam);
  int *vet;
  vet = (int *)malloc(tam * sizeof(int));

    //lendo vetor
  for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
     }

  int maxSomaAtual = vet[0];
  int maxSomaGlobal = vet[0];
  int inicio = 0;
  int fim = 0;
  int inicioTemp = 0;

  for(int i = 1; i < tam; i++) {
    if (vet[i] > (maxSomaAtual + vet[i])) {
          maxSomaAtual = vet[i];
          inicioTemp = i;
     } else{
          maxSomaAtual = maxSomaAtual + vet[i];
     }
  
        if(maxSomaAtual > maxSomaGlobal) {
          maxSomaGlobal = maxSomaAtual;
          inicio = inicioTemp;
          fim = i;
     }
    }

    //subsequência maior 
  printf("%d\n", maxSomaGlobal);
  // Imprimindo a subsequência maior 
  printf("maior sub: ");
    for (int i = inicio; i <= fim; i++) {
        printf("%d", vet[i]);
        if(i != fim) {
            printf(" ");
        }
    }
  printf("\n");

  free(vet); // Liberar a memória alocada para o vetor

  return 0;
}





