//Katherine Mosselaar
//RA-163873

#include "GeradorSenha.h"

int filaVazia(Fila *fila){
  return fila->ultimo==0;
}

void iniciaFila(Fila *fila){
  fila->inicioFila = NULL;
  fila->ultimo = 0;
  fila->senha=0;
}

int insereFila(Fila *fila, TipoItem item){
    TipoNoh *novoNoh, *ptrAux, *ptrAuxProx;
    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    if(novoNoh == NULL) 
      return 0;
    if(filaVazia(fila)){
      novoNoh->prox = fila->inicioFila;
      fila->inicioFila = novoNoh;
      fila->ultimo++;
      fila->senha++;        
      item.senha=fila->senha;
      novoNoh->item = item;
      return 1;
    }
    if(item.i==1){
      ptrAux = NULL;
      ptrAuxProx = fila->inicioFila;
      while((ptrAuxProx->item.i==1)&&(ptrAuxProx->prox != NULL)){
        ptrAux = ptrAuxProx;
        ptrAuxProx = ptrAuxProx->prox;
      }
      while((rand()%10<4)&&(ptrAuxProx->prox != NULL)){
        ptrAux = ptrAuxProx;
        ptrAuxProx = ptrAuxProx->prox;
      }
      if(ptrAux == NULL)
        fila->inicioFila = novoNoh;
      else
        ptrAux->prox = novoNoh;
      novoNoh->prox = ptrAuxProx;
      fila->ultimo++;
      fila->senha++;
      item.senha=fila->senha;
      novoNoh->item = item;
      return 1;
    }
    ptrAux = fila->inicioFila;
    while(ptrAux->prox != NULL)
      ptrAux = ptrAux->prox;
    ptrAux->prox = novoNoh;
    novoNoh->prox = NULL;
    fila->ultimo++;
    fila->senha++;
    item.senha=fila->senha;
    novoNoh->item = item;
    return 1;
  }

int removeDoInicio(Fila* fila, TipoItem* item){
  TipoNoh *ptrAux;

  if(!filaVazia(fila)){
    ptrAux = fila->inicioFila;
    fila->inicioFila = ptrAux->prox;
    *item = ptrAux->item;
    free(ptrAux);
    fila->ultimo--;
    return 1;
  }
  else
    return 0;
}

void chamada(Fila *fila, TipoItem *item){
  if(removeDoInicio(fila, item)>0)
    printf("Senha: %i\nNome: %s",item->senha, item->nome); 
  else
    printf("Não foi possível realizar a chamada.");
}
