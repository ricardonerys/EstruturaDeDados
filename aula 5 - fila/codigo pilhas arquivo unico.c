#include<stdio.h>

void criafila(int *vetor,int tf);
void enqueue(int *vetor,int *inp, int *inu,int t, int val);
int dequeue(int *vetor,int *inp, int *inu,int t);


int main(){
    int *fila;
    int ip=0;
    int iu=0;
    int tamanhofila=5;
    criafila(fila,tamanhofila);
    enqueue(fila,&ip,&iu,tamanhofila, 10);
    enqueue(fila,&ip,&iu,tamanhofila, 20);
    enqueue(fila,&ip,&iu,tamanhofila, 30);
    enqueue(fila,&ip,&iu,tamanhofila, 40);
    enqueue(fila,&ip,&iu,tamanhofila, 50);
    dequeue(fila,&ip,&iu,tamanhofila);
    dequeue(fila,&ip,&iu,tamanhofila);
    dequeue(fila,&ip,&iu,tamanhofila);
    return 0;
}

void criafila(int *vetor,int tf){
    vetor = (int*)malloc(tf*sizeof(int));
    printf("pilha criada!\n");
}

void enqueue(int *vetor,int *inp, int *inu,int t, int val){
    if(*inu == t){
        *inu = 0;
    }
     vetor[*inu]=val;
    *inu = *inu + 1;
    
    printf("valor adicionado a fila: %d\n",vetor[*inu-1]);
}


int dequeue(int *vetor,int *inp, int *inu,int t){
    if(*inp == t){
         *inp=0;
    }
     *inp = *inp + 1;
    printf("valor removido: %d\n",vetor[*inp-1]);
   
    return vetor[*inp-1];
}
