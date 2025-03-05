//Katherine Mombach van den Mosselaar
//RA-163873

#include "LLSE.h"

int listaVaziaLLSE(ListaLinearSE *lista){
  return lista->ultimo==0;
}

int listaCheiaLLSE(ListaLinearSE *lista){
  return lista->ultimo==MAX;
}

void inicializaLLSE(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void destroiListaLLSE(ListaLinearSE *lista){
  lista->ultimo = 0;
}

void imprimeMenu(){
  printf("\n### MENU ###\n");
  printf("1 - Ver Lista;\n2 - Insire item na posição;\n3 - Remove item do começo;\n");
  printf("4 - Remove item do final;\n5 - Remove item da posição; \n6 - Remove item por chave;\n");
  printf("(-1) SAIR\n");
  printf("Insira opção: ");
}

void imprimeItem(TipoItem *item){
  printf("%i - %s\n", item->chave, item->nome);
}

void imprimeListaLLSE(ListaLinearSE *lista){
  int i;

  for(i=0;i<lista->ultimo;i++)
    imprimeItem(&lista->itens[i]);
}

int insereNoFinalLLSE(ListaLinearSE *lista, TipoItem novoItem){
  int pos = lista->ultimo;

  if(pos < MAX){
    lista->itens[pos] = novoItem;
    lista->ultimo++;
    return 0;
  }
  else
    return -1;
}

int removeDoFinalLLSE(ListaLinearSE *lista,TipoItem *item){
  int pos = lista->ultimo;
  if(pos>0){
    item->chave = lista->itens[pos-1].chave;
    strcpy(item->nome,lista->itens[pos-1].nome);
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int removeDoComecoLLSE(ListaLinearSE *lista,TipoItem *item){
  int i;
  int pos = lista->ultimo;
  if(lista->ultimo>0){
    item->chave = lista->itens[0].chave;
    strcpy(item->nome,lista->itens[0].nome);
    for(i=1;i<pos;i++){
      lista->itens[i-1].chave = lista->itens[i].chave;
      strcpy(lista->itens[i-1].nome,lista->itens[i].nome);
    }
    lista->ultimo--;
    return 1;
  }
  return 0;
}

int insereNaPosicao(ListaLinearSE *lista, TipoItem *item, int n){
  int i;
  if(lista->ultimo >= MAX || n>lista->ultimo){
    printf("Número maximo de itens atingido!\n");
    return 0;
  }
  else{
    lista->ultimo++;
    for(i=lista->ultimo; i>=n; i--){//abrindo espaço pra colocar
      lista->itens[i+1].chave = lista->itens[i].chave;
      strcpy(lista->itens[i+1].nome,lista->itens[i].nome);    
    }
  
  lista->itens[n].chave = item->chave;
  strcpy(lista->itens[n].nome,item->nome);      
  return 1;
  }
}

int retiraDaPosicao(ListaLinearSE *lista, int n){
  int i;
  if(n>lista->ultimo || n<0){
    printf("Posição não existente!\n");
    return 0;
  }
  for(i=n; i<lista->ultimo;i++){
    lista->itens[i].chave = lista->itens[i+1].chave;
    strcpy(lista->itens[i].nome,lista->itens[i+1].nome);
  }
  lista->ultimo --;
  return 1;
}

int retiraEspecifico(ListaLinearSE *lista, int chave){
  int i, cont =0;
  for(i=0; i<lista->ultimo; i++){
    if(lista->itens[i].chave == chave){
      printf("Item removido: %i - %s\n", lista->itens[i].chave, lista->itens[i].nome);
      return retiraDaPosicao(lista, i);
  }
    else    
      cont++;
  }
  printf("Item não encontrado.\n");
  return cont;
}