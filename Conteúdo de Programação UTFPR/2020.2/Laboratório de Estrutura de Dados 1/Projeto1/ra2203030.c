#include <stdio.h>
#include <stdlib.h>

void ler_aposta(int *aposta, int n);
void ler_numeros_sorteados(int **sorteio, int ns); //inclui quantidade dos numeros sorteados para caso haja alguma alteracao no sorteio, mas precisa ser atualizado na main tambem, caso haja alteracao
int* comparar_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);
void desaloca(int **p);

int main(){
	char opcao;
	int qtdNum, qtdSort = 6, *numeroIguais, numApostas;
	int *numerosSorteados = (int *)malloc(qtdSort * sizeof(int));
	int *numeroAcertos = (int *)malloc(sizeof(int));

	if(numerosSorteados == NULL){
		printf("Nao foi possivel alocar memoria para a quantidade de numeros sorteados!\n");
		return -1;
	}
	do{
		printf("Insira o numero de apostas que sera realizado(positivo e diferente de 0): ");
		scanf("%d", &numApostas);
	} while(numApostas < 1);

	while(numApostas > 0){
		do{
			printf("\nInsira a quantidade de numeros que serao apostados(6 a 15): ");
			scanf("%d", &qtdNum);
		} while(qtdNum < 6 || qtdNum > 15);

		int *numApostados = (int *)malloc(qtdNum * sizeof(int));
	
		if(numApostados == NULL){
			printf("Nao foi possivel alocar memoria para a quantidade de numeros apostados!\n");
			return -1;
		}

		ler_aposta(numApostados, qtdNum);
		ler_numeros_sorteados(&numerosSorteados, qtdSort);
		for(int i = 0; i < 6; i++){
			if(qtdSort != 6 || *(numerosSorteados + i) < 1 || *(numerosSorteados + i) > 60){
				printf("Favor verificar o arquivo milionario.dat! Erro encontrado!\n");
				return -1;
			}
		}	
		numeroIguais = comparar_aposta(numApostados, numerosSorteados, numeroAcertos, qtdNum, qtdSort);
		
		if(*numeroAcertos == qtdSort){
			printf("\n***VOCE FICOU RICO! #sqn***\n\n");
		} else{
			printf("\n***NAO FOI NESSE SORTEIO QUE VOCE FICOU RICO :/ ***\n\n");
		}
		printf("QUANTIDADE DE ACERTOS: %d\n", *numeroAcertos);
		printf("NUMEROS ACERTADOS: \n");
		for(int i = 0; i < *numeroAcertos; i++){
			printf("%d  ", *(numeroIguais + i));
		}
		if(numApostas > 1){
			*numeroAcertos = 0;
		}

		printf("\n");

		desaloca(&numApostados);
		
		
		--numApostas;
	}

	desaloca(&numeroAcertos);
	desaloca(&numerosSorteados);

	return 0;
}

void ler_aposta(int *aposta, int n){
	printf("INSIRA SUA APOSTA(01 ATE 60)\n\n");
	for(int i = 0; i < n; i++){
		do{
			printf("Numero %d = ", i + 1);
			scanf("%d", aposta + i);
		} while(*(aposta + i) < 1 || *(aposta + i) > 60);
	}
}

void ler_numeros_sorteados(int **sorteio, int ns){
	int i = 0;
	int *aux = (int *)malloc(ns*sizeof(int));

	FILE *sorteados;
	sorteados = fopen("milionario.dat", "r");
	
	if(sorteados == NULL){
		printf("Nao foi possivel abrir o arquivo informado!\n");
	}
	while(!(feof(sorteados))){
		if(feof(sorteados)) break;
			fscanf(sorteados, "%d", *(sorteio) + i);
			++i;

	}

	fclose(sorteados);
	sorteados = NULL;
}

int* comparar_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	int *iguais = (int *)malloc(sizeof(int));
	int cont = 0; //serve para ver qual posicao do vetor iguais estah

	for(int i = 0; i < na; i++){
		for(int j = 0; j < ns; j++){
			if(*(aposta + i) == *(sorteio + j)){
				*(iguais + cont) = *(aposta + i);
				++(*qtdacertos);
				++cont;
			}
		}
	}

	return iguais;
}

void desaloca(int **p){
	free(*p);
	*p = NULL;
}