#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dado;
    struct no* proximono;
}no;

typedef struct lista{
    struct no* head;
    int tamanho;
}lista;

no* criarno(int val);

int main(){
    lista lista1;
    lista1.head= criarno(10);
    inserirfinal(&lista1,20);
    return 0;
}

no* criarno(int val){
    no *novono = (no*)malloc(sizeof(no));
    novono->dado = val;
    novono->proximono=NULL;
    return novono;
}

void imprimirlista(lista *l){
    
    no *nop = l->head;
    printf("%d\n",l->head->dado);

    while(nop->proximono!=l->head){
        printf("%d\n",nop->dado);
    }
}

void inserifinal(lista *l,int val){
    no *novono = criarno(val);
    if(l->head!=NULL){
        no *nop = l->head;
        while(nop->proximono != l->head){
            nop = nop->proximono;
        }
        nop->proximono=novono;
        novono->proximono=l->head;
    }else{
        l->head = novono;
        novono->proximono = l->head;
    }
}
