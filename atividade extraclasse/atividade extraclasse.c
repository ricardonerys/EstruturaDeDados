#include <stdio.h>
#include <stdlib.h>

typedef struct integer {
    int item;
    struct integer *next;
    struct integer *prev;
} Integer;

typedef Integer *P_i;


void concatenaListas(P_i *lista1, P_i *lista2); 
void imprimeLista(P_i lista);
P_i criaNo(int item);

int main() {

    P_i lista1 = criaNo(1);
    lista1->next = criaNo(2);
    lista1->next->prev = lista1;
    lista1->next->next = criaNo(3);
    lista1->next->next->prev = lista1->next;

    
    P_i lista2 = criaNo(4);
    lista2->next = criaNo(5);
    lista2->next->prev = lista2;
    lista2->next->next = criaNo(6);
    lista2->next->next->prev = lista2->next;


    concatenaListas(&lista1, &lista2);
    imprimeLista(lista1);

    return 0;
}



void concatenaListas(P_i *lista1, P_i *lista2) {
    if (*lista1 == NULL) {
        *lista1 = *lista2;
        return;
    }
    
    if (*lista2 == NULL) {
        return;
    }

    P_i ultimoLista1 = *lista1;
    while (ultimoLista1->next != NULL) {
        ultimoLista1 = ultimoLista1->next;
    }

    ultimoLista1->next = *lista2;
    (*lista2)->prev = ultimoLista1;
}

void imprimeLista(P_i lista) {
    P_i atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->item);
        atual = atual->next;
    }
    printf("\n");
}


P_i criaNo(int item) {
    P_i novo = (P_i)malloc(sizeof(Integer));
    novo->item = item;
    novo->next = NULL;
    novo->prev = NULL;
    return novo;
}

