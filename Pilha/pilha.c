//Katherine Mosselaar 163873

#include "pilha.h"

TipoPilha inicializaPilha(TipoPilha pilha){
  return NULL;  
}

TipoPilha destroiPilha(TipoPilha pilha){
  TipoNoh *ptrAux;
  while(pilha!=NULL){
    ptrAux = pilha;
    pilha = pilha->prox;
    free(ptrAux);
  }
  return NULL;
}

int pilhaVazia(TipoPilha pilha){
  return pilha==NULL;
}

TipoPilha empilha(TipoPilha pilha,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = pilha;
  return novoNoh;
}

TipoPilha desempilha(TipoPilha pilha,TipoItem *item){
  TipoNoh *ptrAux;
  if(!pilhaVazia(pilha)){
    ptrAux = pilha;
    pilha = ptrAux->prox;
    *item = ptrAux->item;
    free(ptrAux);
    return pilha;
  }
  return NULL;
}

void imprimePilha(TipoPilha pilha){
  TipoNoh *ptrAux;
  ptrAux = pilha;
  while(ptrAux!=NULL){
    imprimeItem(ptrAux->item);
    ptrAux = ptrAux->prox;
  }
}

void imprimeItem(TipoItem item){
  printf("%c\n",item.caracter);
}