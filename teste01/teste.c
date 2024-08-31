#include <stdio.h>

#define TAMMAX 10

void alterar(int *v,int t);

int main(){
    int vetor[TAMMAX];
    for(int i=0; i < TAMMAX;i++){
        vetor[i]=i;
    }

    alterar(vetor,TAMMAX);

    printf("hello\n");
    for(int i=0; i < TAMMAX;i++){
        printf("%d",vetor[i]);
    }
    return 0;
}



void alterar(int *v,int t){

    for(int i=0; i < t;i++){
        v[i]=20;
    }

}