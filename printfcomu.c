#include <stdio.h>
#include <stdarg.h>

void my_printf(char *digito, ...) {
    va_list args;
    va_start(args, digito);

    while (*digito != '\0') {
        if (*digito == '%') {
            digito++; // Avance para o próximo caractere após '%'
            
            // Verifique o caractere após '%' para determinar o tipo
            if (*digito == 'u') {
                printf("%u", va_arg(args, unsigned int));
            } else {
                putchar('%'); // Se o formato não for reconhecido
                putchar(*digito);
            }
        } else {
            putchar(*digito);
        }
        digito++; // Avance para o próximo caractere no formato
    }

    va_end(args);
}

int main() {
    unsigned int num;
    scanf("%d", &num);
    
    my_printf("número inteiro: %u\n", num);
    
    return 0;
}


