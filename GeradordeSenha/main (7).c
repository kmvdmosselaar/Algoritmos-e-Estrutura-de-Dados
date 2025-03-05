//Katherine Mosselaar
//RA-163873

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeradorSenha.h"

void imprimeMenu();
void leDados(TipoItem*);

int main(){
  int op;
  Fila fila;
  TipoItem item;

  iniciaFila(&fila);

  while(op != 3){
    imprimeMenu();
    printf("Opção: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDados(&item);
        insereFila(&fila, item);
        break;
      case 2:
        chamada(&fila, &item);
        break;
    }
  }
  
  return 0;
}

void imprimeMenu(){
  printf("\nMenu:\n");
  printf("1 - Nova senha.\n");
  printf("2 - Chamada.\n");
  printf("3- Sair.\n");
}

void leDados(TipoItem *item){
  printf("\nNome: ");
  getchar();
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
  printf("\nÉ prioritário? \n1-Sim \n2-Não\n");
  scanf("%i",&item->i);
}
