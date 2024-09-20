#include <stdio.h>
#include <stdlib.h>

void criarpilha(char **p1, int qtd);
int push(char *v, int *topo, char val, int tam);
char pop(char *v, int *topo);
void limparpilha(char *p1, int *topo);

int main() {
    char *pilha1;
    int referenciatopo = 0;
    int tamanho = 5;
    char comando;
   

    criarpilha(&pilha1, tamanho);
    printf("ok\n");

    push(pilha1, &referenciatopo, 'p', tamanho);
    push(pilha1, &referenciatopo, 'a', tamanho);
    push(pilha1, &referenciatopo, 'p', tamanho);
    push(pilha1, &referenciatopo, 'o', tamanho);
    push(pilha1, &referenciatopo, 's', tamanho);

    for (int i = 0; i < referenciatopo; i++) {
        printf("pilha[%d] -> %c\n", i, pilha1[i]);
    }

    while(1){
        printf("digite um comando(#para apagar ou @ para apagar tudo):\n");
        scanf(" %c",&comando);
        if(comando == '#'){

            printf("apagando char:\n");
            pop(pilha1,&referenciatopo);
            for (int i = 0; i < referenciatopo; i++) {
                printf("pilha[%d] -> %c\n", i, pilha1[i]);
                }

        }else if(comando == '@'){
            printf("apagando tudo:\n");
            limparpilha(pilha1,&referenciatopo);
            for (int i = 0; i < referenciatopo; i++) {
                printf("pilha[%d] -> %c\n", i, pilha1[i]);
                }
        }else if(comando=='.'){
            printf("programa finalizado\n");
            break;
        }else{
            printf("comando invalido!\n");
        }
    }


    
    free(pilha1);

    return 0;
}

void criarpilha(char **p1, int qtd) {
    *p1 = (char *)malloc(qtd * sizeof(char));
    if (*p1 != NULL) {
        printf("Pilha criada\n");
    } else {
        printf("Erro ao criar a pilha\n");
    }
}

int push(char *v, int *topo, char val, int tam) {
    if (*topo >= tam) {
        printf("Pilha cheia! Valor não foi adicionado\n");
        return 0;
    } else {
        v[*topo] = val;
        *topo += 1;
        printf("Valor adicionado: %c\n", val);
    }

    return 1;
}

char pop(char *v, int *topo) {
    if (*topo <= 0) {
        printf("Pilha vazia! nada para remover\n");
        return '\0'; // Retorna um caractere nulo se a pilha estiver vazia
    } else {
        *topo -= 1;
        return v[*topo]; // Retorna o caractere removido
    }
}

void limparpilha(char *p1, int *topo) {
    if (*topo <= 0) {
        printf("Pilha vazia! nada para remover\n");
    }else{
        *topo=0;
    }
}