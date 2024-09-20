#include <stdio.h>
#include <stdlib.h>

int filaVazia(int *queue);
void enfileira(int *queue, int valor, int tamanho);
int desenfileira(int *queue, int tamanho);
void imprimeFila(int *queue, int tamanho);

int main() {
    int tamanho = 100;  
    int *queue = (int *)malloc(tamanho * sizeof(int));

    if (queue == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }


    queue[0] = 2; 
    queue[1] = 2;  

    
    enfileira(queue, 10, tamanho);
    enfileira(queue, 20, tamanho);
    enfileira(queue, 30, tamanho);
    enfileira(queue, 40, tamanho);
    enfileira(queue, 50, tamanho);
    enfileira(queue, 60, tamanho);

    
    desenfileira(queue, tamanho);
    desenfileira(queue, tamanho);

    if (filaVazia(queue)) {
        printf("A fila está vazia!\n");
    } else {
        printf("A fila não está vazia!\n");
    }

    desenfileira(queue, tamanho);
    desenfileira(queue, tamanho);

    
    imprimeFila(queue, tamanho);


    return 0;
}

int filaVazia(int *queue) {
    return queue[0] == queue[1];
}

void enfileira(int *queue, int valor, int tamanho) {
    int fim = queue[1];
    

    if ((fim + 1) % tamanho == queue[0]) {
        printf("Fila cheia! impossível enfileirar %d\n", valor);
        return;
    }

    queue[fim] = valor;  
    queue[1] = (fim + 1) % tamanho; 
    printf("Valor %d enfileirado!\n", valor);
}

int desenfileira(int *queue, int tamanho) {
    if (filaVazia(queue)) {
        printf("Fila vazia! nada para desenfileirar\n");
        return -1; 
    }

    int inicio = queue[0];
    int valor = queue[inicio];  
    queue[0] = (inicio + 1) % tamanho;  
    
    printf("Valor %d desenfileirado!\n", valor);
    return valor;
}


void imprimeFila(int *queue, int tamanho) {
    printf("Fila atual: \n");
    int i = queue[0];
    while (i != queue[1]) {
        printf("%d \n", queue[i]);
        i = (i + 1) % tamanho;
    }
    printf("\n");
}
