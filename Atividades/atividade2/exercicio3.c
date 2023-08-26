#include <stdio.h>
#include <string.h>

int busca_string(char** array, int tamanho, char* busca) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char* array[3] = {"texto", "J", "EDA"};
    char* busca = "EDO";
    int resultado;

    resultado = busca_string(array, 3, busca);

    printf("%d\n", resultado);

    return 0;
}
