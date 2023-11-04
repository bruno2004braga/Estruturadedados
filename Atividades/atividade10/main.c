#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_put("Chave1", "Valor1");
    hash_table_put("Chave2", "Valor2");

    char* resultado1 = hash_table_get("Chave1");
    if (resultado1) {
        printf("Chave1: %s\n", resultado1);
    } else {
        printf("Chave1 não encontrada na tabela.\n");
    }

    char* resultado2 = hash_table_get("Chave2");
    if (resultado2) {
        printf("Chave2: %s\n", resultado2);
    } else {
        printf("Chave2 não encontrada na tabela.\n");
    }

    if (hash_table_contains("Chave3")) {
        printf("Chave3 encontrada na tabela.\n");
    } else {
        printf("Chave3 não encontrada na tabela.\n");
    }

    hash_table_remove("Chave2");
    char* resultado3 = hash_table_get("Chave2");
    if (resultado3) {
        printf("Chave2: %s\n", resultado3);
    } else {
        printf("Chave2 não encontrada na tabela após remoção.\n");
    }

    return 0;
}
