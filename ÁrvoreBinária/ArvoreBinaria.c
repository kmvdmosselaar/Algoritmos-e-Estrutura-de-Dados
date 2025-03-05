#include "ArvoreBinaria.h"

int arvoreVazia(TipoArvore arvore){
  return arvore==NULL;
}

TipoArvore inicializaArvore(){
  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    destroiArvore(arvore->subArvoreEsq);
    destroiArvore(arvore->subArvoreDir);
    free(arvore);
  }
  return NULL;
}

TipoArvore instanciaArvore(char dado){
  TipoArvore arvore = (TipoArvore) malloc(sizeof(TipoNohArvore));
  arvore->subArvoreEsq = NULL;
  arvore->subArvoreDir = NULL;
  arvore->dado = dado;
  return arvore;
}

TipoArvore insereSubArvoreEsq(TipoArvore raiz,TipoArvore subArvoreEsq){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreEsq = subArvoreEsq;
    return raiz;
  }
  return NULL;
}

TipoArvore insereSubArvoreDir(TipoArvore raiz,TipoArvore subArvoreDir){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}

TipoArvore montaArvore(TipoArvore raiz,TipoArvore subArvoreEsq,TipoArvore subArvoreDir){
  if(!arvoreVazia(raiz)){
    raiz->subArvoreEsq = subArvoreEsq;
    raiz->subArvoreDir = subArvoreDir;
    return raiz;
  }
  return NULL;
}