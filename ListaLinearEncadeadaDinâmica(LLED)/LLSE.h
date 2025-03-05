//Katherine Mombach van den Mosselaar
//RA-163873

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
  int chave;
  char nome[50];
} TipoItem;

typedef struct{
  TipoItem itens[MAX];
  int ultimo;
} ListaLinearSE;

int listaVaziaLLSE(ListaLinearSE*);
int listaCheiaLLSE(ListaLinearSE*);
void inicializaLLSE(ListaLinearSE*);
void destroiListaLLSE(ListaLinearSE*);
void imprimeMenu();
void inicializaLLSE(ListaLinearSE*);
void imprimeItem(TipoItem *);
void imprimeListaLLSE(ListaLinearSE*);
int insereNoFinalLLSE(ListaLinearSE*,TipoItem);
int removeDoFinalLLSE(ListaLinearSE*,TipoItem*);
int removeDoComecoLLSE(ListaLinearSE*,TipoItem*);
int insereNaPosicao(ListaLinearSE* , TipoItem*, int);
int retiraDaPosicao(ListaLinearSE*, int);
int retiraEspecifico(ListaLinearSE*, int);