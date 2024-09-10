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

    
    return 0;
}


void inseririnicio(le* l,int val){
   
    no *novono=(no*)malloc(sizeof(no));
    novono->valor = val;
    novono->proximoNo = l->head;
    l->head=novono;
    

}