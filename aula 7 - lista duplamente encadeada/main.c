#include<stdio.h>
#include<stdlib.h>
#include"lde.h"

int main(){
    le lista1;
    lista1.head = NULL;
    lista1.tamanho = 0;

    inseririnicio(&lista1,10);
    inseririnicio(&lista1,20);
    inseririnicio(&lista1,30);
    inseririnicio(&lista1,40);
    inserirfim(&lista1,5);
    inserirfim(&lista1,4);
    imprimirLista(&lista1);
    inserirmeio(&lista1,100,20);
    imprimirLista(&lista1);
    removerno(&lista1,40);
    removerno(&lista1,30);
    imprimirLista(&lista1);
    return 0;
}