function Inserir_Lista_Encadeada(lista, chave){
  if (lista == NULL){
    lista = Novo_Elemento();
    lista->chave = chave;
    lista->prox = NULL;
  }
  else {
    aux = lista;
    while (aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = Novo_Elemento();
    aux = aux->prox;
    aux->chave = chave;
    aux->prox = NULL;
  }
  return lista;
}

function Inserir_Hash_Encadeado(T,x){
  hash = Hash(x);
  T[hash] = Inserir_Lista_Encadeada(T[hash],x);
}

function Remover_Hash_Encadeado(T,x){
  hash = Hash(x);
  if !(Buscar_Hash_Encadeado(T,x)){
    return false;
  }
  T[hash] = Remover_Lista_Encadeada(T[hash],x);
  return true;
}

function Buscar_Hash_Encadeado(T,x){
  hash = Hash(x);
  lista = T[hash];
  found = false;
  while (lista != NULL) {
    if (lista->chave == x){
      found = true;
      break;
    }
    lista = lista->prox;
  }
  return found;
}