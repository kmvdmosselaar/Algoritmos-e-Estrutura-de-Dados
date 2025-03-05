//Katherine Mosselaar 163873

#include "mEsp.h"

void imprimeMenu();

int main(){
  TipoMatriz mat;
  int op=0;
  int linha,coluna,elemento;
  
  inicializaMatriz(&mat);

  printf("N. de linhas das Matriz: ");
  scanf("%i",&linha);
  printf("N. de colunas das Matriz: ");
  scanf("%i",&coluna);
  instanciaMatriz(&mat,linha,coluna);
  
  while(op!=4){
    imprimeMenu();
    scanf("%i",&op);
    switch(op){
      case 1:
        printf("\nLinha: ");
        scanf("%i",&linha);
        printf("Coluna: ");
        scanf("%i",&coluna);
        printf("Elemento: ");
        scanf("%i",&elemento);
        insereNaMatriz(&mat,linha,coluna,elemento);
        break;
      case 2:
        printf("Linha: ");
        scanf("%i", &linha);
        printf("Coluna: ");
        scanf("%i",&coluna);
        if(retiraDaMatriz(&mat, linha, coluna, &elemento))
          printf("O elemento %i retirado!\n", elemento);
        else
          printf("Não foi possível retirar o elemento.");
        break;
      case 3:
        printf("\nMatriz:\n");
        imprimeMatriz(&mat);
        break;
      case 4:
        destroiMatriz(&mat);
        break;
      default:
        printf("\nOpção incorreta!\n");
        break;
    }
  }
}

void imprimeMenu(){
  printf("\nMenu:");
  printf("\n1 - Insere na Matriz");
  printf("\n2 - Retira da Matriz");
  printf("\n3 - Imprime Matriz");
  printf("\n4 - Sair");
  printf("\nOpção: ");
}