//Katherine Mosselaar 163873

#include "mEsp.h"

void inicializaMatriz(TipoMatriz *mat){
  mat->matriz = NULL;
  mat->nColunas = 0;
  mat->nLinhas = 0;
}

int matrizVazia(TipoMatriz *mat){
  return mat->matriz==NULL;  
}

int instanciaMatriz(TipoMatriz *mat,int linhas,int colunas){
  int i;
  mat->matriz = (TipoLista*) malloc(linhas*sizeof(TipoLista));
  if(mat->matriz!=NULL){
    mat->nLinhas = linhas;
    mat->nColunas = colunas;
    for(i=0;i<linhas;i++){
      mat->matriz[i] = inicializaLista(mat->matriz[i]);
    }
    return 1;
  }
  return 0;
}

void destroiMatriz(TipoMatriz *mat){
  int i;
  for(i=0;i<mat->nLinhas;i++){
    mat->matriz[i] = destroiLista(mat->matriz[i]);
  }
  free(mat->matriz);
}

int insereNaMatriz(TipoMatriz *mat,int linha,int coluna,int elemento){
  TipoItem item;
  item.coluna = coluna;
  item.elemento = elemento;
  mat->matriz[linha] = insereNoFinal(mat->matriz[linha],item);
}

int retiraDaMatriz(TipoMatriz *mat,int linha,int coluna,int *elemento){
  int cont=0;
  TipoNoh *ptrAux;
  ptrAux = mat->matriz[linha];
  while(ptrAux->item.coluna<coluna){
    ptrAux = ptrAux->prox;
    cont++;
  }
  if(ptrAux->item.coluna == coluna){
    elemento = ptrAux->item.coluna;
    return 1;
  }
  else
    return 0; 
}


void imprimeMatriz(TipoMatriz *mat){
  int i, cont=0;
  TipoNoh *ptrAux1, *ptrAux2;
  ptrAux1 = (TipoNoh *) malloc(sizeof(TipoNoh));
  ptrAux2 = (TipoNoh *) malloc(sizeof(TipoNoh));
  
  for(i=0;i<mat->nLinhas;i++){
    ptrAux1 = mat->matriz[i];
    if(ptrAux1==NULL){
      for(cont=0; cont<mat->nColunas; cont++){
          printf("0\t");
        }
      printf("\n");
      continue;
    }
    ptrAux2 = ptrAux1->prox;
    if(ptrAux1->item.coluna !=1){
      while(cont < ptrAux1->item.coluna){
        printf("0\t");
        cont++;
      }
    }
      imprimeItem(ptrAux1->item);
      while((ptrAux2!=NULL)&&(ptrAux1->item.coluna<ptrAux2->item.coluna)){
        for(cont=0; cont<ptrAux2->item.coluna; cont++){
          printf("0\t");
        }
        ptrAux1 = ptrAux2;
        ptrAux2 = ptrAux2->prox;
        imprimeItem(ptrAux1->item);
      }
      if(ptrAux1->item.coluna < mat->nColunas){
        for(cont=ptrAux1->item.coluna; cont<mat->nColunas; cont++){
          printf("0\t");
        }
      }
      printf("\n");
    }
  }
