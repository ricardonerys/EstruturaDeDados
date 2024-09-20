#include <stdio.h>
#include <stdlib.h>

void criafila(int **vetor, int tf);
void enqueue(int *vetor, int *inp, int *inu, int t, int val);
int dequeue(int *vetor, int *inp, int *inu, int t);
void intercalarFilas(int *fila1, int *fila2, int *inp1, int *inu1, int *inp2, int *inu2, int t, int **filaIntercalada);

int main() {
    int *fila1, *fila2, *filaIntercalada;
    int ip1 = 0, iu1 = 0; // Índices da fila 1
    int ip2 = 0, iu2 = 0; // Índices da fila 2
    int tamanhofila = 5;

    // Criação das filas
    criafila(&fila1, tamanhofila);
    criafila(&fila2, tamanhofila);

    // Enfileira elementos na fila 1
    enqueue(fila1, &ip1, &iu1, tamanhofila, 10);
    enqueue(fila1, &ip1, &iu1, tamanhofila, 20);
    enqueue(fila1, &ip1, &iu1, tamanhofila, 30);

    // Enfileira elementos na fila 2
    enqueue(fila2, &ip2, &iu2, tamanhofila, 100);
    enqueue(fila2, &ip2, &iu2, tamanhofila, 200);
    enqueue(fila2, &ip2, &iu2, tamanhofila, 300);

    // Intercala as duas filas e cria a fila intercalada
    intercalarFilas(fila1, fila2, &ip1, &iu1, &ip2, &iu2, tamanhofila, &filaIntercalada);

    // Imprime a fila intercalada
    printf("Fila Intercalada: ");
    for (int i = 0; i < (iu1 + iu2 - ip1 - ip2); i++) {
        printf("%d ", filaIntercalada[i]);
    }
    printf("\n");

    // Libera a memória
    free(fila1);
    free(fila2);
    free(filaIntercalada);

    return 0;
}

void criafila(int **vetor, int tf) {
    *vetor = (int*)malloc(tf * sizeof(int));
    if (*vetor != NULL) {
        printf("Fila criada!\n");
    } else {
        printf("Erro ao criar a fila!\n");
        exit(EXIT_FAILURE);
    }
}

void enqueue(int *vetor, int *inp, int *inu, int t, int val) {
    if ((*inu + 1) % t == *inp) {
        printf("Fila cheia! Não foi possível enfileirar %d\n", val);
        return;
    }
    vetor[*inu] = val;
    *inu = (*inu + 1) % t;
    printf("Valor adicionado à fila: %d\n", val);
}

int dequeue(int *vetor, int *inp, int *inu, int t) {
    if (*inp == *inu) {
        printf("Fila vazia! Não há elementos para desenfileirar\n");
        return -1;
    }
    int valorRemovido = vetor[*inp];
    *inp = (*inp + 1) % t;
    printf("Valor removido: %d\n", valorRemovido);
    return valorRemovido;
}

void intercalarFilas(int *fila1, int *fila2, int *inp1, int *inu1, int *inp2, int *inu2, int t, int **filaIntercalada) {
    int i = 0;
    criafila(filaIntercalada, t * 2); // Cria fila intercalada com espaço suficiente

    while (*inp1 != *inu1 || *inp2 != *inu2) {
        if (*inp1 != *inu1) { // Adiciona da fila 1 se não estiver vazia
            (*filaIntercalada)[i++] = fila1[*inp1];
            *inp1 = (*inp1 + 1) % t;
        }
        if (*inp2 != *inu2) { // Adiciona da fila 2 se não estiver vazia
            (*filaIntercalada)[i++] = fila2[*inp2];
            *inp2 = (*inp2 + 1) % t;
        }
    }
}
