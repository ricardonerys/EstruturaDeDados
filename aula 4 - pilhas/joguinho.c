#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[20];
    char item[20];
    char tipoTerreno[20];
    struct No* anterior;
    struct No* proximo;
} No;

No* criarNo(char* nome, char* item, char* tipoTerreno) {
    No* novoNo = (No*) malloc(sizeof(No));
    strcpy(novoNo->nome, nome);
    strcpy(novoNo->item, item);
    strcpy(novoNo->tipoTerreno, tipoTerreno);
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionarNo(No** inicio, char* nome, char* item, char* tipoTerreno) {
    No* novoNo = criarNo(nome, item, tipoTerreno);
    if (*inicio == NULL) {
        *inicio = novoNo;
    } else {
        No* atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
        novoNo->anterior = atual;
    }
}

void campoVisao(No* atual) {
    printf("Posicao do personagem: %s\n", atual->nome);

    printf("Direita: ");
    No* direita = atual->proximo;
    for (int i = 0; i < 2 && direita != NULL; i++) {
        printf("%s ", direita->nome);
        direita = direita->proximo;
    }
    printf("\n");

    printf("Esquerda: ");
    No* esquerda = atual->anterior;
    for (int i = 0; i < 2 && esquerda != NULL; i++) {
        printf("%s ", esquerda->nome);
        esquerda = esquerda->anterior;
    }
    printf("\n");
}

int main() {
    No* mapa = NULL;
    int tamMapa, movimentos;

    printf("Tamanho do mapa: ");
    scanf("%d", &tamMapa);

    for (int i = 1; i <= tamMapa; i++) {
        char nome[20], item[20], tipoTerreno[20];
        sprintf(nome, "Posicao %d", i);
        sprintf(item, "Item %d", i);
        sprintf(tipoTerreno, "Terreno %d", i);
        adicionarNo(&mapa, nome, item, tipoTerreno);
    }

    No* personagem = mapa;

    while (1) {
        campoVisao(personagem);

        printf("Digite quantas casas vai andar (num positivo para direita, num negativo para esquerda): ");
        scanf("%d", &movimentos);

        if (movimentos > 0) {
            for (int i = 0; i < movimentos && personagem->proximo != NULL; i++) {
                personagem = personagem->proximo;
            }
        } else {
            for (int i = 0; i > movimentos && personagem->anterior != NULL; i--) {
                personagem = personagem->anterior;
            }
        }
    }

    return 0;
}
