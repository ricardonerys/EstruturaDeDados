#include<stdio.h>
#include<stdlib.h>
#include"lde.h"

typedef struct No{
    int valor;
    struct No *proximoNo;
    struct No *noAnterior;
}no;

typedef struct listaencadeada{
    no *head;
    int tamanho;
}le;


void inseririnicio(le *l,int val){

    printf("inserindo no inicio:\n");
    no *novono=(no*)malloc(sizeof(no));



    novono->valor = val;
    novono->proximoNo = l->head;
    novono->noAnterior = NULL;
    l->head=novono;

    if(novono->proximoNo != NULL){
    novono->proximoNo->noAnterior=novono;
    }

}

void inserirfim(le *l,int val){

    printf("inserindo no fim:\n");
    no *novono=(no*)malloc(sizeof(no));

    no *nop=l->head;
    while(nop->proximoNo!=NULL){
        nop=nop->proximoNo;
    }
    nop->proximoNo=novono;

    novono->valor = val;
    novono->proximoNo = NULL;
    novono->noAnterior = nop;

}

void inserirmeio(le *l,int val,int referencia){
    printf("inserindo no meio:\n");
    no *novono=(no*)malloc(sizeof(no));

    no *nop=l->head;
    while(nop->valor!=referencia && nop->proximoNo!=NULL){
        nop=nop->proximoNo;
    }

    novono->proximoNo= nop->proximoNo;
    nop->proximoNo=novono;
    novono->valor = val;
    novono->noAnterior = nop;
    novono->proximoNo->noAnterior = novono; 
}

void removerno(le *l,int referencia){
    printf("removendo no:\n");
    no *nop=l->head;
    
    while(nop->valor!=referencia){
        nop = nop->proximoNo ;
    }

    if(nop->valor == l->head->valor){
        l->head = nop->proximoNo;
        nop->proximoNo->noAnterior = NULL;

    }else{
       nop->noAnterior->proximoNo = nop->proximoNo;
       nop->proximoNo->noAnterior = nop->noAnterior;
    }
    free(nop);
}

int imprimirLista(le *l){
    printf("imprimindo lista..............\n" );
    if(l->head==NULL){
        printf("nenhum no na lista\n");
        return 0;
    }else{
        no *nop=l->head;
        while(nop->proximoNo != NULL){
            
        printf("%d ",nop->valor);

        if(nop->noAnterior!=NULL){
            printf("anterior: %d ",nop->noAnterior->valor);
        }

        if(nop->proximoNo!= NULL){
           printf("proximo:%d ",nop->proximoNo->valor); // (problema ao imprimir)
        }

        printf("\n");

        //printf("no:%d anterior:%d proximo:%d\n",nop->valor,nop->noAnterior->valor,nop->proximoNo->valor);
        nop = nop->proximoNo;

        }
        printf("%d ",nop->valor);
        if(nop->noAnterior!=NULL){
            printf("anterior: %d",nop->noAnterior->valor);
        }
        if(nop->proximoNo!= NULL){
           printf("proximo:%d ",nop->proximoNo->valor); // (problema ao imprimir)
        }
        printf("\n");
            
        return 1;
    }
}