//Feito e compilado via LINUX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declara uma Lista Duplamente encadeada para gravar as criancas em circulo
typedef struct listaCrianca{
	char nome[30];
	int valor;
	struct listaCrianca *prox;
	struct listaCrianca *ant;
} crianca;
//Declara uma Lista Cabeca para manter controle do primeiro e ultimo ponteiros
typedef struct listaCabeca{
	crianca *prim;
	crianca *ult;
} cabeca;

//Inicio declaracao das funcoes
cabeca *alocaCabeca();
crianca *alocaCrianca(char *nome, int valor);
void imprimeLista(cabeca *cabe, int quant);
crianca *insere(cabeca **cabe, crianca *cria, char *nome, int valor);
crianca *retiraCrianca(cabeca **cabe, crianca **cria);
crianca *desaloca(cabeca **cabe, crianca **cria);
//Fim declaracao das funcoes

void main(){
	char nomeInserido[30];
	int valorInserido = 0, numCrianca = 0;
	cabeca *cabe = alocaCabeca();
	crianca *cria = NULL;

	printf("****ACAMPAMENTO DE FERIAS****\n\n");
	do{
		printf("Insira o numero de criancas que participarao da brincadeira (de 1 a 100): ");
		scanf("%d", &numCrianca);
	} while(numCrianca < 1 || numCrianca > 500);

	for(int i = 0; i < numCrianca; i++){
		printf("\nInsira o nome e o valor atribuido a crianca %d\n", (i + 1));
		printf("Nome (se for composto separar com _): ");
		scanf("%s", nomeInserido);
		do{
			printf("Valor atribuido a/ao %s(de 1 a 500): ", nomeInserido);
			scanf("%d", &valorInserido);
		} while(valorInserido < 1 || valorInserido > 500);
		cria = insere(&cabe, cria, nomeInserido, valorInserido);
	}

	cria = retiraCrianca(&cabe, &cria);
	printf("\nVencedor(a): %s\n", cria->nome);
}

//Inicio da implementacao das funcoes
cabeca *alocaCabeca(){
	cabeca *no = (cabeca *)malloc(sizeof(cabeca));
	if(no != NULL){
			no->prim = NULL;
			no->ult = NULL;
			return no;
	} else {
		return NULL;
	}
}

crianca *alocaCrianca(char *nome, int valor){
	crianca *no = (crianca *)malloc(sizeof(crianca));
	if(no != NULL){
		strcpy(no->nome, nome);
		no->valor = valor; 
		no->prox = NULL;
		no->ant = NULL;
		return no;
	} else {
		return NULL;
	}
}

void imprimeLista(cabeca *cabe, int quant){
	crianca *aux = cabe->prim;
	if(aux == NULL){
		printf("Lista de criancas esta vazia!\n");
	} else {
		for(int i = 0; i < quant; i++){
			printf("%s %d\n", aux->nome, aux->valor);
			aux = aux->prox;;
		}
	}
}

crianca *insere(cabeca **cabe, crianca *cria, char *nome, int valor){
	crianca *no = alocaCrianca(nome, valor);
	crianca *aux = cria;
	crianca *aux2 = NULL;

	if(no != NULL){
		if((*cabe)->prim == NULL){
			no->prox = no;
			no->ant = no;
			(*cabe)->prim = no;
			(*cabe)->ult = no;
			return no;
		} else{
			if((*cabe)->prim == (*cabe)->ult){
				no->prox = aux;
				no->ant = aux;
				(*cabe)->ult = no;
				aux->prox = no;
				aux->ant = no;				
				return aux;
			} else {
				aux2 = cria->ant;
				no->prox = aux;
				no->ant = aux->ant;
				aux->ant = no;
				aux2->prox = no;
				(*cabe)->ult = no;
				return no->prox;
			}
		}
	} else {
		return NULL;
	}
}

crianca *retiraCrianca(cabeca **cabe, crianca **cria){
	crianca *apaga = *cria;

	int aux = apaga->valor;
	char nome[30];
	strcpy(nome, apaga->nome);

	if((*cabe)->prim == (*cabe)->ult){
		return *cria;
	} else {
		while((*cabe)->prim != (*cabe)->ult){
			if(aux % 2 == 0){
				for(int i = 0; i < aux; i++){
					apaga = apaga->prox;
				}
			} else {
				for(int i = 0; i < aux; i++){
					apaga = apaga->ant;
				}
			}
			aux = apaga->valor;
			*cria = desaloca(cabe, &apaga);	
			apaga = apaga->prox;
		}
		return *cria;
	}
}

crianca *desaloca(cabeca **cabe, crianca **cria){
	crianca *aux = *cria;

	if(aux == (*cabe)->prim){
		(*cabe)->prim = aux->prox;
		aux = (*cria)->prox;
		free(*cria);
		*cria = NULL;
		*cria = aux;
		return *cria;
	} else if(aux == (*cabe)->ult){
		aux = aux->ant;
		aux->prox = (*cabe)->prim;
		(*cabe)->ult = aux;
		free(*cria);
		*cria = NULL;
		*cria = (*cabe)->prim;
		return *cria;
	} else {
		crianca *aux2 = aux->ant;
		aux = aux->prox;
		aux2->prox = aux;
		aux->ant = aux2;
		free(*cria);
		*cria = NULL;
		*cria = aux2;
		return (*cabe)->prim;
	}
}
//Fim da implementacao das funcoes