#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#define INF 100000  // Definir um valor alto como "infinito"
#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct vertice {
  int chave;
  int dist;
  struct vertice *pred;
} VERTICE;

typedef struct adjacencia {
  int peso;
  struct vertice *vertice;
  struct adjacencia *prox;
} ADJACENCIA;

typedef struct grafo {
  int nVertices;
  int nArestas;
  VERTICE *vertices;
  ADJACENCIA **arestas;
} GRAFO;

GRAFO *criaGrafo(int n) {
  GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
  g->nVertices = n;
  g->nArestas = 0;
  g->vertices = (VERTICE *) malloc(n * sizeof(VERTICE));
  g->arestas = (ADJACENCIA **) malloc(n * sizeof(ADJACENCIA *));
  for (int i = 0; i < n; i++) {
    g->arestas[i] = NULL;
  }
  return g;
}

void criaVertice(GRAFO *g, int chave) {
  g->vertices[chave].chave = chave;
  g->vertices[chave].dist = INF;  // Inicializa a distância como infinito
  g->vertices[chave].pred = NULL;
}

void criaAdjacencia(GRAFO *g, int vi, int vf, int peso) {
  ADJACENCIA *t = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));
  t->peso = peso;
  t->vertice = &g->vertices[vf];
  t->prox = g->arestas[vi];
  g->arestas[vi] = t;
}

void criaAresta(GRAFO *g, int chave1, int chave2, int peso) {
  criaAdjacencia(g, chave1, chave2, peso);
  g->nArestas++;
}

void relax(GRAFO *g, VERTICE *u, VERTICE *v, int peso) {
  if (u->dist + peso < v->dist) {
    v->dist = u->dist + peso;
    v->pred = u;
  }
}

int peso(GRAFO *g, VERTICE *v1, VERTICE *v2) {
  int vi = v1->chave;
  ADJACENCIA *adj = g->arestas[vi];
  while (adj != NULL) {
    if (adj->vertice == v2) {
      return adj->peso;
    }
    adj = adj->prox;
  }
  return INF;
}

void bellman_ford(GRAFO *g, int vi) {
  g->vertices[vi].dist = 0;  // Define a distância da origem como 0
  for (int i = 1; i < g->nVertices; i++) {
    for (int u = 0; u < g->nVertices; u++) {
      ADJACENCIA *adj = g->arestas[u];
      while (adj != NULL) {
        relax(g, &g->vertices[u], adj->vertice, adj->peso);
        adj = adj->prox;
      }
    }
  }
}

int main() {
  GRAFO* grafo;
  int nv, na, vi, r;
  int chave1, chave2, peso;

  // Leitura de dados
  scanf("%i", &vi);
  scanf("%i", &r);
  scanf("%i %i", &nv, &na);

  grafo = criaGrafo(nv);

  // Inicializa os vértices
  for (int i = 0; i < nv; i++) {
    criaVertice(grafo, i);
  }

  // Criação das arestas
  for (int i = 0; i < na; i++) {
    scanf("%i %i %i", &chave1, &chave2, &peso);
    if (peso <= r) {
      criaAresta(grafo, chave1, chave2, peso);
    }
  }

  bellman_ford(grafo, vi);
  for (int i = 0; i < grafo->nVertices; i++) {
    if (grafo->vertices[i].dist == INF) {
    printf("INF ");
    } 
    else {
      printf("%i ", grafo->vertices[i].dist);
    }
  }
  printf("\n");

  return 0;
}

