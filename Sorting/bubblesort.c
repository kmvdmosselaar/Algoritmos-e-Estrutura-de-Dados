#include <stdio.h>
#include <stdlib.h>

void bubblesort(int vetor[],int tam){
  int proximo=0,i,j;
  for(i=0;i<tam;i++){
    for(j=0;j<(tam-1-i);j++){
      if(vetor[j]>vetor[j+1]){
        proximo=vetor[j];
        vetor[j]=vetor[j+1];
        vetor[j+1]=proximo;
      }
    }
  }
}

int main(){
  int n, i, *vetor;
  vetor = malloc(n * sizeof(int));
  printf("Digite o tamanho do vetor: ");
  scanf("%i", &n);
  printf("\nDigite o vetor: ");
  for (i = 0; i < n; i++) {
    scanf("%i", &vetor[i]);
  }
  bubblesort(vetor, n);
  printf("\nVetor ordenado: ");
  for (i = 0; i < n; i++) {
    printf("%i ", vetor[i]);
  }
  printf("\n");
  return 0;
}