//aula de pilhas
//LIFO(LAST IN,FIRST OUT)
//O PRIMEIRO A ENTRAR É O ULTIMO A SAIR
//PUSH() - PARA INSERIR ALGO
//POP() - PARA REMOVER ALGO DA PILHA
// !!!!SEMPRE É PRECISO TER ACESSO AO TOPO DA PILHA!!!!
//atividade:
//uma funcao pra criar;
//uma pra add;
//uma pra remover;
//uma pra verificar se está vazia;
//uma pra verificar se está cheia;


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