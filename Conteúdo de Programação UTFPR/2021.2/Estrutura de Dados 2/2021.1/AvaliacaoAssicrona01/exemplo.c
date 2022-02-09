#include <stdlib.h>
#include <stdio.h>

struct TNoABP
{
  int chave;
  struct TNoABP  *esq, *dir;
};

typedef struct TNoABP TNoABP;



/*
 * Recebe ponteiro de ponteiro para ABP e uma chave de insercao.
 * Devolve endereço do no inserido ou NULL
 * em caso de insucesso na insercao.
*/
TNoABP *insereNoABP(TNoABP **r, int k)
{
//  TNoABP *no = *r;
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


/*
 * Recebe ponteiro para ABP e uma chave de busca.
 * Devolve 1 se existe um no cujo campo chave
 * seja igual a k ou 0 (zero) caso contrário.
*/
int buscaNoABP(TNoABP *r, int k)
{

  if(r == NULL){
    return 0;
  }

  if(r->chave == k){
    return 1;
  }

  if(r->chave > k){
    return buscaNoABP(r->esq, k);
  } else {
    return buscaNoABP(r->dir, k);
  }

  return -1;//deixe como ultimo comando. Nunca sera executado.
}

/*
 * Recebe o ponteiro da raiz da ABP e retorna um ponteiro para essa
 * posição.
 */
TNoABP *retornaRaizABP(TNoABP **raiz){
  return *raiz;
}

/*
 * Recebe ponteiro de ponteiro para ABP e uma chave de remocao
 * e remove o no cujo campo chave seja igual a k.
 */
void removeNoABP(TNoABP **raiz, int k)
{
  TNoABP *percorre = *raiz;
  TNoABP *anterior;

  if(*raiz != NULL){    
    if(buscaNoABP(*raiz, k) == 1){
      while(percorre->chave != k){ //leva o ponteiro percorre ate a posicao desejada
        if(k < percorre->chave){
          anterior = percorre;
          percorre = percorre->esq;
        } else if(k > percorre->chave){
          anterior = percorre;
          percorre = percorre->dir;
        }              
      }
      //aqui entra casos possiveis de nó
      if(percorre->esq == NULL && percorre->dir == NULL){        
        if(anterior->dir == percorre){  
          free(percorre);
          (percorre) = NULL;       
          anterior->dir = NULL;
        } else {
          free(percorre);
          (percorre) = NULL;
          anterior->esq = NULL;
        }
      } else if(percorre->esq == NULL){
        if(anterior->dir == percorre){  
          anterior->dir = percorre->dir;
          free(percorre);
          (percorre) = NULL;                 
        } else {
          anterior->esq = percorre->dir;
          free(percorre);
          (percorre) = NULL;         
        }
      } else if(percorre->dir == NULL){
        if(anterior->dir == percorre){  
          anterior->dir = percorre->esq;
          free(percorre);
          (percorre) = NULL;                 
        } else {
          anterior->esq = percorre->esq;
          free(percorre);
          (percorre) = NULL;         
        }
      } else {
        //ultimo caso onde possuem 2 folhas
      }
    } 
  }

}

void emOrdem(TNoABP *raiz)
{
  if (raiz != NULL)
  {
    emOrdem(raiz->esq);
    printf("%d\n", raiz->chave);
    emOrdem(raiz->dir);
  }
}

int main()
{
  TNoABP *raiz = NULL; //arvore nascendo vazia
  int N, chave, i;
 
  //populando a arvore
  scanf("%d", &N); //numero de chaves a inserir
  for(i=0; i<N; ++i)
  {
    scanf("%d", &chave);    
    insereNoABP(&raiz, chave);   
  }
  emOrdem(raiz);//imprime toda arvore em ordem crescente.

  //buscando na arvore
  scanf("%d", &N); //numero de chaves a buscar
  for(i=0; i<N; ++i)
  {
    scanf("%d", &chave);    
    printf("%d\n", buscaNoABP(raiz, chave));
  }

  //removendo na arvore
  scanf("%d", &N);//numero de nos a remover
  for(i=0; i<N; ++i)
  {
    scanf("%d", &chave);    
    removeNoABP(&raiz, chave);
  }
  emOrdem(raiz);//imprime toda arvore em ordem crescente.
  return 0;
}