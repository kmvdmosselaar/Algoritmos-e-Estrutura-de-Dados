#include "ArvoreBinaria.h"

int main(){
  TipoArvore raiz, pai, filho;

  raiz = instanciaArvore('A');

  pai = instanciaAvore('B');
  filho = instanciaArvore('C');
  pai = insereSubArvoreEsq(pai,filho);
  filho = instanciaArvore('D');
  pai = insereSubArvoreDir(pai,filho);
  raiz = insereSubArvoreEsq(raiz,pai);

  montaArvore(instanciaArvore('A'),montaArvore(instanciaAvore('B'),instanciaArvore('C'),instanciaArvore('D')),montaArvore(instanciaAvore('E'),instanciaArvore('F'),instanciaArvore('F')));
}

