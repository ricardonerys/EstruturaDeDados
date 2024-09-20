#include <stdio.h>
#include <stdlib.h>

void criarpilha(int **p1, int qtd);
int push(int *v, int *topo, int val, int tam);
void criareversa(int *p1, int *p2, int *topo, int *topo2, int tam);

int main() {
    int *pilha1;
    int referenciatopo = 0;
    int tamanho = 5;
    int *pilha2;
    int referenciatopo2 = 0;

    criarpilha(&pilha1, tamanho);
    criarpilha(&pilha2, tamanho);
    printf("ok\n");

    push(pilha1, &referenciatopo, 10, tamanho);
    push(pilha1, &referenciatopo, 20, tamanho);
    push(pilha1, &referenciatopo, 30, tamanho);
    push(pilha1, &referenciatopo, 40, tamanho);
    push(pilha1, &referenciatopo, 50, tamanho);

    for (int i = 0; i < referenciatopo; i++) {
        printf("pilha[%d] -> %d\n", i, pilha1[i]);
    }

    criareversa(pilha1, pilha2, &referenciatopo, &referenciatopo2, tamanho);

    printf("Pilha revertida:\n");
    for (int i = 0; i < referenciatopo2; i++) {
        printf("pilha2[%d] -> %d\n", i, pilha2[i]);
    }
    
    free(pilha1);
    free(pilha2);

    return 0;
}

void criarpilha(int **p1, int qtd) {
    *p1 = (int *)malloc(qtd * sizeof(int));
    if (*p1 != NULL) {
        printf("Pilha criada\n");
    } else {
        printf("Erro ao criar a pilha\n");
    }
}

int push(int *v, int *topo, int val, int tam) {
    if (*topo >= tam) {
        printf("Pilha cheia! Valor não foi adicionado\n");
        return 0;
    } else {
        v[*topo] = val;
        *topo += 1;
        printf("Valor adicionado: %d\n", val);
    }
    return 1;
}

void criareversa(int *p1, int *p2, int *topo, int *topo2, int tam) {

    for (int i = 0; i < *topo; i++) {
        p2[i] = p1[*topo - i - 1]; 
    }
    *topo2 = *topo; 
}
