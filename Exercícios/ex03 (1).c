#include <stdio.h>
#include <stdlib.h>
struct elemento{
  int chave;
  struct elemento *prox;
};
struct tipoLista{
  struct elemento *primeiro;
  struct elemento *ultimo;
  int tamanho;
};
typedef struct elemento elemento;
typedef struct tipoLista tipoLista;

void desaloca(elemento *elemento){
  if(elemento->prox==NULL)
    free(elemento);

else
  desaloca(elemento->prox);
}

void inicializar(tipoLista *listaAux){
  listaAux->primeiro=NULL;
  listaAux->ultimo=NULL;
  listaAux->tamanho = 0;
}
void adicionarElemento(tipoLista *listaAux,int chave){
  elemento *novo;
  novo = malloc(sizeof(elemento));
  novo->chave=chave;
  if(listaAux->tamanho==0)
    listaAux->primeiro=novo;
  else{
    listaAux->ultimo->prox=novo;
  }
  listaAux->ultimo=novo;
  listaAux->tamanho++;
}

void printarLista(tipoLista *listaAux){
  elemento *aux;
  aux=listaAux->primeiro;
  while(aux!=NULL){
    printf("%d ",aux->chave);
    aux=aux->prox;
  }
  printf("\n");
}
elemento *divide(elemento *lista){
  elemento *p1=lista;
  elemento *p2=lista;
  elemento *lista2;
  if(lista==NULL)
    return lista;
  while(p1->prox!=NULL && p1->prox->prox!=NULL){
    p1=p1->prox->prox;
    p2=p2->prox;
  }
  lista2=p2->prox;
  p2->prox=NULL;
  return lista2;
}
elemento *merge(elemento *lista1, elemento *lista2){
  if(lista1==NULL){
    return lista2;
  }
  if(lista2==NULL){
    return lista1;
  }
  if(lista1->chave < lista2->chave){
    lista1->prox=merge(lista1->prox,lista2);
    return lista1;
  }
  else{
    lista2->prox=merge(lista1,lista2->prox);
    return lista2;
  }
}

elemento *mergeSort(elemento *lista1){
  elemento *lista2;
  if(lista1->prox == NULL)
    return lista1;
  else{
    lista2=divide(lista1);
    lista1=mergeSort(lista1);
    lista2=mergeSort(lista2);
    return merge(lista1,lista2);
  }
}

void contarProfundidade(int operacoes, int *contador){
  //int contador;
  while(operacoes!=0){
    operacoes = operacoes/2;
    (*contador)++;
  }
}

int main(void) {
  tipoLista *lista, *listaOrdenada;
  int operacoes, chave,i, contador;
  contador = 0;
  lista = malloc(sizeof(tipoLista));
  listaOrdenada = malloc(sizeof(tipoLista));
  inicializar(lista);
  scanf("%d",&operacoes);
  for(i=0;i<operacoes;i++){
    scanf("%d",&chave);
    adicionarElemento(lista,chave);
  }
  listaOrdenada->primeiro = mergeSort(lista->primeiro);
  printarLista(listaOrdenada);
  contarProfundidade(operacoes,&contador);
  printf("%d",contador);
  desaloca(lista->primeiro);
  desaloca(listaOrdenada->primeiro);
  return 0;
}