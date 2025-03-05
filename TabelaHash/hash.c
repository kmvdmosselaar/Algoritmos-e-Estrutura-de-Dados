function Inserir_Hash_Aberto(T,x,m){
  i = 0;
  do{
    hash = Hash(x,i);
    i = i + 1;
    if (i > m) break;
  }while (T[hash] != NULL);
  if (T[hash] != NULL){
    return false; // Não foi possível encontrar uma posição livre
  }
  T[hash] = x;
  return true;
}

function Remover_Hash_Aberto(T,x,m){
  i = 0;
  do{
    hash = Hash(x,i);
    i = i + 1;
    if (i > m) break;
  }while (T[hash] != x);
  if (T[hash] != x){
    return false; // Não foi possível encontrar o x
  }
  T[hash] = NULL;
  return true;
}

function Buscar_Hash_Aberto(T,x,m){
  i = 0;
  do{
    hash = Hash(x,i);
    i = i + 1;
    if (i > m) break;
  }while (T[hash] != x);
  if (T[hash] != x){
    return false; // Não foi possível encontrar o x
  }
  return true;
}