//Katherine Mosselaar 163873

#include <string.h>
#include "pilha.h"

int resolvePosfix(char*);
void imprimePosfix(char*);

int main(){
  char expressao[30];
  int resultado;

  printf("Expressão: ");
  fgets(expressao,sizeof(expressao),stdin);
  expressao[strlen(expressao)-1] = '\0';
  imprimePosfix(expressao);
  resultado = resolvePosfix(expressao);
  printf("Resultado: %i\n",resultado);
  return 0;
}

int resolvePosfix(char *expressao){
  TipoPilha pilha1, pilha2;
  TipoItem item;
  int i,n1,n2,r;

  pilha1 = inicializaPilha(pilha1);
  pilha2 = inicializaPilha(pilha2);
  
  for(i=0;i<strlen(expressao);i++){
    item.caracter = expressao[i];
    pilha1 = empilha(pilha1,item);
  }  
  while(!pilhaVazia(pilha1)){
    pilha1 = desempilha(pilha1,&item);
    if(item.caracter=='+'||item.caracter=='-'||item.caracter=='*'||item.caracter=='/'){
      pilha2 = empilha(pilha2,item);
    }
    else{
      n1 = item.caracter - '0';
      pilha1 = desempilha(pilha1,&item);
      n2 = item.caracter - '0';
      pilha2 = desempilha(pilha2,&item);
      switch(item.caracter){
        case '+':
          r = n1+n2;
          break;
        case '-':
          r = n1-n2;
          break;
        case '*':
          r = n1*n2;
          break;
        case '/':
          r = n1/n2;
          break;
      }
      item.caracter = r + '0';
      if(pilhaVazia(pilha1)){
        break;
      }
      else{
        pilha1 = empilha(pilha1,item);
      }
    }
    printf("\nPilha 1:\n");
    imprimePilha(pilha1);
    printf("\nPilha 2:\n");
    imprimePilha(pilha2);
  }
  
  pilha1 = destroiPilha(pilha1);
  pilha2 = destroiPilha(pilha2);
  return r;
}

//EXERCICIO 2
void imprimePosfix(char * expressao){
  TipoPilha pilha1, pilha2;
  TipoItem item;
  char sinal;
  int i,n1,n2,r;

  pilha1 = inicializaPilha(pilha1);
  pilha2 = inicializaPilha(pilha2);
  
  for(i=0;i<strlen(expressao);i++){
    item.caracter = expressao[i];
    pilha1 = empilha(pilha1,item);
  }
  while(!pilhaVazia(pilha1)){
    pilha1 = desempilha(pilha1,&item);
    if(item.caracter=='+'||item.caracter=='-'||item.caracter=='*'||item.caracter=='/'){
      pilha2 = empilha(pilha2,item);
    }
    else{
      n1 = item.caracter - '0';
      printf("%i ", n1);
      if(!pilhaVazia(pilha2)){
        pilha2 = desempilha(pilha2, &item);
        printf("%c ", item.caracter);
      }
    }
  }

  pilha1 = destroiPilha(pilha1);
  pilha2 = destroiPilha(pilha2);
}
