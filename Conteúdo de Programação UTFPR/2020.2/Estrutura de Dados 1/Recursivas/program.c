#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int TipoChave;
typedef int TipoValor;
struct TipoListaSimples
{
	TipoChave chave;
	struct TipoListaSimples *prox;
};
typedef struct TipoListaSimples TipoListaSimples;


TipoListaSimples *alocaNo(TipoChave chave);
void imprimeLista(TipoListaSimples *prim);
TipoListaSimples *insereInicioListaSimples(TipoListaSimples *prim, TipoChave chave);
void insereFimRecursivo(TipoListaSimples **prim, TipoChave chave);
void buscaRecursivo(TipoListaSimples **prim, TipoChave chave);

void main(){
	TipoListaSimples *prim = alocaNo(1);

	prim = insereInicioListaSimples(prim, 2);
	prim = insereInicioListaSimples(prim, 3);
	prim = insereInicioListaSimples(prim, 4);
	prim = insereInicioListaSimples(prim, 5);

	TipoListaSimples *novo = prim;

	insereFimRecursivo(&novo, 0);
	imprimeLista(prim);

	printf("Linha 34.\n");
	buscaRecursivo(&prim, -3);
	printf("Linha 36.\n");
}

TipoListaSimples *alocaNo(TipoChave chave){
	TipoListaSimples *prim = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	if(prim == NULL){
		return NULL;
	} else {
		prim->chave = chave;
		prim->prox = NULL;
		return prim;
	}
}

void imprimeLista(TipoListaSimples *prim){
	while(prim != NULL){
		printf("%d %p %p\n", prim->chave, prim->prox, prim);
		prim = prim->prox;
	}
}

TipoListaSimples *insereInicioListaSimples(TipoListaSimples *prim, TipoChave chave){
	TipoListaSimples *noAux = alocaNo(chave);

	if(noAux == NULL){
		return NULL;
	} else {
		noAux->prox = prim;
		return noAux;
	}
}

void insereFimRecursivo(TipoListaSimples **prim, TipoChave chave){
	if((*prim)->prox == NULL) {
		TipoListaSimples *noAux = alocaNo(chave);
		(*prim)->prox = noAux;
	} else if(*prim == NULL){
		*prim = alocaNo(chave);
	} else {
		*prim = (*prim)->prox;
		insereFimRecursivo(&(*prim), chave);
	}
}

void buscaRecursivo(TipoListaSimples **prim, TipoChave chave){
	if((*prim)->chave == chave) {
		printf("Sua lista possui o valor %d, seu broxinha.\n", chave);
	} else if(*prim == NULL){
		printf("Nao foi encontrado o valor %d na lista kk pena\n", chave);
	} else {
		buscaRecursivo(&(*prim)->prox, chave);
	}
}