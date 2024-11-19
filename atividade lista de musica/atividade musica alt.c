#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char titulodamusica[50];
    char artista[50];
    int duracao;
    struct No *proximoNo;
    struct No *noAnterior;
} no;

typedef struct listaencadeada {
    no *head;
} le;

void inseririnicio(le *l, char *titulo, char *artista, int duracao);
void inserirfim(le *l, char *titulo, char *artista, int duracao);
void removerno(le *l, char *titulo);
void imprimirLista(le *l);
void limparLista(le *l);
no* pesquisarMusica(le *l, char *titulo);
void ordenarMusicas(le *l);
int contarMusicas(le *l);
void menu(le *l);

int main() {
    le lista1;
    lista1.head = NULL;
    menu(&lista1);
    return 0;
}

void menu(le *l) {
    int opcao;
    char titulo[50], artista[50];
    int duracao;

    do {
        printf("\nMenu de usuário:\n");
        printf("1 - Adicionar uma nova música\n");
        printf("2 - Remover uma música\n");
        printf("3 - Visualizar todas as músicas\n");
        printf("4 - Limpar a lista de músicas\n");
        printf("5 - Pesquisar música por título\n");
        printf("6 - Ordenar músicas por título\n");
        printf("7 - Contar o total de músicas na lista\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Título: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove a nova linha
                printf("Artista: ");
                fgets(artista, 50, stdin);
                artista[strcspn(artista, "\n")] = 0; // Remove a nova linha
                printf("Duração (em segundos): ");
                scanf("%d", &duracao);
                inseririnicio(l, titulo, artista, duracao);
                break;
            case 2:
                printf("Título da música a remover: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                removerno(l, titulo);
                break;
            case 3:
                imprimirLista(l);
                break;
            case 4:
                limparLista(l);
                break;
            case 5:
                printf("Título da música a pesquisar: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                no* encontrada = pesquisarMusica(l, titulo);
                if (encontrada) {
                    printf("Música encontrada: Título: %s, Artista: %s, Duração: %d\n",
                           encontrada->titulodamusica, encontrada->artista, encontrada->duracao);
                } else {
                    printf("Música não encontrada.\n");
                }
                break;
            case 6:
                ordenarMusicas(l);
                printf("Músicas ordenadas por título.\n");
                break;
            case 7:
                printf("Total de músicas: %d\n", contarMusicas(l));
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);
}

void inseririnicio(le *l, char *titulo, char *artista, int duracao) {
    no *novono = (no*)malloc(sizeof(no));
    strcpy(novono->titulodamusica, titulo);
    strcpy(novono->artista, artista);
    novono->duracao = duracao;
    novono->proximoNo = l->head;
    novono->noAnterior = NULL;

    if (l->head != NULL) {
        l->head->noAnterior = novono;
    }
    l->head = novono;
}

void removerno(le *l, char *titulo) {
    no *nop = l->head;
    while (nop != NULL && strcmp(nop->titulodamusica, titulo) != 0) {
        nop = nop->proximoNo;
    }
    if (nop == NULL) {
        printf("Música não encontrada.\n");
        return;
    }

    if (nop->noAnterior != NULL) {
        nop->noAnterior->proximoNo = nop->proximoNo;
    } else {
        l->head = nop->proximoNo;
    }

    if (nop->proximoNo != NULL) {
        nop->proximoNo->noAnterior = nop->noAnterior;
    }

    free(nop);
}

void imprimirLista(le *l) {
    no *nop = l->head;
    if (nop == NULL) {
        printf("Nenhuma música na lista.\n");
        return;
    }
    printf("Músicas na lista:\n");
    while (nop != NULL) {
        printf("Título: %s, Artista: %s, Duração: %d segundos\n", nop->titulodamusica, nop->artista, nop->duracao);
        nop = nop->proximoNo;
    }
}

void limparLista(le *l) {
    no *nop = l->head;
    while (nop != NULL) {
        no *temp = nop;
        nop = nop->proximoNo;
        free(temp);
    }
    l->head = NULL;
    printf("Lista de músicas limpa.\n");
}

no* pesquisarMusica(le *l, char *titulo) {
    no *nop = l->head;
    while (nop != NULL) {
        if (strcmp(nop->titulodamusica, titulo) == 0) {
            return nop;
        }
        nop = nop->proximoNo;
    }
    return NULL;
}

void ordenarMusicas(le *l) {
    if (l->head == NULL) return;

    for (no *i = l->head; i != NULL; i = i->proximoNo) {
        for (no *j = i->proximoNo; j != NULL; j = j->proximoNo) {
            if (strcmp(i->titulodamusica, j->titulodamusica) > 0) {
                // Trocar os dados dos nós
                char tempTitulo[50], tempArtista[50];
                int tempDuracao;

                strcpy(tempTitulo, i->titulodamusica);
                strcpy(tempArtista, i->artista);
                tempDuracao = i->duracao;

                strcpy(i->titulodamusica, j->titulodamusica);
                strcpy(i->artista, j->artista);
                i->duracao = j->duracao;

                strcpy(j->titulodamusica, tempTitulo);
                strcpy(j->artista, tempArtista);
                j->duracao = tempDuracao;
            }
        }
    }
}

int contarMusicas(le *l) {
    int contador = 0;
    no *nop = l->head;
    while (nop != NULL) {
        contador++;
        nop = nop->proximoNo;
    }
    return contador;
}
