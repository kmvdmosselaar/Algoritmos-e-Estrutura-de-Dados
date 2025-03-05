#include <stdio.h>
#include <string.h>

int palindromo(char palavra[], int resultado){
  int tamanho;
  tamanho = strlen(palavra);

  for(int i=0; i<=tamanho; i++ ){
    for(int j=tamanho; j>=0; j--){
      if(palavra[i] == palavra[j])
        resultado = 1;
    }
  }
  return resultado;
}

int main(){
  int resultado;
  char palavra[100];
  printf("Digite uma palavra: ");
  fgets(palavra); 
  if(palindromo(palavra,0)==1)
    printf("A palavra é um palindromo");
  else
    printf("A palavra não é um palindromo");
}