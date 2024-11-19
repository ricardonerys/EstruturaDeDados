#define CAPACIDADE 10
#include <stdio.h>

typedef struct No{
int chave;
int valor;
struct No* proximono;
}no;

no* tabelahash[CAPACIDADE];
    
int funcaohash(int chave){
    return chave % CAPACIDADE;
}

void inicializatabelahash(){
    for(int i;i<CAPACIDADE;i++){
        tabelahash[i] = NULL;
    }
}
void inserir(int chave ,int valor){
    int indice = funcaohash(chave);
    no* novono = (no*)malloc(sizeof(no));
    novono ->chave = chave;
    novono ->valor = valor;
    novono -> proximono = tabelahash[indice];
    tabelahash[indice] = novono;
}

void imprimir(){
    
}