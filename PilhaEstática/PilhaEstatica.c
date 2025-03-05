#include "PilhaEstatica.h"

void inicializaPilha(TipoPilha *pilha){
    pilha->topo = -1;//se estiver vazia topo=-1, pois existe o indice 0, que esta ocupado 
}

void destroiPilha(TipoPilha *pilha){
  pilha->topo = -1;
}

int pilhaVazia(TipoPilha *pilha){
  return pilha->topo==-1;
}

int pilhaCheia(TipoPilha *pilha){
  return pilha->topo==MAX-1;
}

int empilha(TipoPilha *pilha,TipoItem item){
  if(!pilhaCheia(pilha)){
    pilha->topo++;
    pilha->itens[pilha->topo] = item;
    return 1;
  }
  return 0;
}//empilha=insere no final-->unica opcao quando se trabalha com pilha

int desempilha(TipoPilha *pilha,TipoItem *item){
  if(!pilhaVazia(pilha)){
    *item = pilha->itens[pilha->topo];
    pilha->topo--;
    return 1;
  } 
  return 0;
}//desempilha=retira do final

int consultaTopo(TipoPilha *pilha,TipoItem *item){
  if(!pilhaVazia(pilha)){
    *item = pilha->itens[pilha->topo];//preenche o valor item
    return 1;
  }
  return 0;
}

int imprimePilha(TipoPilha *pilha){
  int i;
  if(!pilhaVazia(pilha)){
    for(i=pilha->topo;i>=0;i--){
      imprimeItem(pilha->itens[i]);
    }
  }//imprime do topo até o primeiro colocado, i=0
  return 0;
}

void imprimeItem(TipoItem item){
  printf("%i %s\n",item.chave,item.nome);
}