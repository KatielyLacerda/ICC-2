#include <stdio.h>
#include <stdlib.h>

// Função para intercalar duas listas ordenadas, recebe as litas e seus tamanhos e aloca elas 
void intercalarlistas(int* list1, int tm1, int* list2, int tm2, int** result, int* tmtotal) {
    *tmtotal = tm1 + tm2;
    *result = (int*)malloc((*tmtotal) * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < tm1 && j < tm2) {
        if (list1[i] < list2[j]) {
            (*result)[k++] = list1[i++];
        } else {
            (*result)[k++] = list2[j++];
        }
    }

    while (i < tm1) {
        (*result)[k++] = list1[i++];
    }

    while (j < tm2) {
        (*result)[k++] = list2[j++];
    }
}

// função de inverter  lista
void inverterlist(int* list, int tm) {
    int left = 0, right = tm - 1;

    while (left < right) {
        int temp = list[left];
        list[left] = list[right];
        list[right] = temp;
        left++;
        right--;
    }
}

int main() {
    int n1, n2;
    scanf("%d", &n1);

    int* list1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &list1[i]);
    }

    scanf("%d", &n2);

    int* list2 = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &list2[i]);
    }

    int* resultList;
    int tmtotal;

    intercalarlistas(list1, n1, list2, n2, &resultList, &tmtotal);
    inverterlist(resultList, tmtotal);

    for (int i = 0; i < tmtotal; i++) {
        printf("%d ", resultList[i]);
    }
    printf("\n");

    free(list1);
    free(list2);
    free(resultList);

    return 0;
}