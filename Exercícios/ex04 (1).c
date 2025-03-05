#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int particiona(int vetor[], int inicio, int fim) {
  int pivo = vetor[fim];
  int i = inicio - 1;

  for (int j = inicio; j <= fim - 1; j++) {
    if (vetor[j] <= pivo) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }
  i++;
  troca(&vetor[i], &vetor[fim]);
  return i;
}

void quickSort(int vetor[], int inicio, int fim, int *p) {
  int p1, p2;
  if (inicio < fim) {
    int pivo = particiona(vetor, inicio, fim);
    (*p)++;
    p1 = *p;
    quickSort(vetor, inicio, pivo - 1, &p1);
    p2 = *p;
    quickSort(vetor, pivo + 1, fim, &p2);
    *p = (p1 > p2) ? p1 : p2;
  }
}

int particiona_med(int vetor[], int inicio, int fim) {
  int pivo;
  int vi = vetor[inicio];
  int vm = vetor[(inicio + fim + 1) / 2];
  int vf = vetor[fim];
  if ((vi < vm) && (vi > vf))
    pivo = inicio;
  else if ((vi > vm) && (vi < vf))
    pivo = inicio;
  else if ((vf < vm) && (vf > vi))
    pivo = fim;
  else if ((vf > vm) && (vf < vi))
    pivo = fim;
  else
    pivo = (inicio + fim + 1) / 2;
  troca(&vetor[pivo], &vetor[fim]);
  pivo = vetor[fim];
  int i = inicio - 1;
  for (int j = inicio; j <= fim - 1; j++) {
    if (vetor[j] <= pivo) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }
  i++;
  troca(&vetor[i], &vetor[fim]);
  return i;
}

void quickSort_med(int vetor[], int inicio, int fim, int *p) {
  if (inicio < fim) {
    int pivo = particiona_med(vetor, inicio, fim);
    (*p)++;
    int p1 = *p;
    quickSort_med(vetor, inicio, pivo - 1, &p1);
    int p2 = *p;
    quickSort_med(vetor, pivo + 1, fim, &p2);
    *p = (p1 > p2) ? p1 : p2;
  }
}

int main() {
  int *vetor, *vetor_med;
  int n, i, p, p_med;

  scanf("%i", &n);
  vetor = malloc(n * sizeof(int));
  vetor_med = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    scanf("%i", &vetor[i]);
    vetor_med[i] = vetor[i];
  }

  p = -1;
  quickSort(vetor, 0, n - 1, &p);

  // for (i = 0; i < n; i++) {
  //   printf("%i ", vetor[i]);
  // }
  // printf("\n");

  printf("%i\n", p);

  p_med = -1;
  quickSort_med(vetor_med, 0, n - 1, &p_med);

  // for (i = 0; i < n; i++) {
  //   printf("%i ", vetor_med[i]);
  // }
  // printf("\n");

  printf("%i\n", p_med);

  return 0;
}