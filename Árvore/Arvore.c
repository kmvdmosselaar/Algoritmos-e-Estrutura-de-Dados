#include "Arvore.h"

//Funções Lista
int listaVazia(TipoLista lista){
  return lista==NULL;
}

TipoLista inicializaLista(TipoLista lista){
  return NULL;
}

TipoLista destroiLista(TipoLista lista){//é recursiva
  TipoNoh *ptrAux;
  if(lista!=NULL){
    lista->prox = destroiLista(lista->prox);
    destroiArvore(lista->item);
  }
  return NULL;
}

TipoLista insereNoFinal(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  if(lista==NULL){
    novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
    novoNoh->item = item;
    novoNoh->prox = NULL;
    return novoNoh;
  }
  else{
    lista->prox = insereNoFinal(lista->prox,item);
    return lista;
  }
}

TipoLista insereNoInicio(TipoLista lista,TipoItem item){
  TipoNoh *novoNoh;
  novoNoh = (TipoNoh *) malloc(sizeof(TipoNoh));
  novoNoh->item = item;
  novoNoh->prox = lista;
  return novoNoh;
}

TipoLista removeDoFinal(TipoLista lista,TipoItem *item){
  if(lista!=NULL){
    if(lista->prox==NULL){
      *item = lista->item;
      free(lista);
      return NULL;
    }
    else{
      lista->prox = removeDoFinal(lista->prox,item);
      return lista;
    }
  }
  return NULL;
}

TipoLista removeDoInicio(TipoLista lista,TipoItem *item){
  TipoNoh *ptrAux;
  if(lista!=NULL){
    ptrAux = lista;
    lista = lista->prox;
    *item = ptrAux->item;
    free(ptrAux);
    return lista;
  }
  return NULL;
}

void imprimeLista(TipoLista lista,int n){
  if(lista!=NULL){
    imprimeArvore(lista->item,n);//item do primeiro nó quando o imprime arvore recebe n=0, o imprime lista receberá n=1
    imprimeLista(lista->prox,n);
  }
}


//Funções da Árvore
int arvoreVazia(TipoArvore arvore){//pq return null?? pq isso significa que ela está vazia se esta retornando?
  return arvore==NULL;
}

TipoArvore inicializaArvore(TipoArvore arvore){//atribuindo null ao ponteiro nó árvore, que é o primeiro ponteiro, aponta para A
  return NULL;
}

TipoArvore destroiArvore(TipoArvore arvore){
  if(!arvoreVazia(arvore)){
    arvore->listaFilhos = destroiLista(arvore->listaFilhos);
    printf("Destruindo %c\n",arvore->dado);
    free(arvore);
  }
  return NULL;
}

TipoArvore instanciaArvore(TipoArvore arvore,char dado){//cria uma nova arvore
  arvore = (TipoArvore) malloc(sizeof(TipoNohArvore));//ALOCA O NÓ DA ÁTVORE
  arvore->dado = dado;
  arvore->listaFilhos = inicializaLista(arvore->listaFilhos);// cria uma lista de filhos vazia
  return arvore;// retorna ponteiro para o nó criado, da lista vazia
}

TipoArvore insereNaArvore(TipoArvore pai,TipoArvore filho){
  TipoItem item;//declara o item, um ponteiro para o nó da arvore
  item = filho;//ponteiro para o nó da arvore recebe o filho
  pai->listaFilhos = insereNoFinal(pai->listaFilhos,item);
  return pai;
}

void imprimeArvore(TipoArvore arvore,int n){//n é o nível da árvore
  int i;
  if(!arvoreVazia(arvore)){
    for(i=0;i<n;i++){//a raiz não terá o tab, pois o n=0, não entra no for
      printf("\t");
    }
    printf("%c\n",arvore->dado);//imprime o dado
    imprimeLista(arvore->listaFilhos,n+1);//filhos estão no nível mais um do pai
  }
}