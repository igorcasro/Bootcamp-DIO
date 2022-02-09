#include <stdio.h>
#include <stdlib.h>

struct TNoAVL{
	int chave;
	struct TNoAVL *esq, *dir;
};
typedef struct TNoAVL TNoAVL;

TNoAVL *insereNoABP(TNoAVL **r, int k) {
  if(*r == NULL){
   
    (*r) = (TNoAVL *)malloc(sizeof(TNoAVL));
    
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


/* 
 * Rotação a direita somente ocorre quando 
 * o nó que deseja se fazer a rotação
 * possui filho à esquerda.
 */
void rotacaoDireita(TNoAVL **r){

	if(*r == NULL){
		exit(0);
	}

	if((*r)->esq != NULL){
		TNoAVL *aux = (*r)->esq;
			(*r)->esq = aux->dir;
			aux->dir = (*r);
			(*r) = aux;
	}

}

/* 
 * Rotação a esquerda somente ocorre quando 
 * o nó que deseja se fazer a rotação
 * possui filho à direita.
 */
void rotacaoEsquerda(TNoAVL **r){

	if(*r == NULL){
		exit(0);
	}

	if((*r)->dir != NULL){
		TNoAVL *aux = (*r)->dir;
			(*r)->dir = aux->esq;
			aux->esq = (*r);
			(*r) = aux;
	}

}

void preOrdem(TNoAVL *raiz)
{
  if (raiz != NULL)
  {
    printf("%d\n", raiz->chave);
		preOrdem(raiz->esq);		
   	preOrdem(raiz->dir);
  }
}

int main(){
	TNoAVL *raiz = NULL; //arvore nascendo vazia
	int N, chave, i;
	 
	//populando a arvore
	printf("Populando a árvore\n\n");
	printf("Insira quantas chaves vai inserir: ");
	scanf("%d", &N); //numero de chaves a inserir
	for(i=0; i<N; ++i)
	{
		printf("Insira a chave do nó %d: ", i+1);
	    scanf("%d", &chave);    
	    insereNoABP(&raiz, chave);   
	}

	printf("ANTES\n");
	preOrdem(raiz);

	rotacaoEsquerda(&raiz);

	printf("DEPOIS\n");
	preOrdem(raiz);

	return 0;
}