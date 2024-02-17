#include <stdio.h>
//eu não usei a função recursiva nesse caso pq eu já sabia quais valores de h usar, (deixarei o códivo com a função recursiva como comentario  abaixo, é a mesma coisa, exeto que temso a funçaõ calcular_h que calcula os valores de h.)
//Eu não entendi bem o que significava buscar uma prova da compelxidade de shell-sort, então pesquisei uns arquivos e achei um interessante nesse link:https://sol.sbc.org.br/index.php/etc/article/download/3144/3106/. Achei vários na verdade,mas esse é um menor, os outros eram bem maiores. 
//definindo uma função shell sort
void shellSort(int arr[], int n) {
    int i, j, h, aux;

    int incrementos[] = {5, 3, 1};//já temos os nossos incrementos que foram pedidos no slide

    for (int k = 0; k < 3; k++) {
        h = incrementos[k];
        for (i = h; i < n; i++) {
            aux = arr[i];
            for (j = i; j >= h && arr[j - h] > aux; j -= h) {
                arr[j] = arr[j - h];
            }
            arr[j] = aux;
        }
    }
}

int main() {
    int vetor[] = {25, 57, 48, 37, 12, 92, 86, 33};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    
    //printa o vetor ordenado 
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

//código sem os h definidos,usando a funçaõ do slide. 
#include <stdio.h>

// Função recursiva para calcular os valores de h
/*int calculando_h(int i) {
    if (i == 1) {
        return 1;
    } else {
        return 3 * calculando_h(i - 1) + 1;
    }
}

// Shell Sort
void shell_Sort(int arr[], int n) {
    for (int h = calculando_h(1); h > 0; h = calculando_h(h)) {
        for (int i = h; i < n; i++) {
            int aux = arr[i];
            int j;

            for (j = i; j >= h && arr[j - h] > aux; j -= h) {
                arr[j] = arr[j - h];
            }

            arr[j] = aux;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}*/
