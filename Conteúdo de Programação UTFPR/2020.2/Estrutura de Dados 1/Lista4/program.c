#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bib.h"

void main() {
	TipoListaSimples *prim = NULL, *procurado, *seg = NULL, *intersec = NULL;
	prim = alocaNo(1, 2);
	
	atualizaValor(prim, 2);
	
	prim = insereInicioListaSimples(&prim, 3, 4);
	prim = insereInicioListaSimples(&prim, 5, 6);
	prim = insereInicioListaSimples(&prim, 7, 8);	
	
/*	printf("1\n");
	imprimeNos(prim);
	
	removePrimeiroNo(&prim);
	printf("2\n");
	imprimeNos(prim);

	printf("3\n");
	procurado = pesquisaNo(prim, 5);
	if(!procurado) {
		printf("Nao foi encontrada tal chave!\n");
	}

	prim = insereFimListaSimples(&prim, 9, 10);
	printf("4\n");
	imprimeNos(prim);

	removeUltimoNo(&prim);
	printf("5\n");
	imprimeNos(prim);

	removeNo(&prim, 3);
	printf("6\n");
	imprimeNos(prim);

	liberaNos(&prim);
	printf("7\n");
	imprimeNos(prim);

	seg = copiaListas(prim);
	printf("8\n");
	imprimeNos(seg);
*/
	seg = alocaNo(1, 2);
	seg = insereInicioListaSimples(&seg, 2, 4);
	seg = insereInicioListaSimples(&seg, 5, 6);
	seg = insereInicioListaSimples(&seg, 6, 8);
	intersec = intersecaoListas(prim, seg);
	printf("9\n");
	imprimeNos(intersec);
}