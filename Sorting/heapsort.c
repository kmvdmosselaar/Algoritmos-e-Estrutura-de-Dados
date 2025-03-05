#include<stdio.h>
#include <stdlib.h>

void cria_heap(int vetor[], int inicio, int fim){
  int pai=vetor[inicio];
  int filho=inicio*2+1;
  while(filho<=fim){
    if(filho<fim){
      if (vetor[filho+1]>vetor[filho])
        filho=filho+1;
    }
    //O filho é maior que o pai? Se sim o filho se torna pai
    if (vetor[filho]>pai){
      vetor[inicio]=vetor[filho];
      inicio=filho;
      filho=2*inicio+1;
    }
    else
      filho=fim+1;
  }
  //O antigo pai ocupa o lugar do ultimo filho analisado
  vetor[inicio]=pai;
}

void heap_sort(int vetor[], int tam){
  int troca;
  int meio=(tam-1)/2;
  for(int i=meio;i>=0;i--){
    cria_heap(vetor,i,tam-1);
    printf("a)%i: ",i);
    for (int j = 0; j < tam; j++) {
      printf("%i ", vetor[j]);
    }
    printf("\n");
  }
  for(int i=tam-1;i>=1;i--){
    //Pega maior elemento da heap e coloca na sua posicao correspondente no vetor
    troca=vetor[0];
    vetor[0]=vetor[i];
    vetor[i]=troca;

    //reconstroi o heap
    cria_heap(vetor,0,i-1);
    printf("b)%i: ",i);
    for (int j = 0; j < tam; j++) {
      printf("%i ", vetor[j]);
    }
    printf("\n");
  }
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
  heap_sort(vetor, n);
  printf("\nVetor ordenado: ");
  for (i = 0; i < n; i++) {
    printf("%i ", vetor[i]);
  }
  printf("\n");
}