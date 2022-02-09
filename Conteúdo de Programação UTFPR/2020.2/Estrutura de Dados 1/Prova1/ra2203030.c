//FEITO E COMPILADO VIA GCC LINUX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UTI{
	char nome[20];
	int idade;
	struct UTI *prox;
};
typedef struct UTI UTI;


UTI *alocaNo(char nome[20], int idade);
UTI *alocaCrescente(UTI **prim, char nome[20], int idade);
void imprimeNos(UTI *prim);
void liberaLeito(UTI **prim1, UTI **prim2, UTI **prim3, char nome[20]);
int quantPacientes(UTI **prim);

void main(){
	int opcao, opcao2, numUTI, idade, qtd1, qtd2, qtdLista, acomodado, obrigacao;
	UTI *UTI1 = NULL, *UTI2 = NULL, *ListaDeEspera = NULL;

	do{	
		char *nome =(char *)malloc(20*sizeof(char));
		
		printf("\n***PROTOCOLO INTERNACOES***\n\n");

		printf("MENU:\n1) Internar Paciente\n2) Consultar Pacientes\n3) Liberar Leito\n4) Internar Emergencial\n5) Sair\n");
		printf("Insira a opcao desejada: ");
		setbuf(stdin, NULL);
		scanf("%d", &opcao);
		setbuf(stdin, NULL);

		switch(opcao){
			case 1:
				printf("\nInternar Paciente\n");
				if(ListaDeEspera != NULL){
					printf("\nExistem pacientes na Lista De Espera.\n");
				} else {
					printf("\nAinda nao existem pacientes na Lista De Espera!\n");
				}
				printf("1) Inserir novo paciente na fila de espera\n2) Prosseguir com internamento\n");
				printf("Insira a opcao desejada: ");
				setbuf(stdin, NULL);
				scanf("%d", &opcao2);
				setbuf(stdin, NULL);
				if(opcao2 == 1){
					printf("\nInserir o paciente na fila de espera\n");
					if(ListaDeEspera == NULL){						
						printf("Insira o nome do paciente: ");
						scanf("%s", nome);
						printf("Insira a idade do paciente: ");
						scanf("%d", &idade);
						ListaDeEspera = alocaNo(nome, idade);						
						free(nome);
					} else {
						printf("Insira o nome do paciente: ");
						scanf("%s", nome);
						printf("Insira a idade do paciente: ");
						scanf("%d", &idade);
						ListaDeEspera = alocaCrescente(&ListaDeEspera, nome, idade);
						free(nome);
					}
				} else if(opcao2 == 2){
					printf("\nProsseguir com o internamento\n");
					printf("Qual UTI deseja alocar o paciente?\n1) UTI1\n2) UTI2\n");
					printf("Insira a opcao desejada: ");
					scanf("%d", &numUTI);
					if(numUTI == 1){
						if(UTI1 == NULL){
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI1 = alocaNo(nome, idade);
							free(nome);
						} else {
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI1 = alocaCrescente(&UTI1, nome, idade);
							free(nome);
						}
					} else if(numUTI == 2){
						if(UTI2 == NULL){
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI2 = alocaNo(nome, idade);
							free(nome);
						} else {
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI2 = alocaCrescente(&UTI2, nome, idade);
							free(nome);
						}
					} else {
						printf("UTI invalida!\n");
					}
				} else {
					printf("Opcao Invalida!\n");
				}
			break;
			case 2:
				printf("\nConsultar Pacientes\n");
				printf("***UTI 1***\n");
				if(UTI1 == NULL){
					printf("Nao ha pacientes internados na UTI1!\n");
				} else {
					imprimeNos(UTI1);
				}
				printf("***UTI 2***\n");
				if(UTI2 == NULL){
					printf("Nao ha pacientes internados na UTI2!\n");
				} else {
					imprimeNos(UTI2);
				}
				printf("***LISTA DE ESPERA***\n");
				if(ListaDeEspera == NULL){
					printf("Nao ha pacientes na Lista De Espera!\n");
				} else {
					imprimeNos(ListaDeEspera);
				}
			break;
			case 3:
				printf("\nLiberar Leito\n");
				printf("Insira o nome do paciente que recebeu alta, por favor: ");
				scanf("%s", nome);
				liberaLeito(&UTI1, &UTI2, &ListaDeEspera, nome);
			break;
			case 4:
				printf("\nInternar Emergencial\n");
				qtd1 = quantPacientes(&UTI1);
				qtd2 = quantPacientes(&UTI2);
				qtdLista = quantPacientes(&ListaDeEspera);
				printf("Na UTI 1 temos: %d leito(s) ocupado(s)\n", qtd1);
				printf("Na UTI 2 temos: %d leito(s) ocupado(s)\n", qtd2);
				printf("Na Lista De Espera temos: %d paciente(s)\n", qtdLista);
				if(qtd1 <= qtd2){
					obrigacao = 1;
					printf("\nFavor alocar o paciente EMERGENCIAL na UTI1!\n");
				} else {
					obrigacao = 2;
					printf("\nFavor alocar o paciente EMERGENCIAL na UTI2!\n");
				}
				printf("Favor confirmar o internamento indicando qual UTI o paciente sera acomodado(1 ou 2)\n");
				do{
					printf("UTI numero: ");
					scanf("%d", &acomodado);
				} while(acomodado < 1 || acomodado > 2);
				if(acomodado == obrigacao){
					printf("***UTI %d***\n", obrigacao);
					if(obrigacao == 1){
						if(UTI1 == NULL){
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI1 = alocaNo(nome, idade);
							free(nome);
						} else {
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI1 = alocaCrescente(&UTI1, nome, idade);
							free(nome);
						}
					} else {
						if(UTI2 == NULL){
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI2 = alocaNo(nome, idade);
							free(nome);
						} else {
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI2 = alocaCrescente(&UTI2, nome, idade);
							free(nome);
						}
					}
				} else {
					printf("Por ordens superiores, estamos realocando o paciente para a UTI %d. Conclua seu internamento!\n", obrigacao);
					if(obrigacao == 1){
						if(UTI1 == NULL){
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI1 = alocaNo(nome, idade);
							free(nome);
						} else {
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI1 = alocaCrescente(&UTI1, nome, idade);
							free(nome);
						}
					} else {
						if(UTI2 == NULL){
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI2 = alocaNo(nome, idade);
							free(nome);
						} else {
							printf("Insira o nome do paciente: ");
							scanf("%s", nome);
							printf("Insira a idade do paciente: ");
							scanf("%d", &idade);
							UTI2 = alocaCrescente(&UTI2, nome, idade);
							free(nome);
						}		
					}
				}
			break;
			case 5:
				printf("\nSair\nObrigado pelos seus serviços!\n");
			break;
			default:
				printf("\nOpcao inexistente!\n");
			break;
		}
	} while(opcao != 5);

}

UTI *alocaNo(char nome[20], int idade){
	UTI *no;
	no = (UTI *)malloc(sizeof(UTI));

	if(no == NULL){
		printf("Nao foi possivel alocar tal paciente!\n");
		return NULL;
	} else {
		strcpy(no->nome, nome);
		no->idade = idade;
		no->prox = NULL;
		return no;
	}
}

UTI *alocaCrescente(UTI **prim, char nome[20], int idade){
	UTI *noAux = alocaNo(nome, idade);
	UTI *percorre = *prim;
	UTI *anterior;

	if(noAux == NULL){
		printf("Nao foi possivel alocar tal paciente!\n");
		return NULL;
	} else {
		while(percorre != NULL){
			if(noAux->idade <= percorre->idade){
				if(percorre == *prim){
					noAux->prox = *prim;
					*prim = noAux;
					return noAux;
				} else {
					noAux->prox = percorre;
					anterior->prox = noAux;
					return *prim;
				}
			}
			if(percorre->prox == NULL){
				percorre->prox = noAux;
				return *prim;
			}
			anterior = percorre;
			percorre = percorre->prox;
		}
	}
}

void imprimeNos(UTI *prim){
	while(prim != NULL){
		printf("%s %d\n", prim->nome, prim->idade);
		prim = prim->prox;
	}
}

void liberaLeito(UTI **prim1, UTI **prim2, UTI **prim3, char nome[20]){
	UTI *percorre1 = *prim1;
	UTI *percorre2 = *prim2;
	UTI *percorre3 = *prim3;
	UTI *anterior1, *anterior2;
	int comp;

	while(percorre1 != NULL){
		comp = strcmp(nome, percorre1->nome);
		if(comp == 0){
			if(percorre1->prox == NULL && percorre1 != *prim1){
				free(percorre1);
				percorre1 = NULL;
				anterior1->prox = NULL;
				if(*prim3 != NULL){
					*prim1 = alocaCrescente(prim1, percorre3->nome, percorre3->idade);
					*prim3 = percorre3->prox;
					free(percorre3);
					percorre3 = NULL;
				}
				break;
			} else if(percorre1 == *prim1){
				*prim1 = percorre1->prox;
				free(percorre1);
				percorre1 = NULL;
				if(*prim3 != NULL){
					*prim1 = alocaCrescente(prim1, percorre3->nome, percorre3->idade);
					*prim3 = percorre3->prox;
					free(percorre3);
					percorre3 = NULL;
				}
				break;
			} else {
				anterior1->prox = percorre1->prox;
				free(percorre1);
				percorre1 = NULL;
				if(*prim3 != NULL){
					*prim1 = alocaCrescente(prim1, percorre3->nome, percorre3->idade);
					*prim3 = percorre3->prox;
					free(percorre3);
					percorre3 = NULL;
				}
				break;
			}
		} else {	
			anterior1 = percorre1;		
			percorre1 = percorre1->prox;
		}
	}
	if(percorre1 == NULL && comp != 0){
		while(percorre2 != NULL){
			comp = strcmp(nome, percorre2->nome);
			if(comp == 0){
				if(percorre2->prox == NULL && percorre2 != *prim2){
					free(percorre2);
					percorre2 = NULL;
					anterior2->prox = NULL;
					if(*prim3 != NULL){
						*prim2 = alocaCrescente(prim2, percorre3->nome, percorre3->idade);
						*prim3 = percorre3->prox;
						free(percorre3);
						percorre3 = NULL;
					}
					break;
				} else if(percorre2 == *prim2){
					*prim2 = percorre2->prox;
					free(percorre2);
					percorre2 = NULL;
					if(*prim3 != NULL){
						*prim2 = alocaCrescente(prim2, percorre3->nome, percorre3->idade);
						*prim3 = percorre3->prox;
						free(percorre3);
						percorre3 = NULL;
					}
					break;
				} else {
					anterior2->prox = percorre2->prox;
					free(percorre2);
					percorre2 = NULL;
					if(*prim3 != NULL){
						*prim2 = alocaCrescente(prim2, percorre3->nome, percorre3->idade);
						*prim3 = percorre3->prox;
						free(percorre3);
						percorre3 = NULL;
					}
					break;
				}				
			} else {	
				anterior2 = percorre2;		
				percorre2 = percorre2->prox;
			}
		}
	}
	if(percorre1 == NULL && percorre2 == NULL && comp != 0){
			printf("Paciente nao encontrado!\n");
	}
}

int quantPacientes(UTI **prim){
	int quant = 0;
	UTI *percorre = *prim;

	if(percorre == NULL){
		return 0;
	} else {
		while(percorre != NULL){
			++quant;
			percorre = percorre->prox;
		}
	}

	return quant;
}