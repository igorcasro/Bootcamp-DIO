#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int TipoChave;
typedef int TipoValor;
struct TipoListaSimples
{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaSimples *prox;
};
typedef struct TipoListaSimples TipoListaSimples;


//Começo da declaraçao das funçoes

TipoListaSimples *criaLista();
void imprimeLista(TipoListaSimples *prim);
TipoListaSimples *insereInicioListaSimples(TipoListaSimples *cabeca, TipoChave chave, TipoValor valorQualquer);
TipoListaSimples *alocaNo(TipoChave chave, TipoValor valorQualquer);


//Fim da declaraçao das funçoes

void main(){
	TipoListaSimples *NoC = criaLista();

	printf("1\n");
	imprimeLista(NoC);

	NoC = insereInicioListaSimples(NoC, 1, 2);
	printf("2\n");
	imprimeLista(NoC);

	NoC = insereInicioListaSimples(NoC, 3, 4);
	printf("3\n");
	imprimeLista(NoC);
}

//Inicio das funçoes

TipoListaSimples *criaLista() {
	TipoListaSimples *cabeca = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	if(cabeca == NULL){
		return NULL;
	} else {
		cabeca->chave = -1;
		cabeca ->valorQualquer = cabeca->chave;
		cabeca->prox = NULL;
		return cabeca;
	}
}

void imprimeLista(TipoListaSimples *prim){
	while(prim != NULL){
		if(prim->chave == -1 && prim->valorQualquer == prim->chave){
			printf("No cabeca: ");
		}
		printf("%d %d %p %p\n", prim->chave, prim->valorQualquer, prim->prox, prim);
		prim = prim->prox;
	}
}

TipoListaSimples *insereInicioListaSimples(TipoListaSimples *cabeca, TipoChave chave, TipoValor valorQualquer){
	TipoListaSimples *prim = alocaNo(chave, valorQualquer);
	if(prim == NULL) {
		return NULL;
	} else {
		prim->prox = cabeca->prox;
		cabeca->prox = prim;
		return cabeca;
	}
}

TipoListaSimples *alocaNo(TipoChave chave, TipoValor valorQualquer){
	TipoListaSimples *novo = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
	if(novo == NULL){
		return NULL;
	} else {
		novo->chave = chave;
		novo->valorQualquer = valorQualquer;
		novo->prox = NULL;
		return novo;
	}
}

//Fim das funçoes