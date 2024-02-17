#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void troca(int *x,int  *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}
void printarray(int *vet, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}
void cocktailsort(int **a,int tam){
    int swap = -1;
    do{

        swap = 0;

        for(int i = 0; i < tam - 1; i++){
            if( a[i] > a[i + 1]){
                troca(a[i],a[i + 1]);
                swap = 1;
            }
        }
        printarray(a,tam);
        if(swap == 0){
            break;
        }

        swap = 0;
        for(int i = tam - 1; i > 0; i++){
            if(a[i] > a[i + 1]){
                troca(a[i],a[i + 1]);
                swap = 1;
            }
        }
        printarray(a,tam);

    }while (swap != 0);

}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int swap = -1;

    do{        

        swap = 0;

        for(int i = 0; i < n - 1; i++){
            if( arr[i] > arr[i + 1]){
                troca(&arr[i],&arr[i + 1]);
                swap = 1;
            }
        }
        printarray(arr,n);
        if(swap == 0){
            break;
        }

        swap = 0;
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[i + 1]){
                troca(&arr[i],&arr[i + 1]);
                swap = 1;
            }
        }
        printarray(arr,n);
    }while(swap != 0);

}