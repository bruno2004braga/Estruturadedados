#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

void calcularRegressao(FILE *file, Ponto *pontos, int numPontos) {
    int i;
    int sumX = 0;
    float sumY = 0;
    float sumXY = 0;
    float sumXX = 0;
    

    for (i = 0; i < numPontos; i++) {
        fscanf(file, "%d,%f", &(pontos[i].x), &(pontos[i].y));
        sumX += pontos[i].x;
        sumY += pontos[i].y;
        sumXY += pontos[i].x * pontos[i].y;
        sumXX += pontos[i].x * pontos[i].x;
    }
    

    float avgX = (float)sumX / numPontos;
    float avgY = sumY / numPontos;
    

    float slope = (sumXY - numPontos * avgX * avgY) / (sumXX - numPontos * avgX * avgX);
    
    float intercept = avgY - slope * avgX;
    

    printf("y = %fx + %f\n", slope, intercept);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Modo de uso: ./regressao <dados.csv>\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    int numPontos = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            numPontos++;
        }
    }
    rewind(file);
    
    Ponto *pontos = (Ponto *)malloc(numPontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return 1;
    }
    
    calcularRegressao(file, pontos, numPontos);
    
    free(pontos);
    fclose(file);
    
    return 0;
}
