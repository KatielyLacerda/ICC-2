#include <stdio.h>

void ordenalist(
    int arr[], int n,
    int i) { // mantem a propriedade do heap ternário garantindo que o i seja
             // maior ou igauis aos seus "filhos" de forma recursiva
  int maior = i;
  int esquer = 3 * i + 1;
  int meio = 3 * i + 2;
  int direira = 3 * i + 3;

  if (esquer < n && arr[esquer] > arr[maior])
    maior = esquer;

  if (meio < n && arr[meio] > arr[maior])
    maior = meio;

  if (direira < n && arr[direira] > arr[maior])
    maior = direira;

  if (maior != i) {
    int temp = arr[i];
    arr[i] = arr[maior];
    arr[maior] = temp;
    ordenalist(arr, n, maior);
  }
}

void TernaryHeap(int arr[], int n) { // fazendo um heap ternário a partir de um
                                     // vetor (desordenado no nosso caso)
  for (int i = (n / 3) - 1; i >= 0; i--) {
    ordenalist(arr, n, i);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int vetor[n];
  for (int i = 0; i < n; i++) { // lendo os elementos do vetor
    scanf("%d", &vetor[i]);
  }

  // Print   do vetor inicial
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  // Construção do vetor depois de fazer o Heap ternário
  TernaryHeap(vetor, n);

  // Imprime estado após a construção do heap ternário
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
  printf("\n");

  // Ordenação
  for (int i = n - 1; i > 0; i--) {
    // Troca o primeiro elemento com o último não ordenado
    int temp = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = temp;

    // Imprime o estado após remover o maior elemento
    for (int j = 0; j < i; j++) {
      printf("%d ", vetor[j]);
    }
    printf("- %d ", vetor[i]);
    printf("\n");

    // Reorganiza o heap ternário apenas se houver mais de um elemento no vetor,
    if (i > 1) {
      ordenalist(vetor, i, 0);

      // Imprime o estado após reorganizar o heap
      for (int j = 0; j < i; j++) {
        printf("%d ", vetor[j]);
      }
      printf("\n");
    }

    // Adiciona uma quebra de linha entre os pares de vetores
    printf("\n");
  }

  // Imprime o array ordenado
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}