#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef int TipoValor;
struct TipoListaEncadeada {
 TipoChave chave;
 TipoValor valorQualquer;
 struct TipoListaEncadeada *prox;
 struct TipoListaEncadeada *ant;
};
typedef struct TipoListaEncadeada TipoListaEncadeada;

/* -------------------------> Insercao inicio
* Insere novo nó no início de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor);
/* -------------------------> Insercao final
* Insere novo nó no final de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor);
/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaEncadeada **prim, TipoChave chave);
/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós são múltiplos de 3.
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim);

TipoListaEncadeada *aloca(TipoChave chave, TipoValor valorQualquer);

void imprime(TipoListaEncadeada *prim);

void main(){
	TipoListaEncadeada *prim = NULL, *seg = NULL;

	printf("Teste 1\n");
	imprime(prim);

	printf("Teste 2\n");
	prim = insereInicioListaEncadeada(&prim, 0, 1);
	imprime(prim);

	printf("Teste 3\n");
	prim = insereInicioListaEncadeada(&prim, 2, 3);
	imprime(prim);

	printf("Teste 4\n");
	prim = insereInicioListaEncadeada(&prim, 4, 5);
	imprime(prim);

	printf("Teste 1\n");
	imprime(seg);

	printf("Teste 2\n");
	seg = insereFimListaEncadeada(&seg, 6, 7);
	imprime(seg);

	printf("Teste 3\n");
	seg = insereFimListaEncadeada(&seg, 8, 9);
	imprime(seg);

	printf("Teste 4\n");
	seg = insereFimListaEncadeada(&seg, 10, 11);
	imprime(seg);

}

TipoListaEncadeada *aloca(TipoChave chave, TipoValor valorQualquer){
	TipoListaEncadeada *no = (TipoListaEncadeada *)malloc(sizeof(TipoListaEncadeada));

	if(no == NULL){
		return NULL;
	} else {
		no->chave = chave;
		no->valorQualquer = valorQualquer;
		no->prox = NULL;
		no->ant = NULL;
		return no;
	}
}

void imprime(TipoListaEncadeada *prim){
	TipoListaEncadeada *aux = prim;

	if(aux == NULL){
		printf("Nenhum valor na lista.\n");
	} else {
		do{
			if(aux->prox == aux){
				printf("%d %d %p %p %p\n", aux->chave, aux->valorQualquer, aux->prox, aux->ant, aux);
				break;
			} else {
				printf("%d %d %p %p %p\n", aux->chave, aux->valorQualquer, aux->prox, aux->ant, aux);
				aux = aux->prox;
			}			
		} while(aux != prim);
	}
}

TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor){
	TipoListaEncadeada *no = aloca(chave, valor), *aux = *prim;

	if(no != NULL){
		if(aux == NULL){
			no->prox = no;
			no->ant = no;
			aux = no;
			return aux;
		} else {
			if(aux->prox == aux->ant){
				no->prox = aux;
				no->ant = aux;
				aux = no;
				return aux;
			} else {
				no->prox = aux;
				aux->prox = no;
				no->ant = aux->ant;
				aux = no;
				return aux;
			}
		}
	} else {
		printf("Falha na alocacao.\n");
		return NULL;
	}
}

TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor){
	TipoListaEncadeada *no = aloca(chave, valor), *aux = *prim;

	if(no != NULL){
		if(aux == NULL){
			no->prox = no;
			no->ant = no;
			aux = no;
			return aux;
		} else {
			if(aux->prox == aux->ant){
				no->prox = aux;
				no->ant = aux;
				return no;
			} else {
				no->prox = aux;
				no->ant = aux->ant;
				return no;
			}
		}
	} else {
		printf("Falha na alocacao.\n");
		return NULL;
	}
}