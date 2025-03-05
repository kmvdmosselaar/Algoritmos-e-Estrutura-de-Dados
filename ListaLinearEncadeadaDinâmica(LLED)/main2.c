//Katherine Mombach van den Mosselaar
//RA-163873

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLSE.h"


int main(){
  ListaLinearSE lista;
  TipoItem item;
  int i,n, pos, op=0;
  
  inicializaLLSE(&lista);

  
  printf("Número de itens a serem inseridos: ");
  scanf("%i",&n);
  for(i=0;i<n;i++){//aqui ela preenche todos os itens
    printf("Item %i\n",i+1);
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    item.nome[strlen(item.nome)-1] = '\0';
    if(insereNoFinalLLSE(&lista,item)<0){
      printf("Erro! Tamanho limite excedido!\n");
      break;
    }
  }

  while(op!=-1){ 
    imprimeMenu();//aqui ela lista as funções
    scanf("%i", &op);
    switch(op){
      case 1:
        printf("\nItens na lista:\n");
        imprimeListaLLSE(&lista);
        break;
      case 2: //Insere na posição
        printf("Item %i\n",i+1);
        printf("Chave: ");
        scanf("%i",&item.chave);
        getchar();
        printf("Nome: ");
        fgets(item.nome,sizeof(item.nome),stdin);
        item.nome[strlen(item.nome)-1] = '\0';
        printf("Posição a ser colocado: ");
        scanf("%i", &pos);
        if(insereNaPosicao(&lista, &item, pos-1))
          printf("Item inserido na posição %i", pos);
        else
          printf("ERRO!!");
        break;
      case 3: //Remove do começo
        if(!removeDoComecoLLSE(&lista,&item))
          printf("Erro! Lista Vazia!\n");
        else
          printf("\nItem Removido: %i %s\n",item.chave,item.nome);
      case 4: //Remove do final
        if(!removeDoFinalLLSE(&lista,&item))
         printf("Erro! Lista Vazia!\n");
       else
         printf("\nItem Removido: %i %s\n",item.chave,item.nome);
        break;
      case 5: //Remove da posição
        printf("Insira a posição a ser removida: ");
        scanf("%i", &pos);
        if(retiraDaPosicao(&lista, pos-1))
          printf("Item %i removido com sucesso!\n", pos);
        break;
      case 6: //Retira item especifico
        printf("Insira a chave do item a ser removido: ");
        scanf("%i", &pos);
        if(retiraEspecifico(&lista, pos)==0)
          printf("Item removido com sucesso!");
        break;
      case -1:
        printf("Obrigado! Até logo :)");
        if(!listaVaziaLLSE(&lista)){
          printf("\nItens na lista:\n");
          imprimeListaLLSE(&lista);
          }
        break;
      default:
        printf("ERRO!! default");
        break;
    }
  }  
  return 0;
}