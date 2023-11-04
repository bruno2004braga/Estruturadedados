#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabela_hash.h"

#define TAMANHO_TABELA 10

struct Nodo {
    char* chave;
    char* dado;
    struct Nodo* proximo;
};

struct Nodo* tabela[TAMANHO_TABELA];

int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TAMANHO_TABELA;
}

char* hash_table_get(char* chave) {
    int indice = hash(chave);
    struct Nodo* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int indice = hash(chave);
    struct Nodo* novo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    novo_nodo->chave = chave;
    novo_nodo->dado = dado;
    novo_nodo->proximo = tabela[indice];
    tabela[indice] = novo_nodo;
}

int hash_table_contains(char* chave) {
    int indice = hash(chave);
    struct Nodo* atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void hash_table_remove(char* chave) {
    int indice = hash(chave);
    struct Nodo* atual = tabela[indice];
    struct Nodo* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

