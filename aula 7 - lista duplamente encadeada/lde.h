typedef struct No no;

typedef struct listaencadeada le;

void inseririnicio(le *l,int val);
void inserirfim(le *l,int val);
void inserirmeio(le *l,int val,int ref);
void removerno(le *l,int ref);
int imprimirLista(le *l);