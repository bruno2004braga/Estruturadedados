#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    do {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    bubbleSort(arr, n);

    printf("Saída: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
