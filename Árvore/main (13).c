#include "Arvore.h"

int main(){
  TipoArvore raiz, pai, filho;//ponteiros para nós da árvore

  inicializaArvore(raiz);//atribui null ao ponteiro raiz
  raiz = instanciaArvore(raiz,'A');//alocou o nó da árvore e criou uma lista de filhos vazia


  inicializaArvore(pai);
  pai = instanciaArvore(pai,'B');
  
  inicializaArvore(filho);
  filho = instanciaArvore(filho,'E');
  pai = insereNaArvore(pai,filho);
  
  filho = instanciaArvore(filho,'F');
  pai = insereNaArvore(pai,filho);
  
  raiz = insereNaArvore(raiz,pai);
  
  pai = instanciaArvore(pai,'C');

  raiz = insereNaArvore(raiz,pai);

  pai = instanciaArvore(pai,'D');
  
  inicializaArvore(filho);
  filho = instanciaArvore(filho,'G');
  pai = insereNaArvore(pai,filho);
  
  filho = instanciaArvore(filho,'H');
  pai = insereNaArvore(pai,filho);
  
  raiz = insereNaArvore(raiz,pai);
  
  imprimeArvore(raiz,0);
  printf("\n");
  
  raiz = destroiArvore(raiz);
  
  return 0;
}