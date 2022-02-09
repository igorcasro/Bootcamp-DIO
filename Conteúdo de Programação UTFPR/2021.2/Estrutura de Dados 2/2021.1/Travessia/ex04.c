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

void numeroFolhas(TNoABP *raiz){

	if (raiz != NULL){

		numeroFolhas(raiz->esq);
    if(raiz->esq == NULL && raiz->dir == NULL){
      printf("%d\n", raiz->chave);
    }
		numeroFolhas(raiz->dir);
		}
}



int main() {
  TNoABP *raiz = NULL; //arvore nascendo vazia
  int N, chave, i;
 
  //populando a arvore
//  printf("Populando a árvore\n\n");
//  printf("Insira quantas chaves vai inserir: ");
  do{
    scanf("%d", &N); //numero de chaves a inserir
  } while(N <= 0);
  for(i=0; i<N; ++i)
  {
// 	printf("Insira a chave do nó %d: ", i+1);
    scanf("%d", &chave);    
    insereNoABP(&raiz, chave);   
  }

  numeroFolhas(raiz);

  return 0;
}