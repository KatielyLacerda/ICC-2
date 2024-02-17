#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no* next;
} No;

// Função para inserir um novo nó na lista de forma ordenada
void inserir(No** lista, int x) {
    No* aux, *novo = malloc(sizeof(No));
    if (novo) {
        novo->num = x;
        // Verificando se a lista está vazia
        if (*lista == NULL) {
            novo->next = NULL;
            *lista = novo;
        }
        else if (novo->num < (*lista)->num) {
            novo->next = *lista;
            *lista = novo;
        }
        else {
            aux = *lista;
            while (aux->next && novo->num > aux->next->num)
                aux = aux->next;
            novo->next = aux->next;
            aux->next = novo;
        }
    }
    else {
        printf("Erro ao alocar memória para o novo nó.\n");
    }
}

// Função para imprimir a lista
void imprimirLista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->num);
        atual = atual->next;
    }
    printf("NULL\n");
}

int main() {
    int num;
    No* lista = NULL;

    while (1) {
        printf("Digite um número (ou digite -1 para sair): ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        inserir(&lista, num);
        imprimirLista(lista);
    }

    // Imprimir a lista final ordenada
    printf("Lista ordenada:\n");
    imprimirLista(lista);

    return 0;
}






