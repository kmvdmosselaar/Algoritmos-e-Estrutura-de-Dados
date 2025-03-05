#include<stdlib.h>
#include<stdio.h>



#define FALSE 0
#define TRUE  1

typedef long int tipoChave;
typedef struct tipoItem {
  tipoChave chave;
} tipoItem;

typedef struct tipoFolha* tipoPtr;
typedef struct tipoFolha {
  short n;
  tipoItem *r;
  tipoPtr *p;
} tipoFolha;

void Inicializa(tipoPtr * dic){
  *dic = NULL; 
}

tipoPtr alocaB(int m){
  int MM = 2*m;
  tipoPtr D = malloc(sizeof(tipoFolha));
  D->r = (tipoItem*) malloc(MM*sizeof(tipoItem));
  D->p = (tipoPtr*) malloc((MM+1) * sizeof(tipoPtr));
  return D;
}
void desalocaB(tipoPtr dic){
  if(dic==NULL)
    return;
  for(int i=0;  i<dic->n; i++){
    desalocaB(dic->p[i]);
  }
  free(dic->r);
  free(dic);
}

void ImprimeN(tipoPtr p){
  for(int i=0; i<p->n;i++)
    printf("%ld ", p->r[i].chave);
  printf("\n");
}

int Pesquisa(tipoItem *x, tipoPtr ptr, int log){ 
  long i = 1;
  if (ptr == NULL){ 
    return 0;
  }
  while (i < ptr->n && x->chave > ptr->r[i-1].chave) 
    i++;
  if (x->chave == ptr->r[i-1].chave) { 
    if(log==1){
      *x = ptr->r[i-1];
      printf("%i\n", ptr->n);
      ImprimeN(ptr);
    }
    return 1;
  }
  if (x->chave < ptr->r[i-1].chave) 
    Pesquisa(x, ptr->p[i-1], log);
  else Pesquisa(x, ptr->p[i], log);
} 

void InsereNaPagina(tipoPtr ptr, tipoItem Reg, tipoPtr pDir){ 
  short naoAchou;
  int k;
  k = ptr->n;  
  naoAchou = (k > 0);
  while (naoAchou) 
    { if (Reg.chave >= ptr->r[k-1].chave) 
      { naoAchou = FALSE;
        break;
      }
      ptr->r[k] = ptr->r[k-1];
      ptr->p[k+1] = ptr->p[k];
      k--;
      if (k < 1) naoAchou = FALSE;
    }
  ptr->r[k] = Reg; 
  ptr->p[k+1] = pDir;
  ptr->n++;
} 

void Ins(tipoItem Reg, tipoPtr ptr, short *Cresceu, tipoItem *itemRetorno,  tipoPtr *ptrRetorno, int MM){ 
  long i = 1; // Posição provavel do vetor em que novo indice sera inserido
  long j;
  tipoPtr ptrTemp;
  ptrTemp = alocaB(MM/2);

  if (ptr == NULL) // Critério de parada da recursão. Pode ser usado para arvore vazia, arvore com espaço em folhas ou arvore que explode
  { *Cresceu = TRUE; (*itemRetorno) = Reg; (*ptrRetorno) = NULL;
    return;
  }

  while (i < ptr->n && Reg.chave > ptr->r[i-1].chave)  i++; 


  if (Reg.chave < ptr->r[i-1].chave) i--; 

  Ins(Reg, ptr->p[i], Cresceu, itemRetorno, ptrRetorno, MM);

  if (!*Cresceu) return;

  if (ptr->n < MM)  
    { InsereNaPagina(ptr, *itemRetorno, *ptrRetorno);
      *Cresceu = FALSE;
      return;
    }

  ptrTemp = alocaB(MM/2); 
  ptrTemp->n = 0;  ptrTemp->p[0] = NULL; 
    if (i < (MM/2) + 1) 
    { InsereNaPagina(ptrTemp, ptr->r[MM-1], ptr->p[MM]);
      ptr->n--;
      InsereNaPagina(ptr, *itemRetorno, *ptrRetorno);
    } 
    else InsereNaPagina(ptrTemp, *itemRetorno, *ptrRetorno);
    for (j = (MM/2) + 2; j <= MM; j++) 
      InsereNaPagina(ptrTemp, ptr->r[j-1], ptr->p[j]);
    ptr->n = MM/2;  
    ptrTemp->p[0] = ptr->p[(MM/2)+1];
    *itemRetorno = ptr->r[MM/2];  *ptrRetorno = ptrTemp;
}

void Insere(tipoItem Reg, tipoPtr *ptr, int MM){
  short Cresceu;
  tipoItem itemRetorno;
  tipoFolha *ptrRetorno, *ptrTemp;
  ptrRetorno = alocaB(MM/2);

  Ins(Reg, *ptr, &Cresceu, &itemRetorno, &ptrRetorno, MM); 
  if (Cresceu)
  { ptrTemp = alocaB(MM/2); 
    ptrTemp->n = 1;  
    ptrTemp->r[0] = itemRetorno; 
    ptrTemp->p[1] = ptrRetorno; 
    ptrTemp->p[0] = *ptr;   
    *ptr = ptrTemp; 
  }
}

int main(){
  int m;
  tipoItem x;
  tipoFolha *D;

  scanf("%i", &m);
  D = alocaB(m);
  Inicializa(&D);

  do{ 
    scanf("%ld", &x.chave);
    if(x.chave>=0 && Pesquisa(&x, D, 0)==0)
      Insere(x, &D, 2*m);
    getchar();
  }while(x.chave >= 0);

  printf("%i\n", D->n);

  scanf("%ld", &x.chave);
  if(Pesquisa(&x, D, 1)==0)
    printf("Valor nao encontrado\n");

  return 0;
}