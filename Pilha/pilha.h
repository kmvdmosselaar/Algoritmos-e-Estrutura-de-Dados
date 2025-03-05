//Katherine Mosselaar 163873

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char caracter;
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef TipoNoh *TipoPilha;

TipoPilha inicializaPilha(TipoPilha);
TipoPilha destroiPilha(TipoPilha);
int pilhaVazia(TipoPilha);
TipoPilha empilha(TipoPilha,TipoItem);
TipoPilha desempilha(TipoPilha,TipoItem*);
void imprimePilha(TipoPilha);
void imprimeItem(TipoItem);