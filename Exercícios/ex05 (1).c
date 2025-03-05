#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void cria_heap(char* vetor[], int inicio, int fim){
  char* pai=vetor[inicio];
  int filho=inicio*2+1;
  while(filho<=fim){
    if(filho<fim){
      if (strcmp(vetor[filho+1],vetor[filho]) > 0)
        filho=filho+1;
    }
    //O filho é maior que o pai? Se sim o filho se torna pai
    if (strcmp(vetor[filho],pai) > 0){
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

void heap_sort(char* vetor[], int tam){
  char* troca;
  int meio=(tam-1)/2;
  for(int i=meio;i>=0;i--){
    cria_heap(vetor,i,tam-1);
  }
  for(int i=tam-1;i>=1;i--){
    //Pega maior elemento da heap e coloca na sua posicao correspondente no vetor
    troca=vetor[0];
    vetor[0]=vetor[i];
    vetor[i]=troca;

    //reconstroi o heap
    cria_heap(vetor,0,i-1);
  }
}

int main() {
    int p, n, i;
    char **string, **vetor2;
    int *chave;
    scanf("%i", &p);
    string = malloc(p * sizeof(char*));

    for (i = 0; i < p; i++) {
        string[i] = malloc(32 * sizeof(char));
        scanf("%s", string[i]);
    }

    scanf("%i", &n);
    chave = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%i", &chave[i]);
    }

  for (i = 0; i < p; i++) {
    for (int j = 0; string[i][j] != '\0'; j++) {
      if (string[i][j] < 'a' || string[i][j] > 'z') {
        printf("a palavra %s eh invalida\n", string[i]);
        return 0;
      }
    }
  }
  vetor2 = malloc(n * sizeof(char*));
  printf("build heap:");
  for(i=0;i<n;i++){
    vetor2[i]=string[chave[i]];
    printf(" %s",vetor2[i]);
  }

  printf("\n");
  heap_sort(vetor2,n);

  printf("palavras:");
  for (i = 0; i < n; i++) {
    printf(" %s", vetor2[i]);
  }
  printf("\n");

  for (i = 0; i < p; i++) {
    free(string[i]);
  }
  free(string);
  free(chave);
  free(vetor2);

  return 0;
}
