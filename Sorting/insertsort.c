#include <stdio.h>
#include <stdlib.h>

void insertsort(int vetor[], int n){
  int k, j, aux;
   for (k = 1; k < n; k++){
      aux = vetor[k];
      j = k - 1;
      while (j >= 0 && aux < vetor[j]) {
         vetor[j+1] = vetor[j];
         j--;
      }
      vetor[j+1] = aux;
   }
}

int main(){
  int n, i, *vetor;
  vetor = malloc(n * sizeof(int));
  printf("Digite o tamanho do vetor: ");
  scanf("%i",&n);
  printf("\nDigite o vetor: ");
  for(i=0;i<n;i++){
    scanf("%i",&vetor[i]);
  }
  insertsort(vetor, n);
  printf("\nVetor ordenado: ");
  for(i=0;i<n;i++){
    printf("%i ",vetor[i]);
  }
}