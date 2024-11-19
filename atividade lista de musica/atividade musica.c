
#include<stdio.h>
#include<stdlib.h>

typedef struct No{

    char titulodamusica[15];
    char artista[15];
    int duracao;

    struct No *proximoNo;
    struct No *noAnterior;
}no;

typedef struct listaencadeada{
    no *head;
}le;

void inseririnicio(le *l,int val);
void inserirfim(le *l,int val);
void inserirmeio(le *l,int val,int ref);
void removerno(le *l,int ref);
int imprimirLista(le *l);


int main(){
    le lista1;
    lista1.head = NULL;

    printf("menu de usuario:\n\n");
    printf("1-Adicionar uma nova música");
    printf("2-Remover uma música ");
    printf("3-Visualizar todas as músicas \n");
    printf("4-Limpar a lista de músicas \n");
    printf("5-Pesquisar música por título\n");
    printf("6-Ordenar músicas por título \n");
    printf("7-Contar o total de músicas na lista \n");
    printf("8-sair\n");


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

void inserirmeio(le *l,int val,int ref){
    printf("inserindo no meio:\n");
    no *novono=(no*)malloc(sizeof(no));

    no *nop=l->head;
    while(nop->valor!=ref && nop->proximoNo!=NULL){
        nop=nop->proximoNo;
    }

    novono->proximoNo= nop->proximoNo;
    nop->proximoNo=novono;
    novono->valor = val;
    novono->noAnterior = nop;
    novono->proximoNo->noAnterior = novono; 
}

void removerno(le *l,int ref){
    printf("removendo no:\n");
    no *nop=l->head;
    
    while(nop->valor!=ref){
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