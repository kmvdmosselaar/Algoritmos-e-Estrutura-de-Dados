#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct vertice{
  char chave;
  int cor;
  int dist;
  struct vertice *pred;
} VERTICE;

typedef struct adjacencia{
  struct vertice *vertice;//ponteiro do vertice ao qual esta ligada a adjacencia(poderia ser apenas a chave) 
  struct adjacencia *prox;
} ADJACENCIA;

typedef struct grafo{
  int nVertices;
  int nArestas;
  VERTICE *vertices;//ponteiro para uma tabela de vertices
  ADJACENCIA **arestas;//ponteiro para uma tabela de ponteiro de adjacencias(lista de adjacencias)
} GRAFO;

typedef struct fila{
  int valor;
  struct fila *prox;
} FILA;

GRAFO *criaGrafo(int n){
  GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
  g->nVertices = n;
  g->nArestas = 0;
  g->vertices = (VERTICE *) malloc(n*sizeof(VERTICE));//aloca a memoria para a lista de vertices
  g->arestas = (ADJACENCIA **) malloc(n*sizeof(ADJACENCIA *));//aloca a memoria para a lista de ponteiros de adjacencias
  return (g);
}

void criaVertice(GRAFO *g, int v, char chave){
  g->vertices[v].chave = chave;
  g->vertices[v].cor = BRANCO;
  g->vertices[v].dist = -1;
  g->vertices[v].pred = NULL;
  g->arestas[v] = NULL;
}

int buscaVerice(GRAFO *g, char chave){//retorna o indice da lista de vertices que corresponde a chave
  int i;
  for (i = 0; i < g->nVertices; i++){
   if (g->vertices[i].chave == chave) {
     break;
   } 
  }
  return i;
}

void criaAdjacencia(GRAFO *g, int vi, int vf){
    ADJACENCIA *t;
    t = (ADJACENCIA *) malloc(sizeof(ADJACENCIA)); // Aloca memória para um novo nó de adjacência

    t->vertice = &g->vertices[vf]; // Define o vértice de destino como o vértice final da aresta
    t->prox = NULL; // Inicializa o ponteiro para o próximo nó como NULL, indicando o final da lista

    if (g->arestas[vi] == NULL){ // Verifica se a lista de adjacências do vértice inicial está vazia
        g->arestas[vi] = t; // Se estiver vazia, a nova adjacência se torna o primeiro elemento da lista
    }
    else{ 
        ADJACENCIA *p = g->arestas[vi]; // Ponteiro auxiliar para percorrer a lista de adjacências
        while (p->prox != NULL){ // Percorre até o final da lista de adjacências do vértice inicial
            p = p->prox; // Avança para o próximo nó na lista
        }
        p->prox = t; // Insere a nova adjacência no final da lista
    }
}


void criaAresta(GRAFO *g, char chave1, char chave2){
  int v1 = buscaVerice(g, chave1);
  if (v1 >= g->nVertices){
    printf("Vertice %c nao encontrado!\n",chave1);
    return;
  }
  int v2 = buscaVerice(g, chave2);
  if (v2 >= g->nVertices){
    printf("Vertice %c nao encontrado!\n",chave2);
    return;
  }
  criaAdjacencia(g, v1, v2); 
  criaAdjacencia(g, v2, v1); 
  g->nArestas++;
}

void imprimeGrafo (GRAFO* g){
  printf("Vertices: %i Arestas: %i.\n", g->nVertices, g->nArestas);
  for(int i=0;i<g->nVertices; i++){
    printf("v%d: %c >>", i, g->vertices[i].chave);
    ADJACENCIA * ad = g->arestas[i];
    while (ad){
      printf(" %c", ad->vertice->chave);//pq não ad->vertice.chave??
      ad = ad->prox;
    }
    printf("\n");
  }
}

void insereFila(FILA **f, int valor){
  FILA *p;
  if (*f == NULL){
    p = (FILA *) malloc(sizeof(FILA));
    p->valor = valor;
    p->prox = NULL;
    *f = p;
  }
  else {
    p = *f;
    while (p->prox != NULL){
      p = p->prox;
    }
    p->prox = (FILA *) malloc(sizeof(FILA));
    p = p->prox;
    p->valor = valor;
    p->prox = NULL;
  }
}

int removeFila(FILA **f){
  if (*f == NULL){
    return -1;
  }
  FILA *p;
  p = *f;
  int valor = p->valor;
  *f = p->prox;//*f aponta para proximo elemento da fila
  free(p);
  return valor;
}

void BFS(GRAFO *g, char s){
  FILA *f = NULL;
  int vs = buscaVerice(g, s);
  if (vs >= g->nVertices){
    printf("Vertice %c nao encontrado!\n",s);
    return;
  }
  g->vertices[vs].cor = CINZA;
  g->vertices[vs].dist = 0;
  g->vertices[vs].pred = NULL;
  insereFila(&f, vs);//pq manda o indice vs e nao o s?
  while(f != NULL){
    int vu = removeFila(&f);
    //printf("vu: %i\n",vu);
    ADJACENCIA *adj = g->arestas[vu];
    while (adj != NULL){
      int va = buscaVerice(g, adj->vertice->chave);
      //printf("va: %i\n",va);
      if (g->vertices[va].cor == BRANCO){
        g->vertices[va].cor = CINZA;
        g->vertices[va].dist = ((g->vertices[vu].dist>-1)?g->vertices[vu].dist:0)+1;
        g->vertices[va].pred = &g->vertices[vu];
        insereFila(&f,va);
      }
      adj = adj->prox;//percorre as adjacencias do vertice vu
    }
    g->vertices[vu].cor = PRETO;
  }
}

void imprimeBFS (GRAFO* g){
  printf("Vertices: %i Arestas: %i.\n", g->nVertices, g->nArestas);
  for(int i=0;i<g->nVertices; i++){
    printf("v%d: %c - dist: %i - pred: %c\n", i, 
              g->vertices[i].chave, 
              g->vertices[i].dist, 
              ((g->vertices[i].pred==NULL)?'-':g->vertices[i].pred->chave));
  }
}

int main(){
  GRAFO* grafo;
  int n, i;
  char chave, chave1, chave2;

  scanf("%i", &n);
  grafo = criaGrafo(n);
  
  for(i=0; i<n; i++){
    scanf("%c", &chave);
    if ((chave == '\r') || (chave == '\n') || (chave == ' ') || (chave == '\0')){
      i--;
      continue;
    }
    criaVertice(grafo, i, chave);
  }
  
  do{
    do{
      scanf("%c", &chave1);
    } while ((chave1 == '\r') || (chave1 == '\n') || (chave1 == '\0'));
    if (chave1 == ' '){
      break;
    }
    do{
      scanf("%c", &chave2);
    } while ((chave2 == '\r') || (chave2 == '\n') || (chave2 == ' ') || (chave2 == '\0'));
    criaAresta(grafo, chave1, chave2);
  } while (true);
  
  imprimeGrafo(grafo);
  
  BFS(grafo,'s');
  
  imprimeBFS(grafo);
}