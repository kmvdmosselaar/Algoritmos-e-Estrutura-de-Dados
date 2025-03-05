//Katherine Mombach van den Mosselaar
//RA-163873

#include "LLED.h"

int insereNaPosicao(ListaLinearED* lista, TipoItem item, int posicao){
  TipoNoh *novoNoh, *ptrAux, *ptrAuxProx;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if((--posicao > 0)&&(!listaVaziaLLED(lista))){
      while((--posicao > 0)&&(ptrAux->prox != NULL))
        ptrAux = ptrAux->prox;
      ptrAuxProx = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      ptrAuxProx = lista->inicioLista;
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = ptrAuxProx;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int listaVaziaLLED(ListaLinearED *lista){
  return lista->ultimo==0;
}

void inicializaListaLLED(ListaLinearED *lista){
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void destroiListaLLED(ListaLinearED* lista){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    while(ptrAux1->prox != NULL){
      free(ptrAux1);
      ptrAux1 = ptrAux2;
      ptrAux2 = ptrAux1->prox;
    }
    free(ptrAux1);
  }
  lista->inicioLista = NULL;
  lista->ultimo = 0;
}

void imprimeItemLLED(TipoItem item){
  printf("%i %s %.1f %.1f %.1f %i\n",item.RA,item.nome,item.notas[0],item.notas[1],item.notas[2],item.freq);
}

void imprimeListaLLED(ListaLinearED *lista){
  TipoNoh *ptrAux;
  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    while(ptrAux != NULL){
      imprimeItemLLED(ptrAux->item);
      ptrAux = ptrAux->prox;
    }
  }
}

int insereNoFinalLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh, *ptrAux;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    ptrAux = lista->inicioLista;
    if(!listaVaziaLLED(lista)){
      while(ptrAux->prox != NULL)
        ptrAux = ptrAux->prox;
      ptrAux->prox = novoNoh;
    }
    else{
      lista->inicioLista = novoNoh;
    }
    novoNoh->item = item;
    novoNoh->prox = NULL;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int insereNoInicioLLED(ListaLinearED *lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
  if(novoNoh != NULL){
    novoNoh->item = item;
    novoNoh->prox = lista->inicioLista;
    lista->inicioLista = novoNoh;
    lista->ultimo++;
    return 1;
  }
  return 0;
}

int removeDoFinalLLED(ListaLinearED *lista,TipoItem *item){
    TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if(ptrAux2 == NULL){
      lista->inicioLista = NULL;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while(ptrAux2->prox != NULL){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = NULL;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int removeDoInicioLLED(ListaLinearED* lista,TipoItem* item){
  TipoNoh *ptrAux;

  if(!listaVaziaLLED(lista)){
    ptrAux = lista->inicioLista;
    lista->inicioLista = ptrAux->prox;
    *item = ptrAux->item;
    free(ptrAux);
    lista->ultimo--;
    return 1;
  }
  else
    return 0;
}
int retiraDaPosicao(ListaLinearED* lista, TipoItem* item, int posicao){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if((--posicao > 0)&&(ptrAux2 == NULL)){
      lista->inicioLista = ptrAux2;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while((--posicao > 0)&&(ptrAux2->prox != NULL)){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      ptrAux1->prox = ptrAux2->prox;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}
int retiraEspecifico(ListaLinearED* lista, TipoItem* item, int RA){
  TipoNoh *ptrAux1, *ptrAux2;
  if(!listaVaziaLLED(lista)){
    ptrAux1 = lista->inicioLista;
    ptrAux2 = ptrAux1->prox;
    if((ptrAux2 == NULL)||(ptrAux1->item.RA == RA)){
      if (ptrAux1->item.RA != RA){
        return 0;
      }
      lista->inicioLista = ptrAux2;
      *item = ptrAux1->item;
      free(ptrAux1);
    }
    else{
      while((ptrAux2->prox != NULL)&&(ptrAux2->item.RA != RA)){
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
      }
      if (ptrAux2->item.RA != RA){
        return 0;
      }
      ptrAux1->prox = ptrAux2->prox;
      *item = ptrAux2->item;
      free(ptrAux2);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}