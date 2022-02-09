/*Feito pelo gcc Linux*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
char nome[15];
int idade;
char vacina[15]; //nome da vacina que tomou
}TPessoa; 

TPessoa *relatorio(TPessoa *p1, int n1, TPessoa *p2, int n2);

void main(){
	int opcao, resVacina, i, k;
	int *ptri, *ptrk;
	ptri = &i;
	ptrk = &k;

	TPessoa *pessoa = (TPessoa *)malloc(20 * sizeof(TPessoa));
	TPessoa *vacinados1 = (TPessoa *)malloc(20 * sizeof(TPessoa));
	TPessoa *vacinados2 = (TPessoa *)malloc(20 * sizeof(TPessoa));
	
	if(pessoa == NULL || vacinados1 == NULL|| vacinados2 == NULL){
		printf("Alocacao invalida!\n");
	}
	printf("***CONTROLE APLICACAO DE VACINAS***\n");

	i = 0;

	FILE *primeiraDose;
	primeiraDose = fopen("vacinados1adose.dat", "r");
	if(primeiraDose == NULL){
		printf("Nao foi possivel realizar a abertura do arquivo informado!\n");
	} else {
		while(!(feof(primeiraDose))){
			fscanf(primeiraDose, "%s %d %s", &(vacinados1 + i)->nome, &(vacinados1 + i)->idade, &(vacinados1 + i)->vacina);
			i++;	
		if(feof(primeiraDose)) break;	
		}
	}
	fclose(primeiraDose);
	primeiraDose = NULL;

	k = 0;

	FILE *segundaDose;
	segundaDose = fopen("vacinados2adose.txt", "r");
	if(segundaDose == NULL){
		printf("Nao foi possivel realizar a abertura do arquivo informado!\n");
	} else {
		while(!(feof(segundaDose))){			
	fscanf(segundaDose, "%s %d %s", &(vacinados2+k)->nome, &(vacinados2+k)->idade, &(vacinados2+k)->vacina);
		k++;
		if(feof(segundaDose)) break;		
		}					
	}
	fclose(segundaDose);
	segundaDose = NULL;

	do{
	printf("\nMENU:\n1 – Busca pessoa - vacina\n2 – Relatorio pessoas com pendencia de 2a dose\n3 - Encerrar consulta\n");
		printf("\nInsira a opcao desejada:\n");
		scanf("%d", &opcao);
		setbuf(stdin, NULL);
	switch(opcao){
		case 1:
			printf("\nBusca pessoa - vacina\n");
			printf("Insira o nome da pessoa consultada, por favor: ");
			setbuf(stdin, NULL);
			scanf("%s", &(pessoa)->nome);
			setbuf(stdin, NULL);

			int aux;
			int comp1;
			int comp2;
			for(int j = 0; j < i; j++){
				comp1 = strcmp(pessoa->nome,(vacinados1 + j)->nome);
				if(comp1 == 0){
					for(int l = 0; l < k; l++){
						comp2 = strcmp(pessoa->nome,(vacinados2 + l)->nome);														
						if(comp2 == 0){
						printf("\n%s ja tomou as duas doses!\n", pessoa->nome);
						break;
						}								
					} if(comp2 != 0){
						printf("\n%s ira tomar a 2a dose!\n", pessoa->nome);
						printf("A primeira dose tomada por %s foi da: %s\n", pessoa->nome, (vacinados1+j)->vacina);
						aux = j;
						break;
					}
				}
				if(comp1 != 0 && comp2 != 0 && j == (i-1)){
					printf("\n%s ira tomar a 1a dose!\n", pessoa->nome);
				}
			}

			printf("AUX = %d", aux);

			if(comp1 == 0){
				printf("\nVacinacao da segunda dose foi efetuada com sucesso?(1:sim/2:nao)\n");
				scanf("%d", &resVacina);
				if(resVacina == 1){
					FILE *segundaDose;
					segundaDose = fopen("vacinados2adose.txt", "a");
					if(segundaDose == NULL){
						printf("Nao foi possivel abrir o arquivo.\n");
					} else{
						fprintf(segundaDose, "\n%s %d %s", (vacinados1 + aux)->nome, (vacinados1 + aux)->idade, (vacinados1 + aux)->vacina);
					}
					fclose(segundaDose);
				} else{
					printf("Tente novamente a aplicacao da segunda dose, por favor!\n");
				}
			} else if(comp2 != 0){
				printf("\nVacinacao da primeira dose foi efetuada com sucesso?(1:sim/2:nao)\n");
				scanf("%d", &resVacina);
				if(resVacina == 1){
					printf("Insira a idade de %s: ", pessoa->nome);
					scanf("%d", &pessoa->idade);
					printf("Insira de qual vacina esta pessoa tomou: ");
					scanf("%s", &pessoa->vacina);

					FILE *primeiraDose;
					primeiraDose = fopen("vacinados1adose.dat", "a");
					if(primeiraDose == NULL){
						printf("Nao foi possivel abrir o arquivo.\n");
					} else {
						fprintf(primeiraDose, "\n%s %d %s", pessoa->nome, pessoa->idade, pessoa->vacina);
						}
						fclose(primeiraDose);
				} else{
					printf("Tente novamente a aplicacao da primeira dose, por favor!\n");
				}
			}
			break;
			case 2:
				printf("\nRelatório pessoas com pendencia de 2a dose\n");
				TPessoa *p3 = (TPessoa *)malloc(10 * sizeof(TPessoa));
				p3 = relatorio(vacinados1, i, vacinados2, k);
				if(p3 == NULL){
					printf("Nao foi possivel alocar o vetor!\n");
				} else {
					for(int j = 0; j < k; j ++){
						printf("%s ainda nao tomou as duas doses!\n", (p3 + j)->nome);
					}
				}
			break;
			default:
				printf("Obrigado pelos seus servicos!\n");
		}
	} while(opcao == 1 || opcao == 2 || opcao != 3);
}

TPessoa *relatorio(TPessoa *p1, int n1, TPessoa *p2, int n2){
	TPessoa *aux = (TPessoa *)malloc(n2 * sizeof(TPessoa));
	if(aux == NULL){
		return NULL;
	} else {
		int comp1;
		int cont = 0;;
		for(int j = 0; j < n1; j++){
			for(int l = 0; l < n2; l++){
				comp1 = strcmp((p1 + j)->nome, (p2 + l)->nome);
				if(comp1 == 0){
					break;
				} else if(l == (n2 - 1) && comp1 != 0){
					strcpy((aux + cont)->nome, (p1 + j)->nome);
					++cont;
				}
			}
		}
	}

	return aux;
}