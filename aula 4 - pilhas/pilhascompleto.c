#include<stdio.h>
#include<stdlib.h>

void Stack(int *pilhai,int tpl);
void push(int *v,int *topo,int val);
void pop(int *v,int *topo);
void isEmpty(int *topo,int tamMax);
void size(int *topo);

int main(){
    int *pilha;
    int referenciatopo=0;
    int tamanhodapilha=5;
    int *pilha2;

    printf("programa iniciado!\n");
    Stack(pilha,tamanhodapilha);
    Stack(pilha2,tamanhodapilha);
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


void Stack(int *pilhai,int tpl){       
pilhai = (int*)malloc(tpl*sizeof(int));
printf("pilha criada!\n");
}

void push(int *v,int *topo,int val){
    v[*topo]=val;
    *topo+=1;
    printf("valor adicionado!\n");
}

void pop(int *v,int *topo){
    printf("valor %d removido\n",v[*topo-1]);
    *topo+= -1;
}

void isEmpty(int *topo,int tamMax){
    if(*topo<tamMax){
        printf("%d espaco(s) livre(s)!\n",tamMax-*topo);
        return 0;
    }else{
        printf("pilha cheia");
        return 1;
    }

}

void size(int *topo){
printf("referencia topo:%d\n",*topo);
}