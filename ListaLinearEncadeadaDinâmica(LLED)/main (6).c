//Katherine Mombach van den Mosselaar
//RA-163873

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLED.h"

void imprimeMenu();
void leDadosAluno(TipoItem*);

int main(){
  ListaLinearED listaAlunosAED;
  TipoItem item;
  int n, i, op = 0, posicao, RA;

  inicializaListaLLED(&listaAlunosAED);

  while(op != 5){
    imprimeMenu();
    printf("Opção: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosAluno(&item);
        if(insereNoFinalLLED(&listaAlunosAED,item)){
          printf("\nAluno inserido com sucesso.\n");
        }
        break;
      case 2:
        imprimeListaLLED(&listaAlunosAED);
        break;
      case 3:
        leDadosAluno(&item);
        printf("Qual posição que deseja inserir? ");
        scanf("%i", &posicao);
        insereNaPosicao(&listaAlunosAED,item,posicao);
        break;
      case 4:
        printf("Qual posição que deseja remover? ");
        scanf("%i", &posicao);
        retiraDaPosicao(&listaAlunosAED,&item,posicao);
        break;
      case 5:
        printf("Qual o RA do aluno que deseja remover da lista? ");
        scanf("%i", &RA);
        retiraEspecifico(&listaAlunosAED,&item,RA);
        break;
      case 6:
        destroiListaLLED(&listaAlunosAED);
        break;
      default:
        printf("\nOpcao incorreta!\n");
        break;
    }
  }
  
  return 0;
}

void imprimeMenu(){
  printf("\nMenu:\n");
  printf("1 - Inserir aluno.\n");
  printf("2 - Listar alunos.\n");
  printf("3 - Insere na posição.\n");
  printf("4 - Remove aluno da posição.\n");
  printf("5 - Remove aluno específico.\n");
  printf("6 - Sair.\n");
}

void leDadosAluno(TipoItem *item){
  int i;
  printf("\nRA: ");
  scanf("%i",&item->RA);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
  item->nome[strlen(item->nome)-1] = '\0';
  for(i=0;i<3;i++){
    printf("Nota %i: ",i+1);
    scanf("%f",&item->notas[i]);
  }
  printf("Frequencia: ");
  scanf("%i",&item->freq);
}