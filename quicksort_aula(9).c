#include <stdio.h>

//troca os dois elementos do pivo de lugar 
void trocar(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// coloca o array em torno do pivô
int organizar(int arr[], int esquerda, int direita){
  int pivo = arr[direita]; 
  int i = (esquerda - 1);

  for (int j = esquerda; j <= direita - 1; j++){
    if (arr[j] < pivo) {
      i++;
      trocar(&arr[i], &arr[j]);
    }
  }

  trocar(&arr[i + 1], &arr[direita]);
  return (i + 1);
}

// ordena o array usando o Quick Sort
void quick_sort(int arr[], int baixo, int alto) {
  if (baixo < alto) {
    // Encontra o índice do pivô após a partição
    int pi = organizar(arr, baixo, alto);

    // ordena as partições à esquerda e à direita do pivô
    quick_sort(arr, baixo, pi - 1);
    quick_sort(arr, pi + 1, alto);
  }
}

int main() {
  int list[] = {25, 33, 35, 12, 37, 86, 92, 57};
  int tamanho = sizeof(list) / sizeof(list[0]);

  quick_sort(list, 0, tamanho - 1);
//mostra lista ordenada 
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");

  return 0;
}
//melhor caso : o pivor foi bem escolhido no caso bem no meio do vetor logo ele vai criar n/2 repartições logo fica T(n) = n + 2f(n/2) ->
//T(n) = n + 2( n/2 + 2f(n/4)) -> n + 2(n/2+ 2(n/4 + 2f(n/8))) que se observado em O(n . sua função de forma recursiva) que diminiu cade vez mais
//diminui um pouco menos que n vezes então podemos deduzir que será logn portanto no melhor caso ficaria O(nlogn)

//pior caso: quando ja esta ordenado e o pivo esta do lado extremo esquerdo  neste caso a menor celula logo ele verifica as celulas do vetor 
//de tamanho n, n vezes pra cada celula +1 pra removero pivo e particionar depois ele recursivamente usa a propria função com um vetor menor logo n - 1
//logo fica T(n) = (n - 1) + O(n) -> T(n) = (n + 1 ) + ((n - 1) + 1 + f(n - 2)) e vai indo recursivamente logo podemos criar um somatorio ou 
//sabendo já que vai ser repetido n vezes podemos assumir que vai ser O(n²)