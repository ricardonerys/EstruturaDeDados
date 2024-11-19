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
                titulo[strcspn(titulo, "\n")] = 0; 
                printf("Artista: ");
                fgets(artista, 50, stdin);
                artista[strcspn(artista, "\n")] = 0; 
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

    if (l->head == NULL) {
        novono->proximoNo = novono; 
        novono->noAnterior = novono; 
    } else {
        no *ultimo = l->head->noAnterior; 
        novono->proximoNo = l->head; 
        novono->noAnterior = ultimo;
        ultimo->proximoNo = novono; 
        l->head->noAnterior = novono; 
    }
    l->head = novono;
}

void inserirfim(le *l, char *titulo, char *artista, int duracao) {
    no *novono = (no*)malloc(sizeof(no));
    strcpy(novono->titulodamusica, titulo);
    strcpy(novono->artista, artista);
    novono->duracao = duracao;

    if (l->head == NULL) {
        novono->proximoNo = novono; 
        novono->noAnterior = novono;
        l->head = novono;
    } else {
        no *ultimo = l->head->noAnterior; 
        ultimo->proximoNo = novono; 
        novono->noAnterior = ultimo; 
        novono->proximoNo = l->head; 
        l->head->noAnterior = novono; 
    }
}

void removerno(le *l, char *titulo) {
    if (l->head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    no *nop = l->head;
    do {
        if (strcmp(nop->titulodamusica, titulo) == 0) {
            if (nop->noAnterior == nop) {
                
                free(nop);
                l->head = NULL;
            } else {
                nop->noAnterior->proximoNo = nop->proximoNo; 
                nop->proximoNo->noAnterior = nop->noAnterior;
                if (nop == l->head) {
                    l->head = nop->proximoNo; 
                }
                free(nop);
            }
            return;
        }
        nop = nop->proximoNo;
    } while (nop != l->head);

    printf("Música não encontrada.\n");
}

void imprimirLista(le *l) {
    if (l->head == NULL) {
        printf("Nenhuma música na lista.\n");
        return;
    }

    no *nop = l->head;
    printf("Músicas na lista:\n");
    do {
        printf("Título: %s, Artista: %s, Duração: %d segundos\n", nop->titulodamusica, nop->artista, nop->duracao);
        nop = nop->proximoNo;
    } while (nop != l->head);
}

void limparLista(le *l) {
    if (l->head == NULL) return;

    no *nop = l->head;
    do {
        no *temp = nop;
        nop = nop->proximoNo;
        free(temp);
    } while (nop != l->head);
    
    l->head = NULL;
    printf("Lista de músicas limpa.\n");
}

no* pesquisarMusica(le *l, char *titulo) {
    no *nop = l->head;
    if (nop == NULL) return NULL;

    do {
        if (strcmp(nop->titulodamusica, titulo) == 0) {
            return nop;
        }
        nop = nop->proximoNo;
    } while (nop != l->head);

    return NULL;
}

void ordenarMusicas(le *l) {
    if (l->head == NULL) return;

    int trocado;
    do {
        no *i = l->head;
        trocado = 0;

        do {
            no *j = i->proximoNo;
            if (j != l->head && strcmp(i->titulodamusica, j->titulodamusica) > 0) {
                
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
                trocado = 1;
            }
            i = j;
        } while (i != l->head);
    } while (trocado);
}

int contarMusicas(le *l) {
    if (l->head == NULL) return 0;

    int count = 0;
    no *nop = l->head;
    do {
        count++;
        nop = nop->proximoNo;
    } while (nop != l->head);

    return count;
}
