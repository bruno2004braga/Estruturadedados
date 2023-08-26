#include <stdio.h>

void multiplica_array(int arr1[], int arr2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = arr1[i] * arr2[i];
    }
}

int main() {
    int arr1[] = {9, 3, 7, 4};
    int arr2[] = {5, 7, 9, 6};
    int tamanho = sizeof(arr1) / sizeof(arr1[0]);
    int resultado[tamanho];

    multiplica_array(arr1, arr2, resultado, tamanho);

    printf("O resultado da multiplicação entres as arrays ehh: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
