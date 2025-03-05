#include <stdio.h>
#include <stdlib.h>

void selectsort(int vetor[], int n){
  int i, j, menor, aux;
  for(i=0; i<n-1; i++){
    menor = i;
    for(j=i+1; j<n; j++){
      if(vetor[j] < vetor[menor])
        menor = j;
    }
    aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
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
  selectsort(vetor, n);
  printf("\nVetor ordenado: ");
  for(i=0;i<n;i++){
    printf("%i ",vetor[i]);
  }
}