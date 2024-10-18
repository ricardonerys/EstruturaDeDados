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
void imprimirlista(lista *l);
void inserifinal(lista *l,int val);

int main(){
    lista lista1;
    lista1.head = NULL;
    lista1.tamanho = 0;
    
    lista1.head= criarno(10);
    inserirfinal(&lista1,20);
    imprimirlista(&lista1);
    return 0;
}

no* criarno(int val){
    no *novono = (no*)malloc(sizeof(no));
    novono->dado = val;
    novono->proximono=NULL;
    return novono;
}

void imprimirlista(lista *l){
    
   

    if(l->head != NULL){
        no *nop = l->head;
        printf("%d\n",nop->dado);
        while(nop->proximono!=l->head && nop->proximono!=NULL){
        }
    }else{
        printf("lista vazia!\n");
    }
}

void inserirfinal(lista *l,int val){
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
