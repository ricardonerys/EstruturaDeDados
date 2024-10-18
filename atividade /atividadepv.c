#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[20];
    char item[20];
    char tipoTerreno[20];
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct Mapa {
    No *inicio;
    No *fim;
    int tamanho;
} Mapa;

Mapa* criarMapa(int tamanho) {
    Mapa *mapa = (Mapa *)malloc(sizeof(Mapa));
    mapa->inicio = NULL;
    mapa->fim = NULL;
    mapa->tamanho = tamanho;

    // Criação dos nós do mapa
    for (int i = 0; i < tamanho; i++) {
        No *novoNo = (No *)malloc(sizeof(No));
        snprintf(novoNo->nome, sizeof(novoNo->nome), "Posição %d", i + 1);
        snprintf(novoNo->item, sizeof(novoNo->item), "Item %d", i + 1);
        snprintf(novoNo->tipoTerreno, sizeof(novoNo->tipoTerreno), "Terreno %d", i + 1);

        novoNo->proximo = NULL;
        novoNo->anterior = NULL;

        if (mapa->inicio == NULL) {
            mapa->inicio = novoNo;
            mapa->fim = novoNo;
        } else {
            mapa->fim->proximo = novoNo;
            novoNo->anterior = mapa->fim;
            mapa->fim = novoNo;
        }
    }

    return mapa;
}

void liberarMapa(Mapa *mapa) {
    No *atual = mapa->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(mapa);
}

void moverPersonagem(Mapa *mapa, int *posicao, int passos) {
    *posicao += passos;

    // Verificar limites
    if (*posicao < 0) {
        *posicao = 0;
    } else if (*posicao >= mapa->tamanho) {
        *posicao = mapa->tamanho - 1;
    }

    printf("Posição do personagem: %d\n", *posicao + 1);
    
    // Mostrar campo de visão
    printf("Direita: ");
    for (int i = 1; i <= 2; i++) {
        if (*posicao + i < mapa->tamanho) {
            printf("%s ", (mapa->inicio + (*posicao + i))->nome);
        }
    }
    
    printf("\nEsquerda: ");
    for (int i = 1; i <= 2; i++) {
        if (*posicao - i >= 0) {
            printf("%s ", (mapa->inicio + (*posicao - i))->nome);
        }
    }
    printf("\n");
}

int main() {
    int tamanho, passos;
    printf("Digite o tamanho do mapa (número de posições): ");
    scanf("%d", &tamanho);

    Mapa *mapa = criarMapa(tamanho);
    int posicao = 0; // posição inicial do personagem

    while (1) {
        printf("Digite quantas casas o personagem vai andar (positivo para direita, negativo para esquerda, 0 para sair): ");
        scanf("%d", &passos);
        
        if (passos == 0) {
            break;
        }

        moverPersonagem(mapa, &posicao, passos);
    }

    liberarMapa(mapa);
    return 0;
}
