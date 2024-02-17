#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam;//tamanho

    
    scanf("%d",&tam);
    int *vet;
    vet = (int*)malloc(tam * sizeof(int));
    
    for (int i = 0; i < tam; i++){
        //printf("tam:%d i:%d\n",tam,i);
        scanf("%d",&vet[i]);
    }
    int sum;//soma
    scanf("%d",&sum);

    int check = 0,indice = 0,sumsub = 0;//soma de subsequencia
    do
    {
        for(int i = indice; i < tam; i++){
            //printf("indice:%d i:%d veti:%d Sumsub:%d \n",indice,i,vet[i],sumsub);
            sumsub = sumsub + vet[i];
            if(sumsub == sum){
                printf("%d %d\n",indice + 1,i + 1);
                check = 1;
                break;
            }
        }
        sumsub = 0;
        indice++;
    }while(check != 1);
    
    

    
}