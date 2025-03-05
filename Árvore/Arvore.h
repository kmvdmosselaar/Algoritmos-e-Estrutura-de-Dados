#include <stdio.h>
#include <stdlib.h>

struct nohLista{
  struct nohArvore *item;//item da lista é um ponteiro para o nó da árvore, ou seja, é uma árvore
  struct nohLista *prox;
};

struct nohArvore{
  char dado;
  struct nohLista *listaFilhos;//ponteiro para o nó da lista
};

typedef struct nohArvore *TipoItem;

typedef struct nohLista TipoNoh;

typedef TipoNoh *TipoLista;

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;//tipoarvore é um ponteiro para um nó da árvore

//Funções Lista
int listaVazia(TipoLista);
TipoLista inicializaLista(TipoLista); 
TipoLista destroiLista(TipoLista);
TipoLista insereNoFinal(TipoLista,TipoItem);
TipoLista insereNoInicio(TipoLista,TipoItem);
TipoLista removeDoFinal(TipoLista,TipoItem*);
TipoLista removeDoInicio(TipoLista,TipoItem*);
void imprimeLista(TipoLista,int);


//Funções Árvore
int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore(TipoArvore); 
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(TipoArvore,char);//cria um nó e passa o dado
TipoArvore insereNaArvore(TipoArvore,TipoArvore);
void imprimeArvore(TipoArvore,int);