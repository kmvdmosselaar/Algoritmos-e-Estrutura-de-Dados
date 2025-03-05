#include <stdio.h>
#include <stdlib.h>
struct AB{
  int chave;
  int altura;
  struct AB *esq;
  struct AB *dir;
};
typedef struct AB tipoAB;
tipoAB* rotinaLL(tipoAB *arv);
tipoAB* rotinaRR(tipoAB *arv);
tipoAB* rotinaRL(tipoAB *arv);
tipoAB* rotinaLR(tipoAB *arv);

int calculaH(tipoAB *arv){
  int hE,hD;
  if(arv == NULL)
    return -1;
  else{
    hE = calculaH(arv->esq);
    hD = calculaH(arv->dir);
    if(hE>hD)
      return hE + 1;
    else
      return hD + 1;
  }
}
void defH(tipoAB *no){
  if(no)
    no->altura = calculaH(no);
}
int calculaFatBal(tipoAB *arv){
  if(arv)
    return (calculaH(arv->esq) - calculaH(arv->dir));
  else
    return 0;
}
tipoAB* aloca(int x){
  tipoAB *novoNoh;
  novoNoh = malloc(sizeof(tipoAB));
  novoNoh->altura = 0;
  novoNoh->chave = x;
  novoNoh->dir=NULL;
  novoNoh->esq = NULL;
  return novoNoh;
}
tipoAB* balancear(tipoAB *arv){
  int fatB = calculaFatBal(arv);
  if(fatB < -1 && calculaFatBal(arv->dir)<=0)
    arv = rotinaLL(arv);
  else if(fatB < -1 && calculaFatBal(arv->dir) > 0)
    arv = rotinaRL(arv);
  else if(fatB > 1 && calculaFatBal(arv->esq)>=0)
    arv = rotinaRR(arv);
  else if(fatB > 1 && calculaFatBal(arv->esq)<0)
    arv = rotinaLR(arv);
  return arv;
}
tipoAB* inserir(tipoAB *arv, tipoAB *novoNoh){
  if(arv==NULL)
    return novoNoh;
  else{
    if(novoNoh->chave < arv->chave){
      if(arv->esq == NULL)
        arv->esq = novoNoh;
      else
        arv->esq = inserir(arv->esq,novoNoh);//poderia tirar a igualdade
    }
    else{
      if(arv->dir == NULL)
        arv->dir = novoNoh;
      else
        arv->dir = inserir(arv->dir,novoNoh);
    }
  }
  defH(arv);
  arv = balancear(arv);
  return arv;
}
tipoAB* buscaABB(tipoAB *arv, int x){
  if(arv == NULL)
    return NULL;
  else{
    if(arv->chave == x)
      return arv;
    else{
      if(x < arv->chave)
        return buscaABB(arv->esq,x);
      else
        return buscaABB(arv->dir,x);
    }
  }
}
tipoAB* remover(tipoAB *arv, int x){
  tipoAB *sucessor,*pai,*filho;
  if(arv==NULL){
    printf("valor nao encontrado\n");
    return NULL;
  }
  else{
    if(x==arv->chave){
      if(arv->esq==NULL && arv->dir==NULL){
        arv = NULL;
        free(arv);
        return NULL;
      }
      else{
        if(arv->esq != NULL && arv->dir!=NULL){
          sucessor = arv->dir;
          while(sucessor->esq)
            sucessor = sucessor->esq;
          arv->chave = sucessor->chave;
          sucessor->chave = x;
          arv->dir = remover(arv->dir,x);
          return arv;
        }
        else{
          if(arv->esq==NULL)
            filho = arv->dir;
          else
            filho = arv->esq;
          free(arv);
          return filho;//??
        }
      }
    }
    else{
      if(x<arv->chave)
        arv->esq = remover(arv->esq,x);
      else
        arv->dir = remover(arv->dir,x);
    }
    defH(arv);
    arv = balancear(arv);
    return arv;
  }
}
tipoAB* rotinaLL(tipoAB *arv){
  tipoAB *aux,*filho;
  aux = arv->dir;
  filho = aux->esq;

  aux->esq = arv;
  arv->dir = filho;

  defH(arv);
  defH(aux);
  return aux;
}
tipoAB* rotinaRR(tipoAB *arv){
  tipoAB *aux,*filho;
  aux = arv->esq;
  filho = aux->dir;

  aux->dir = arv;
  arv->esq = filho;

  defH(arv);
  defH(aux);
  return aux;
}
tipoAB* rotinaRL(tipoAB *arv){
  arv->dir = rotinaRR(arv->dir);
  return rotinaLL(arv);
}
tipoAB* rotinaLR(tipoAB *arv){
  arv->esq = rotinaLL(arv->esq);
  return rotinaRR(arv);
}

void printarArvore(tipoAB *arv){
  if(arv){
    printarArvore(arv->esq);
    printf("%d ",arv->chave);
    printarArvore(arv->dir);
  }
}
int main(void) {
  tipoAB *arv, *novoNoh,*verify;
  int x=0,y = 0,fat,z;
  arv = NULL;
  while(x >= 0){
    scanf("%d",&x);
    if(x >= 0){
      novoNoh = aloca(x);
      defH(novoNoh);
      arv = inserir(arv,novoNoh);
      //printf("arv:%d\n",arv->chave);
      //printarArvore(arv);
      //printf("\n");
    }
  }
  printf("%i,%i,%i\n",calculaH(arv),calculaH(arv->esq)+1,calculaH(arv->dir)+1);
  while(y >= 0){
    scanf("%i",&y);
    if(y >= 0){
      verify = buscaABB(arv,y);
      if(verify != NULL){
        arv = remover(arv,y);
      }
      else{
        novoNoh = aloca(y);
        defH(novoNoh);
        arv = inserir(arv,novoNoh);
      }
    }
  }
  scanf("%i",&z);
  verify = buscaABB(arv,z);
  if(verify == NULL)
    printf("Valor nao encontrado");
  else{
  printf("%i,%i,%i\n",calculaH(verify),calculaH(verify->esq)+1,calculaH(verify->dir)+1);
  }
  return 0;
}