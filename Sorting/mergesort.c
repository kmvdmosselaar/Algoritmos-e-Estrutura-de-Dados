#include<stdio.h>
#include<stdlib.h>

void mergesort(int*, int, int);
void merge(int*, int, int, int);

int main(){
  int n, *A, i;
  printf("Digite o tamanho do vetor:");
  scanf("%i",&n);
  A = malloc(n * sizeof(int));
  printf("Digite o vetor: ");
  for(i=0;i<n;i++){
    scanf("%i",&A[i]);
  }
  mergesort(A,0,n-1);
  printf("Vetor ordenado: ");
  for(i=0;i<n;i++){
    printf("%i ",A[i]); // Adicionei um espaço aqui para melhor visualização
  }
  free(A); // Liberar memória alocada para o vetor A
}

void mergesort(int *A, int p, int r){
  if(p<r){
    int q=(p+r)/2;
    mergesort(A,p,q);
    mergesort(A,q+1,r);
    merge(A,p,q,r);
  }
}

void merge(int *A, int p, int q, int r){
  int k, i, j;
  int n1=q-p+1;
  int n2=r-q;
  int *L, *R;
  L = malloc(n1 * sizeof(int));
  R = malloc(n2 * sizeof(int));
  for(i=0;i<n1;i++){
    L[i]=A[p+i];
  }
  for(j=0;j<n2;j++){
    R[j]=A[q+j+1];
  }
  i=0;
  j=0;
  k=p;
  while(i<n1 && j<n2){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i+=1;
    }
    else{
      A[k]=R[j];
      j+=1;
    }
    k+=1;
  }
  while(i<n1){
    A[k]=L[i];
    i+=1;
    k+=1;
  }
  while(j<n2){
    A[k]=R[j];
    j+=1;
    k+=1;
  }
  free(L); // Liberar memória alocada para L
  free(R); // Liberar memória alocada para R
}
