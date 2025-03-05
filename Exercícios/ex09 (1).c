#include <stdio.h>
#include <stdlib.h>

// NUza\LL vai ser menos 2
//  DELETED VAI SER -3

struct node {
  int data;
  struct node *next;
};

int hash(int k, int m) { 
  return (k % m); 
}

int insereHash(struct node **T, int k, int m) {
  int j;
  struct node *p;
  j = hash(k, m);
  p = T[j];
  if (p == (struct node *)NULL) {
    p = (struct node *)malloc(sizeof(struct node));
    T[j] = p;
    p->data = k;
    p->next = (struct node *)NULL;
  } else {
    while (p->next != (struct node *)NULL) {
      p = p->next;
    }
    p->next = (struct node *)malloc(sizeof(struct node));
    p = p->next;
    p->data = k;
    p->next = (struct node *)NULL;
  }
  return 1;
}

int removeHash(struct node **T, int k, int m) {
  int j;
  struct node *p, *q;
  j = hash(k, m);
  if (T[j] == (struct node *)NULL) {
    return 0;
  }
  p = T[j];
  if (p->data == k) {
    T[j] = p->next;
    free(p);
    return 1;
  }
  while ((p->next != (struct node *)NULL) && (p->next->data != k)) {
    p = p->next;
  }
  if ((p->next == (struct node *)NULL) || (p->next->data != k)) {
    return 0;
  }
  q = p->next;
  p->next = p->next->next;
  free(q);
  return 1;
}

void imprimeLinhaHash(struct node **T, int l) {
  struct node *p;
  printf("[%i]", l);
  p = T[l];
  while (p != (struct node *)NULL) {
    printf(" %i", p->data);
    p = p->next;
  }
  printf("\n");
}

int main() {
  struct node **T;
  int i = 0, x, k, m, l;
  scanf("%i", &m);
  T = (struct node **)malloc(m * sizeof(struct node *));
  for (i = 0; i < m; i++)
    T[i] = (struct node *)NULL;
  do {
    scanf("%i", &k);
    if (k >= 0) {
      insereHash(T, k, m);
    }
  } while (k != -1);
  scanf("%i", &x);
  if (removeHash(T, x, m) == 0) {
    printf("Valor nao encontrado\n");
  }
  scanf("%i", &l);
  imprimeLinhaHash(T, l);
  free(T);
}