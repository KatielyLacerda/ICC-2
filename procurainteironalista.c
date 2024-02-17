#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// busca o inteiro na lista
Node *busca(Node *head, int x) {
  Node *current = head;

  // Percorre a lista até encontrar o valor ou chegar ao final
  while (current != NULL) {
    if (current->data == x) {
      return current; // Retorna o ponteiro para o registro encontrado
    }
    current = current->next;
  }

  return NULL; // Retorna NULL se n achar o valor
}

int main() {
  Node *head = NULL;
  Node *newNode = NULL;
  int n; // Número de elementos na lista
  int x; // Número a ser procurado

  printf("Número de elementos da lista? ");
  scanf("%d", &n);

  // Preenche a lista com números fornecidos pelo usuário
  printf("Digite os números separados por um espaço:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
      printf("Erro ao alocar memória para o nó.\n");
      return 1; // caso não tenha memória
    }
    newNode->data = x;
    newNode->next = head;
    head = newNode;
  }
// Solicita o número a ser procurado
  printf("Número que deseja achar na lista: ");
  scanf("%d", &x);

  // Busca o valor na lista
  Node *resultado = busca(head, x);

  // Verifica se o valor foi encontrado e imprime
  if (resultado != NULL) {
    printf("O valor %d foi encontrado na lista.\n", x);
  } else {
    printf("NULL\n");
  }

  // Libera a memória alocada para a lista
  while (head != NULL) {
    Node *temp = head;
    head = head->next;
    free(temp); // Libera a memória do nó atual
  }

  return 0;
}
