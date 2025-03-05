#include <stdio.h>
#include <stdlib.h>

struct nohArvore{
  char dado;
  struct nohArvore *subArvoreEsq;
  struct nohArvore *subArvoreDir;
};

typedef struct nohArvore TipoNohArvore;

typedef TipoNohArvore *TipoArvore;

int arvoreVazia(TipoArvore);
TipoArvore inicializaArvore();
TipoArvore destroiArvore(TipoArvore);
TipoArvore instanciaArvore(char);
TipoArvore insereSubArvoreEsq(TipoArvore,TipoArvore);
TipoArvore insereSubArvoreDir(TipoArvore,TipoArvore);
TipoArvore montaArvore(TipoArvore,TipoArvore,TipoArvore);
void imprimeArvorePreOrdem(TipoArvore);
void imprimeArvoreEmOrdem(TipoArvore);
void imprimeArvorePosOrdem(TipoArvore);