#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct vertice{
  int chave;
  int cor;
  int dist;
  int d;
  int f;
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
  g->nVertices = 0;
  g->nArestas = 0;
  g->vertices = (VERTICE *) malloc(n*sizeof(VERTICE));//aloca a memoria para a lista de vertices
  g->arestas = (ADJACENCIA **) malloc(n*sizeof(ADJACENCIA *));//aloca a memoria para a lista de ponteiros de adjacencias
  return (g);
}

void criaVertice(GRAFO *g, int chave){
  g->vertices[g->nVertices].chave = chave;
  g->vertices[g->nVertices].cor = BRANCO;
  g->vertices[g->nVertices].dist = -1;
  g->vertices[g->nVertices].pred = NULL;
  g->arestas[g->nVertices] = NULL;
  g->nVertices++;
}

int buscaVertice(GRAFO *g, int chave){//retorna o indice da lista de vertices que corresponde a chave
  int i;
  for (i = 0; i < g->nVertices; i++){
   if (g->vertices[i].chave == chave) {
     break;
   } 
  }
  return i;
}

void criaAdjacencia(GRAFO *g, int vi, int vf){
    int chave;
    ADJACENCIA *t;
    chave = g->vertices[vf].chave;
    t = (ADJACENCIA *) malloc(sizeof(ADJACENCIA)); // Aloca memória para um novo nó de adjacência

    t->vertice = &g->vertices[vf]; // Define o vértice de destino como o vértice final da aresta
    t->prox = NULL; // Inicializa o ponteiro para o próximo nó como NULL, indicando o final da lista

    if ((g->arestas[vi] == NULL) || (g->arestas[vi]->vertice->chave > chave)){ // Verifica se a lista de adjacências do vértice inicial está vazia
        t->prox = g->arestas[vi];
        g->arestas[vi] = t; // Se estiver vazia, a nova adjacência se torna o primeiro elemento da lista
    }
    else{ 
        ADJACENCIA *p = g->arestas[vi]; // Ponteiro auxiliar para percorrer a lista de adjacências
        while ((p->prox != NULL) && (p->prox->vertice->chave < chave)){ // Percorre até o final da lista de adjacências do vértice inicial
            p = p->prox; // Avança para o próximo nó na lista
        }
        t->prox = p->prox;
        p->prox = t; // Insere a nova adjacência no final da lista
    }
}


void criaAresta(GRAFO *g, int chave1, int chave2){
  int v1 = buscaVertice(g, chave1);
  int v2 = buscaVertice(g, chave2);
  criaAdjacencia(g, v1, v2); 
  g->nArestas++;
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


void BFS(GRAFO *g, int vi){
  FILA *f = NULL;
  int vs = buscaVertice(g, vi);
  g->vertices[vs].cor = CINZA;
  g->vertices[vs].dist = 0;
  g->vertices[vs].pred = NULL;
  insereFila(&f, vs);//pq manda o indice vs e nao o s?
  while(f != NULL){
    int vu = removeFila(&f);
    printf("%i ", g->vertices[vu].chave);
    ADJACENCIA *adj = g->arestas[vu];
    while (adj != NULL){
      int va = buscaVertice(g, adj->vertice->chave);
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

void DFS_Visit(GRAFO *g, VERTICE *u, int *tempo) {
  (*tempo) = (*tempo) + 1; // Incrementa o tempo
  u->d = *tempo; // Atualiza o tempo de descoberta
  u->cor = CINZA; // Pinta v de cinza (descoberto)
  printf("%i ", u->chave);

  int vu = buscaVertice(g, u->chave);
  ADJACENCIA *adj = g->arestas[vu];

  while (adj != NULL) {
      VERTICE *v = adj->vertice;
      if (v->cor == BRANCO) { // Verifica se v não foi visitado
          v->pred = u; // Atualiza o predecessor
          DFS_Visit(g, v, tempo); // Chama recursivamente DFS-Visit em v
      }
      adj = adj->prox; // Avança para a próxima adjacência
  }

  u->cor = PRETO; // Pinta u de preto (não há mais vizinhos para serem descobertos)
  (*tempo) = (*tempo) + 1; // Incrementa o tempo
  u->f = *tempo; // Atualiza o tempo final
}

void DFS(GRAFO *g) {
  int i;
  int tempo = 0; // Inicializa o contador de tempo

  for (i = 0; i < g->nVertices; i++) {
      g->vertices[i].cor = BRANCO; // Pinta todos os nós de BRANCO
      g->vertices[i].pred = NULL; // Predecessor de todos os “u” para NIL
  }

  for (i = 0; i < g->nVertices; i++) {
      if (g->vertices[i].cor == BRANCO) { // Verifica se “u” não foi visitado
          DFS_Visit(g, &g->vertices[i], &tempo); // Chama DFS-Visit em “u”
      }
  }
}


int main(){
  GRAFO* grafo;
  int nv, na, i, j, vi;
  int chave1, chave2, cont1, cont2;;

  scanf("%i", &vi);
  scanf("%i %i", &nv,&na);
  grafo = criaGrafo(nv);
  criaVertice(grafo, vi);
  
  for(i=0; i<na; i++){
    scanf("%i %i", &chave1,&chave2);
    cont1=0;
    cont2=0;
    for(j=0; j<grafo->nVertices; j++){
      if(grafo->vertices[j].chave == chave1){
        cont1++;
      }
      if(grafo->vertices[j].chave == chave2){
        cont2++;
      }
    }
    if(cont1==0)
      criaVertice(grafo, chave1);
    if(cont2==0)
      criaVertice(grafo, chave2);
    criaAresta(grafo, chave1, chave2);
  }


  BFS(grafo,vi);
  printf("\n");
  DFS(grafo);
  printf("\n");
}