#include<stdio.h>
#include "pilhas.h"



int main(){
    int *pilha;
    int referenciatopo=0;
    int tamanhodapilha=5;


    printf("programa iniciado!\n");
    Stack(pilha,tamanhodapilha);

    push(pilha,&referenciatopo,10);
    push(pilha,&referenciatopo,20);
    push(pilha,&referenciatopo,30);
    push(pilha,&referenciatopo,40);
     push(pilha,&referenciatopo,10);
    push(pilha,&referenciatopo,20);
    push(pilha,&referenciatopo,30);
    push(pilha,&referenciatopo,40);
    pop(pilha,&referenciatopo);
    isEmpty(&referenciatopo,tamanhodapilha);
    size(&referenciatopo);
    
    for(int i=0;i <referenciatopo;i++){
        printf("pilha[%d] -> %d\n",i,pilha[i]);
    }
    
    return 0;
}