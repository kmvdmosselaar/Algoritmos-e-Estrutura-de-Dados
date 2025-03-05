//Katherine Mosselaar 163873

typedef struct pilha Pilha;

Pilha * criar();
void destruir(Pilha * p);
int desempilhar(Pilha * p); 
void empilhar(Pilha * p, int x); 
int tamanho(Pilha * p);
int topo(Pilha * p);
void imprimir(Pilha * p);
void inverter3(Pilha * p);