 // Katherine Mosselaar

 #include <stdio.h>
 #include <stdlib.h>

 void bubbleSort(int *, int n);
 int compara(int *, int *, int);

 int main() {
   int *vet1, *vet2;
   int i, n, x;

   scanf("%i", &n);
   vet1 = malloc(n * sizeof(int));
   vet2 = malloc(n * sizeof(int));
   for (i = 0; i < n; i++) {
     scanf("%i", &vet1[i]);
   }
   for (i = 0; i < n; i++) {
     scanf("%i", &vet2[i]);
   }
   bubbleSort(vet1, n);
   bubbleSort(vet2, n);
   x = compara(vet1, vet2, n);
   if (x != 0)
     printf("nao");
   else
     printf("sim");
   printf("\n");
 }

 void bubbleSort(int *vetor, int n) {
   int i, j, aux;
   for (i = 1; i < n; i++) {
     for (j = 0; j < n - 1; j++) {
       if (vetor[j] > vetor[j + 1]) {
         aux = vetor[j];
         vetor[j] = vetor[j + 1];
         vetor[j + 1] = aux;
       }
     }
   }
 }

 int compara(int *vet1, int *vet2, int n) {
   int i, cont = 0;
   for (i = 0; i < n; i++) {
     if (vet1[i] >= vet2[i])
       cont++;
   }
   return cont;
 }
