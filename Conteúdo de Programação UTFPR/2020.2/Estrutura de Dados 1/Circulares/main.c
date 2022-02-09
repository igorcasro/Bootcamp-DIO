#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef int TipoValor;
struct TipoListaCircular{
 TipoChave chave;
 TipoValor valorQualquer;
 struct TipoListaCircular *prox;
};
typedef struct TipoListaCircular TipoListaCircular;

//Inicio da declaraçao das funçoes
/* -------------------------> Insercao
* Insere novo nó no início de uma lista encadeada circular.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaCircular *insereInicio(TipoListaCircular **prim, TipoChave chave, TipoValor valor);
/* -------------------------> Alocacao
* Tenta alocar no e, se nao conseguir, retorna NULL
*/
TipoListaCircular *alocaNo(TipoChave chave, TipoValor valor);
/* -------------------------> Impressao
* Caso exista nos em uma lista, faz a impressao
*/
void imprime(TipoListaCircular **prim);
/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaCircular **prim, TipoChave chave);
/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós tem valor chave par
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaCircular *copiaListaPar(TipoListaCircular *prim);
//Fim da declaraçao das funçoes

void main(){
	TipoListaCircular *no, *pares;

	printf("Insercao\n");
	no = insereInicio(&no, 2, 3);
	no = insereInicio(&no, 4, 5);
	no = insereInicio(&no, 6, 7);
	no = insereInicio(&no, 9, 8);
	no = insereInicio(&no, 15, 14);
	imprime(&no);

	printf("Remocao\n");
	removeNo(&no, 6);
	imprime(&no);

	printf("Pares\n");
	pares = copiaListaPar(no);
	imprime(&pares);
}

TipoListaCircular *alocaNo(TipoChave chave, TipoValor valor){
	TipoListaCircular *prim = (TipoListaCircular *)malloc(sizeof(TipoListaCircular));
	if(prim == NULL){
		return NULL;
	} else {
		prim->chave = chave;
		prim->valorQualquer = valor;
		prim->prox = prim;
		return prim;
	}
}

void imprime(TipoListaCircular **prim){
	TipoListaCircular *percorre = *prim;
	if(*prim == NULL){
		printf("Lista vazia!\n");
	} else if(percorre->prox == *prim){
		printf("%d %d %p %p\n", percorre->chave, percorre->valorQualquer, percorre->prox, percorre);
		percorre = percorre->prox;
	} else {
		do {
			printf("%d %d %p %p\n", percorre->chave, percorre->valorQualquer, percorre->prox, percorre);
			percorre = percorre->prox;
		} while(percorre != *prim);
	}
}

TipoListaCircular *insereInicio(TipoListaCircular **prim, TipoChave chave, TipoValor valor){
	TipoListaCircular *no = alocaNo(chave, valor);
	TipoListaCircular *aux = *prim;
	if(no == NULL){
		return NULL;
	} else {
		if(*prim == NULL){
			return no;
		} else {
			while(aux->prox != *prim){
				aux = aux->prox;
			}
			no->prox = (aux)->prox;
			(aux)->prox = no;
			aux = no;
			return no;
		}
	}
}

void removeNo(TipoListaCircular **prim, TipoChave chave) {
	TipoListaCircular *aux = *prim, *aux2, *first = *prim;

	if(aux == NULL){
		printf("Vetor vazio!\n");
	} else {
		if(*prim == (*prim)->prox){
			if(chave == aux->chave){
				free(*prim);
				*prim = NULL;
			} else {
				printf("Lista nao possui o valor %d como chave\n", chave);
			}
		} else {
			if(chave == (*prim)->chave){
				aux2 = *prim;
				while(aux2->prox != *prim){
					aux2 = aux2->prox;
				}
				aux2->prox = aux->prox;
				free(*prim);
				*prim = NULL;
				*prim = aux2->prox;
			} else {
				aux = aux->prox;
				aux2 = *prim;
				while(aux != *prim) {
					if(chave == aux->chave){
						*prim = aux;
						aux2->prox = aux->prox;
						free(*prim);
						*prim = NULL;
						while(aux2->prox != first){
							aux2 = aux2->prox;
						}
						*prim = aux2->prox;
						break;
					} else {
						aux2 = aux2->prox;						
						aux = aux->prox;
						if(aux == *prim){
							printf("Lista nao possui o valor %d como chave\n", chave);
						}
					}
				} 
			}
		}
	}
}

TipoListaCircular *copiaListaPar(TipoListaCircular *prim) {
	TipoListaCircular *par = NULL, *aux = prim;
	do {
		if(aux->chave % 2 == 0 || aux->chave == 0){
			par = insereInicio(&par, aux->chave, aux->valorQualquer);
		}
		aux = aux->prox;
	} while(aux != prim);
	return par;
}