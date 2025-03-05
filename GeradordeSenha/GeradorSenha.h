//Katherine Mosselaar
//RA-163873

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int senha;
  int i;
  char nome[30];
} TipoItem;

struct noh{
  TipoItem item;
  struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
  TipoNoh *inicioFila;
  int ultimo;
  int senha;
} Fila;

void iniciaFila(Fila*);
int filaVazia(Fila*);
int insereFila(Fila*, TipoItem);
void chamada(Fila*, TipoItem*);
int removeDoInicio(Fila* , TipoItem*);