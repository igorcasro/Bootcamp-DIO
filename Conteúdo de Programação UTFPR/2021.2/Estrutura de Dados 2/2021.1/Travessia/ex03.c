#include <stdio.h>
#include <stdlib.h>

struct TNoABP{
  int chave;
  struct TNoABP  *esq, *dir;
};

typedef struct TNoABP TNoABP;

TNoABP *insereNoABP(TNoABP **r, int k) {
  if(*r == NULL){
   
    (*r) = (TNoABP *)malloc(sizeof(TNoABP));
    if(*r){
      
      (*r)->chave = k;
      (*r)->esq = NULL;
      (*r)->dir = NULL;

      return *r;
    } else {
      return NULL;
    }
  }

  if(k <= (*r)->chave){
    return insereNoABP(&(*r)->esq, k);
  } else {
    return insereNoABP(&(*r)->dir, k);
  }

  return 0; //deixe como ultimo comando. Nunca sera executado.
}

void doisFilhos(TNoABP *raiz, int *k){

	if (raiz != NULL){

		doisFilhos(raiz->esq, k);
    if(raiz->esq != NULL && raiz->dir != NULL){
      (*k)= (*k) + 1;
      printf("%d\n", raiz->chave);
    }
		doisFilhos(raiz->dir, k);
		}
}



int main() {
  TNoABP *raiz = NULL; //arvore nascendo vazia
  int N, chave, i, qtdFolhas;
 
  //populando a arvore
//  printf("Populando a árvore\n\n");
//  printf("Insira quantas chaves vai inserir: ");
  do {
    scanf("%d", &N); //numero de chaves a inserir
  } while(N <= 0);
  for(i=0; i<N; ++i)
  {
//  	printf("Insira a chave do nó %d: ", i+1);
    scanf("%d", &chave);    
    if(chave > 0){
     insereNoABP(&raiz, chave);   
    } else {
      i--;
    }
  }

  int *p = &qtdFolhas;

  doisFilhos(raiz, p);
  if(qtdFolhas == 0){
    printf("nao ha no com dois filhos na arvore\n");
  } 

  return 0;
}