#include <math.h>
#include <stdio.h>
#include <string.h>
// Escreva uma função que transforme uma
// string (que contenha apenas dígitos) em um
// número inteiro, para uma dada base.

int main() {
  char numeros[10]; // Definindo um tamanho de números pra entrada
  int base;
  scanf("%s", numeros);
  scanf("%d", &base);

  int convertido = 0; // vai armazenar o número inteiro convertido
  for (int i = 0; numeros[i] != '\0'; i++) {
    // Verifica se o caractere atual é um dígito
    if (numeros[i] >= '0' && numeros[i] <= '9') {
      convertido = convertido * 10 + (numeros[i] - '0');
    } else {
      printf("A string contém caracteres inválidos.\n");
      return 1; // caso tenho caractres que não são números
    }
  }

 // tranformar o int num vetor (vai ficar mais fácil trabalhar com ele assim)
  int numero = convertido; // quero usar o número convertido sem altera-ló pois
                           // vou usa-ló novamento mais pra frente
  int numerodedigitos = 0;
  while (numero != 0) { // conta o número de digitos do inteiro
    numero /= 10;
    numerodedigitos++;
  }
  numero = convertido;
  int vetordenumeros[numerodedigitos]; // vetor que armazenara os digitos
  for (int i = numerodedigitos - 1; i >= 0; i--) {
    vetordenumeros[i] = numero % 10;
    numero /= 10;
  }
  
  
  // fazendo a conta na base dada
  int resultado = 0; // guarda o resultado da conta na base dada
  int tamanho = numerodedigitos;
  for (int i = 0; i < numerodedigitos; i++) {
    resultado += vetordenumeros[i] * pow(base, numerodedigitos - 1 - i);
  }
  printf("\n");
  printf("%d", resultado);

  return 0;
}