#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char *string1 = (char*)malloc(50 *sizeof(char));
    char *string2 = (char*)malloc(50 *sizeof(char));

    scanf("%s",string1);
    scanf("%s",string2);
    //fgets(string1,50,stdin);
    //fgets(string2,50,stdin);

    int tam_novo = strlen(string1) + strlen(string2);

    char *stringNova = (char*)malloc(tam_novo * sizeof(char));
    int pos = strlen(string1);
    for(int i = 0; i < strlen(string1);i++){
            stringNova[i] = string1[i];
            //printf("Iterador:%d i:%c o:%c\n",i,string1[i],stringNova[i]);
    }
    for(int j = 0; j < strlen(string2); j++){
        stringNova[j + pos] = string2[j];
        //printf("Iterador:%d i:%c o:%c\n",j,string2[j],stringNova[j + pos]);
    }
    for(int i = 0; i < tam_novo; i++){
        printf("%c",stringNova[i]);
    }

    return 0;
}
