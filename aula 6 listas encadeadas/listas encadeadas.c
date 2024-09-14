//dados entrelaçados;
//parecido com as filas comuns
//tem o tamanho dinamico
//cada nó tem pelomenos o dado e um ponteiro para o proximo
//1-criar estrutura de uma lista encadeada e de nó
//2-criar lista encadeada
//3-criar no
//4-inserir no na lista


#include<stdio.h>

typedef struct No{
    int valor;
    struct No *proximoNo;
}no;

typedef struct listaencadeada{
    no *head;
    int tamanho;
}le;

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


void inseririnicio(le *l,int val){
    printf("inserindo no inicio:\n");
    no *novono=(no*)malloc(sizeof(no));
    novono->valor = val;
    novono->proximoNo = l->head;
    l->head=novono;
    

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

}

void removerno(le *l,int ref){
    printf("removendo no:\n");
    no *nop=l->head;
    no *noant=l->head;
    while(nop->valor!=ref){
        noant = nop;
        nop = nop->proximoNo ;
    }
    if(nop->valor == l->head->valor){
        l->head = nop->proximoNo;
    }else{
        noant->proximoNo = nop->proximoNo;
    }

}

int imprimirLista(le *l){
    printf("imprimindo valor\n" );
    if(l->head==NULL){
        printf("nenhum no na lista\n");
        return 0;
    }else{
        no *nop=l->head;
        while(nop->proximoNo != NULL){
        printf("%d\n",nop->valor);
        nop = nop->proximoNo;

        }
        printf("%d\n",nop->valor);
            
        return 1;
    }
}


    
