typedef int TChave;

typedef struct {
TChave Chave;
/* outros compomentes */
} TItem;

typedef struct SNo *TArvBin;

typedef struct SNo {
TItem Item;
TArvBin Esq, Dir;
} TNo;



typedef struct {
int Chave;
/* outros compomentes */
} TItem;


typedef struct SNo {
TItem Item;
TNo *Esq, *Dir;
} TNo;