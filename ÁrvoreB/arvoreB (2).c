  #define M 2
  #define MM (2 * M)

  typedef int TChave;

  typedef struct {
  TChave Chave;
  /* outros componentes */
  } TItem;

  typedef int TIndice;

  typedef struct SNo *TArvoreB;

  typedef struct SNo {
  TItem Item[MM];
  TArvoreB Pagina[MM + 1];
  TIndice n;
  } TNo;

  typedef struct {
  TItem Item;
  TArvoreB Pagina;
  } TInfo;

//?=
typedef struct {
  int Chave;
/* outros componentes */
} TItem;

typedef struct SNo *TArvoreB;

typedef struct SNo {
  TItem Item[MM];
  TNo Pagina[MM + 1];
  int n;
} TNo;

typedef struct {
  TItem Item;
  TArvoreB Pagina;
} TInfo;

  // Determina a posição da chave na página (0..n)
  function IndiceChave(ArvoreB, Chave){
    for (i=0; (i<ArvoreB.n) && (Chave > ArvoreB.Item[i].Chave); i++);//incrementa o i enquanto a chave é maior que a chave do item e o i seja menor que tamanho da arvore
    return i;
  }

  // Insere uma nova chave na página
  function InsereChave(ArvoreB, Chave, PaginaChave){
    Index = IndiceChave(ArvoreB,Chave);
    for (j=ArvoreB.n; j>Index; j--){
      ArvoreB.Item[j] = ArvoreB.Item[j-1];
      ArvoreB.Pagina[j+1] = ArvoreB.Pagina[j];
    }
    ArvoreB.Item[i].Chave = Chave;
    ArvoreB.Pagina[i+1] = PaginaChave;
    ArvoreB.n++;
  }

  function DividePagina(ArvoreB, *Chave, *PaginaChave){
    Index = IndiceChave(ArvoreB,Chave);
    for (i=Index; i<M; i++){
      ChaveAux = ArvoreB.Item[i].Chave;
      PaginaChaveAux = ArvoreB.Pagina[i+1];
      ArvoreB.Item[i].Chave = *Chave;
      ArvoreB.Pagina[i+1] = *PaginaChave;
      *Chave = ChaveAux;
      *PaginaChave = PaginaChaveAux;
    }
    for (i=Index-1; i>=M; i--){
      ChaveAux = ArvoreB.Item[i].Chave;
      PaginaChaveAux = ArvoreB.Pagina[i+1];
      ArvoreB.Item[i].Chave = *Chave;
      ArvoreB.Pagina[i+1] = *PaginaChave;
      *Chave = ChaveAux;
      *PaginaChave = PaginaChaveAux;
    }
    NovaPagina = CriaArvoreB();
    for (i=M*2-1; i>=M; i--){
      ChaveAux = ArvoreB.Item[i].Chave;
      PaginaChaveAux = ArvoreB.Pagina[i+1];
      InsereChave(NovaPagina,ChaveAux,PaginaChaveAux);
      ArvoreB.Item[i].Chave = EMPTY;
      ArvoreB.Pagina[i+1] = NULL;
      ArvoreB.n--;
    }
    NovaPagina.Pagina[0] = *PaginaChave;
    *PaginaChave = NovaPagina;
  }

  function InsereArvoreB(ArvoreB, *Chave, *PaginaChave){
    Index = IndiceChave(ArvoreB,*Chave);
    if (Index < 2*M) && (*Chave == ArvoreB.Item[Index].Chave){
     return false; 
    }
    if (ArvoreB.Pagina[Index]){//verifica se existe uma pagina abaixo (sub-nó)
      if (!InsereArvoreB(ArvoreB.Pagina[Index], Chave, PaginaChave)){
        return false;
      }
    }
    if (*Chave != EMPTY){
      if (ArvoreB.n < M*2){
        InsereChave(ArvoreB, *Chave, *PaginaChave);
        *Chave = EMPTY;
        *PaginaChave = NULL;
      }
      else{
        DividePagina(ArvoreB, Chave, PaginaChave);
      }
    }
    return true;
  }

  function Insere(ArvoreB, Chave){
    if (ArvoreB = NULL){
      ArvoreB = CriaArvoreB();
    }
    PaginaChave = NULL;
    if (InsereArvoreB(ArvoreB,&Chave,&PaginaChave)) {//tratamento para o caso do pagina inicial mudar (ter sido dividida)
      if (*Chave != EMPTY){
        NovaArvoreB = CriaArvoreB();
        NovaArvoreB.Pagina[0] = ArvoreB;
        InsereChave(NovaArvoreB,Chave,PaginaChave);
        ArvoreB = NovaArvoreB;
      }
    }
    else{
      printf("Chave já existente!\b")
    }
  }
