#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int id;
    char nomeparada[10];
    struct No *proximono;
    struct No *noanterior;
} no;

typedef struct Listaparadas {
    struct No *head;
    struct No *tail;
    int tamanho;
} lp;

void addparada(lp *lista);
void removerparada(lp *lista);
void imprimirpercurso(lp *lista);

int main() {
    lp linha1;
    linha1.head = NULL;
    linha1.tail = NULL;
    linha1.tamanho = 0;
    char opcao;
    while (1) {
        printf("Digite 'a' para adicionar parada, 'r' para remover parada ou 'p' para imprimir o percurso:\n");
        scanf(" %c", &opcao);
        
        if (opcao == 'a') {
            addparada(&linha1);
        } else if (opcao == 'r') {
            removerparada(&linha1);
        } else if (opcao == 'p') {
            imprimirpercurso(&linha1);
        }
    }
    
    return 0;
}

void addparada(lp *lista) {
    no *novaparada = (no *)malloc(sizeof(no));
    if (!novaparada) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    char novonome[10];
    char comando;

    printf("Quer adicionar no início ou após uma parada já existente? ('i' para início, 'e' para após)\n");
    scanf(" %c", &comando);

    printf("Digite o nome da parada: \n");
    scanf(" %9s", novonome);  
    strcpy(novaparada->nomeparada, novonome);
    novaparada->id = lista->tamanho + 1;
    lista->tamanho++;

    if (comando == 'i') {
        printf("Adicionando no início:\n");
        novaparada->proximono = lista->head;
        novaparada->noanterior = NULL;

        if (lista->head != NULL) {
            lista->head->noanterior = novaparada;
        }
        lista->head = novaparada;

        if (lista->tail == NULL) {
            lista->tail = novaparada;
        }

    } else if (comando == 'e') {
        if (lista->head == NULL) {
            printf("Lista vazia, não é possível adicionar no meio.\n");
            free(novaparada);
            return;
        }

        printf("Adicionando a uma parada já existente:\n");
        printf("Selecione a referência da parada existente ('i' para ID ou 'n' para NOME DA PARADA)\n");
        scanf(" %c", &comando);

        if (comando == 'i') {
            int idreferencia;
            printf("Digite o ID da parada:\n");
            scanf("%d", &idreferencia);
            no *nop = lista->head;

            while (nop != NULL && nop->id != idreferencia) {
                nop = nop->proximono;
            }

            if (nop == NULL) {
                printf("Parada com ID %d não encontrada.\n", idreferencia);
                free(novaparada);
                return;
            }

            novaparada->proximono = nop->proximono;
            novaparada->noanterior = nop;

            if (nop->proximono != NULL) {
                nop->proximono->noanterior = novaparada;
            } else {
                lista->tail = novaparada;  
            }
            nop->proximono = novaparada;

        } else if (comando == 'n') {
            printf("Digite o NOME da parada:\n");
            scanf(" %9s", novonome);
            no *nop = lista->head;

            while (nop != NULL && strcmp(nop->nomeparada, novonome) != 0) {
                nop = nop->proximono;
            }

            if (nop == NULL) {
                printf("Parada com nome '%s' não encontrada.\n", novonome);
                free(novaparada);
                return;
            }

            novaparada->proximono = nop->proximono;
            novaparada->noanterior = nop;

            if (nop->proximono != NULL) {
                nop->proximono->noanterior = novaparada;
            } else {
                lista->tail = novaparada; 
            }
            nop->proximono = novaparada;
        }
    }
}

void removerparada(lp *lista) {
    if (lista->head == NULL) {
        printf("Lista vazia, não há paradas para remover.\n");
        return;
    }

    char comando;
    printf("Selecione a referência da parada a ser removida ('i' para ID ou 'n' para NOME DA PARADA)\n");
    scanf(" %c", &comando);

    if (comando == 'i') {
        int idreferencia;
        printf("Digite o ID da parada a ser removida:\n");
        scanf("%d", &idreferencia);
        no *nop = lista->head;

        while (nop != NULL && nop->id != idreferencia) {
            nop = nop->proximono;
        }

        if (nop == NULL) {
            printf("Parada com ID %d não encontrada.\n", idreferencia);
            return;
        }

        if (nop->noanterior != NULL) {
            nop->noanterior->proximono = nop->proximono;
        } else {
            lista->head = nop->proximono;  
        }

        if (nop->proximono != NULL) {
            nop->proximono->noanterior = nop->noanterior;
        } else {
            lista->tail = nop->noanterior;  
        }

        free(nop);
        lista->tamanho--;
        printf("Parada com ID %d removida.\n", idreferencia);

    } else if (comando == 'n') {
        char novonome[10];
        printf("Digite o NOME da parada a ser removida:\n");
        scanf(" %9s", novonome);
        no *nop = lista->head;

        while (nop != NULL && strcmp(nop->nomeparada, novonome) != 0) {
            nop = nop->proximono;
        }

        if (nop == NULL) {
            printf("Parada com nome '%s' não encontrada.\n", novonome);
            return;
        }

        if (nop->noanterior != NULL) {
            nop->noanterior->proximono = nop->proximono;
        } else {
            lista->head = nop->proximono;  
        }

        if (nop->proximono != NULL) {
            nop->proximono->noanterior = nop->noanterior;
        } else {
            lista->tail = nop->noanterior; 
        }

        free(nop);
        lista->tamanho--;
        printf("Parada com nome '%s' removida.\n", novonome);
    }
}

void imprimirpercurso(lp *lista) {
    if (lista->head == NULL) {
        printf("Percurso vazio!\n");
        return;
    }

    no *nop = lista->head;
    printf("Imprimindo percurso na ida:\n");
    while (nop != NULL) {
        printf("Parada %d: %s\n", nop->id, nop->nomeparada);
        nop = nop->proximono;
    }

    printf("Imprimindo percurso na volta:\n");
    nop = lista->tail;
    while (nop != NULL) {
        printf("Parada %d: %s\n", nop->id, nop->nomeparada);
        nop = nop->noanterior;
    }
}
