#include <stdio.h>
#include <stdlib.h>

void quicksort(int vetor[], int tam) {
  int i, j, grupo, troca;
  if (tam < 2) {
    return;
  } 
  else {
    grupo = vetor[tam / 2];
  }
  for (i = 0, j = tam - 1;; i++, j--) {
    while (vetor[i] < grupo) {
      i++;
    }
    while (vetor[j] > grupo) {
      j--;
    }
    if (i >= j) {
      break;
    } 
    else {
      troca = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = troca;
    }
  }
  quicksort(vetor, i);
  quicksort(vetor + i, tam - i);
}

int main() {
  int n, i, *vetor;
  vetor = malloc(n * sizeof(int));
  printf("Digite o tamanho do vetor: ");
  scanf("%i", &n);
  printf("\nDigite o vetor: ");
  for (i = 0; i < n; i++) {
    scanf("%i", &vetor[i]);
  }
  quicksort(vetor, n);
  printf("\nVetor ordenado: ");
  for (i = 0; i < n; i++) {
    printf("%i ", vetor[i]);
  }
  printf("\n");
}