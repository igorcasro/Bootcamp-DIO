#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bib.h"


TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor){
	assert(prim);
	TipoListaSimples *noAux = alocaNo(chave, valor);

	if(noAux == NULL) return NULL;
	noAux->prox = *prim;
	*prim = noAux;

	return noAux;
}

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor){

	if(prim != NULL){
		prim->valorQualquer = novoValor;
	}

}

void removePrimeiroNo(TipoListaSimples **prim){
	assert(*prim);
	if(prim){
		TipoListaSimples *noAux = *prim;
		*prim = (*prim)->prox;
		free(noAux);
		noAux = NULL;
	}
}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave){
	assert(prim);
	TipoListaSimples *noAux = prim;

	if(prim == NULL) return NULL;

	while(noAux != NULL){	
		if(noAux->chave == chave){
			printf("ENCONTRADO: %d %d %p %p\n", noAux->chave, noAux->valorQualquer, noAux->prox, noAux);
			return noAux;
		}
		noAux = noAux->prox;
	}
	return NULL;
}

TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim,TipoChave chave, TipoValor valor){
	assert(*prim);
	TipoListaSimples *percorre = *prim;
	TipoListaSimples *noAux = alocaNo(chave, valor);

	if(noAux == NULL) return NULL;
	
	while(percorre->prox != NULL){
		percorre = percorre->prox;
	}

	percorre->prox = noAux;

	return *prim;
}

void removeUltimoNo(TipoListaSimples **prim){
	assert(*prim);
	TipoListaSimples *percorre = *prim;

	if(percorre != NULL){
		while(percorre->prox->prox != NULL){
			percorre = percorre->prox;
		}
		free(percorre->prox->prox);
		percorre->prox->prox = NULL;

		percorre->prox = NULL;
	}
}

void removeNo(TipoListaSimples **prim, TipoChave chave){
	assert(*prim);
	TipoListaSimples *percorre = *prim;
	TipoListaSimples *anterior = alocaNo(percorre->chave, percorre->valorQualquer);

	if(percorre != NULL){
		do {
			if(percorre->chave == chave){
				if(percorre->prox == NULL){
					removeUltimoNo(prim);
					break;
				} else if(percorre == *prim){
					*prim = percorre->prox;
					free(percorre);
					percorre = NULL;
					break;
				} else {
					anterior->prox = percorre->prox;
					free(percorre);
					percorre = NULL;
					break;
				}
			}
			anterior = percorre;
			percorre = percorre->prox;
		} while(percorre != NULL);
	}
}

void liberaNos(TipoListaSimples **prim){
	assert(*prim);

	TipoListaSimples *percorre = *prim;
	if(percorre != NULL){
		while(percorre->prox != NULL){
			removeUltimoNo(&percorre);
			percorre = percorre->prox;
		}
		if(percorre->prox == NULL){
			free(*prim);
			*prim = NULL;
		}
	}
}

TipoListaSimples *copiaListas(TipoListaSimples *prim){
	assert(prim);
	TipoListaSimples *copia, *noAux = NULL;
	TipoListaSimples *percorre = prim;
	int i = 0;

	if((percorre) == NULL && (copia) == NULL){
		printf("Erro de alocacao de memoria!\n");
		return NULL;
	} else {
		while(percorre != NULL){
			copia = alocaNo(percorre->chave, percorre->valorQualquer);
			copia->prox = noAux;
			noAux = copia; 
			percorre = percorre->prox;
		}
		return copia;
	} 
}

TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2){
	assert(prim1);
	assert(prim2);

	int i = 0;

	TipoListaSimples *intersecao, *noAux = NULL;
	TipoListaSimples *percorre1;
	TipoListaSimples *percorre2 = prim2;

	if(intersecao == NULL || percorre1 == NULL || percorre2 == NULL){
		printf("Erro de alocacao de memoria!\n");
		return NULL;
	} else {
		while(percorre2 != NULL){
			percorre1 = prim1;
			while(percorre1 != NULL){
				if(percorre1->chave == percorre2->chave){
					intersecao = alocaNo(percorre1->chave, percorre1->valorQualquer);
					intersecao->prox = noAux;
					noAux = intersecao; 
				}
				percorre1 = percorre1->prox;
			}
			percorre2 = percorre2->prox;
		}
		return intersecao;
	}
}

void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2){

}

void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2){

}

int contaNo(TipoListaSimples **primLista1){

}

int alturaNo(TipoListaSimples **primLista1, TipoChave chave){

}

int profundidadeNo(TipoListaSimples **primLista1, TipoChave chave){

}

TipoListaSimples *alocaNo(TipoChave chave, TipoValor valorQualquer){
	TipoListaSimples *no;
	no = (TipoListaSimples *) malloc(sizeof(TipoListaSimples)); 
    
    if (no == NULL) return NULL;
	no->chave = chave;
	no->valorQualquer = valorQualquer;
	no->prox = NULL;
	
	return no;
}

void imprimeNos(TipoListaSimples *prim){
	while(prim != NULL){
		printf("%d %d %p %p\n", prim->chave, prim->valorQualquer, prim->prox, prim);
		prim = prim->prox;
	}
}