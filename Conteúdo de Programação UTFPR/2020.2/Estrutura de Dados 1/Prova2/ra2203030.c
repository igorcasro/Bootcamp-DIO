// Codigo escrito e compilado via LINUX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
	char nome[20]; 		//nome do aluno
	float coeficiente;	//coeficiente
	struct aluno *prox;	//proximo aluno
}Aluno;

typedef struct cabeca{
	int num;			//numero de alunos na lista
	Aluno *prim;		//primeiro aluno da lista
	Aluno *ult;			//ultimo aluno da lista
}Cabeca;

//Inicio declaracao das funcoes
Aluno *alocaAluno(char *nome, float coeficiente);
void insereAlunoFim(Cabeca **cabeca, char *nome, float coeficiente);
void buscaMenor(Aluno *prim, Cabeca *cabeca);
void buscaAluno(char *nome, Cabeca **cabeca);
void removeAluno(char *nome, Cabeca **cabeca);
//Fim declaracao das funcoes

void main(){
	int op, auxQuant;
	char nomeInserido[20];
	float coeficienteInserido;
	Aluno *aux;

	Cabeca *cabecaAlunos = (Cabeca *)malloc(sizeof(Cabeca));
	if(cabecaAlunos != NULL){
		cabecaAlunos->num = 0;
		cabecaAlunos->prim = NULL;
		cabecaAlunos->ult = NULL;
	} else {
		printf("Nao foi possivel alocar o no cabeca da fila.\n");
	}

	do{
		printf("\n***MENU***\n");
		printf("1. Inserir Aluno\n");
		printf("2. Buscar Aluno\n");
		printf("3. Remover um Aluno\n");
		printf("4. Imprimir Alunos da Lista\n");
		printf("5. Imprimir Aluno(s) com Menor Coeficiente\n");
		printf("6. Encerrar Acoes\n");
		printf("Insira a opcao desejada: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\nInserir Aluno\n");
				printf("Insira o nome do aluno: ");
				scanf("%s", nomeInserido);
				setbuf(stdin, NULL);
				do{
					printf("Insira o coeficiente de rendimento desse aluno(de 0 a 10): ");
					scanf("%f", &coeficienteInserido);
				} while(coeficienteInserido < 0 || coeficienteInserido > 10);
				insereAlunoFim(&cabecaAlunos, nomeInserido, coeficienteInserido);
				printf("Aluno inserido com sucesso.\n");
				break;
			case 2:
				printf("\nBuscar Aluno\n");
				if(cabecaAlunos->prim == NULL){
					printf("Nao ha nenhum aluno na lista.\n");
				} else {
					printf("Insira o nome do aluno que deseja procurar: ");
					scanf("%s", nomeInserido);
					setbuf(stdin, NULL);
					buscaAluno(nomeInserido, &cabecaAlunos);
				}
				break;
			case 3:
				printf("\nRemover um Aluno\n");
				if(cabecaAlunos->prim == NULL){
					printf("Nao ha nenhum aluno na lista.\n");
				} else {
					printf("Insira o nome do aluno que deseja retirar da Lista: ");
					scanf("%s", nomeInserido);
					setbuf(stdin, NULL);
					removeAluno(nomeInserido, &cabecaAlunos);
					
				}
				break;
			case 4:
				printf("\nImprimir Alunos da Lista\n");
				if(cabecaAlunos->prim == NULL){
					printf("Nao ha nenhum aluno na lista.\n");
				} else {
					aux = cabecaAlunos->prim;;
					for(int i = 0; i < cabecaAlunos->num; i++){
						printf("ALUNO %d\nNome: %s\nCoeficiente de rendimento: %.2f\n\n", (i+1), aux->nome, aux->coeficiente);
						aux = aux->prox;
					}
				}
				break;
			case 5:
				printf("\nImprimir Aluno(s) com Menor Coeficiente\n");
				if(cabecaAlunos->prim == NULL){
					printf("Nao ha nenhum aluno na lista.\n");
				} else if(cabecaAlunos->prim == cabecaAlunos->ult){
					aux = cabecaAlunos->prim;
					printf("Aluno com menor coeficiente\nNome: %s\nCoeficiente de rendimento: %.2f\n", aux->nome, aux->coeficiente);
				} else {
					buscaMenor(cabecaAlunos->prim, cabecaAlunos);
				}
				break;
			case 6:
				printf("\nEncerrar Acoes\nObrigado por seus servicos.\n");
				break;
			default:
				printf("\nFavor inserir opcao valida.\n");
				break;
		}
	} while(op != 6);

}

//Inicio implementacao das funcoes
Aluno *alocaAluno(char *nome, float coeficiente){
	Aluno *no = (Aluno *)malloc(sizeof(Aluno));
	if(no == NULL){
		printf("Aluno nao foi alocado: ");
		return NULL;
	} else {
		strcpy(no->nome, nome);
		no->coeficiente = coeficiente;
		no->prox = NULL;
		return no;
	}
}

void insereAlunoFim(Cabeca **cabeca, char *nome, float coeficiente){
	Cabeca *auxCabeca = *cabeca;
	Aluno *auxAluno = alocaAluno(nome, coeficiente);
	if(auxAluno != NULL){
		if(auxCabeca->prim == NULL){
			auxCabeca->num = 1;
			auxCabeca->prim = auxCabeca->ult = auxAluno;
		} else {
			auxCabeca->num = auxCabeca->num + 1;
			auxCabeca->ult->prox = auxAluno;
			auxCabeca->ult = auxAluno;
		}
	} else {
		exit(1);
	}
}

void buscaMenor(Aluno *prim, Cabeca *cabeca){
	Aluno *aux = prim->prox, *aux2 = prim;
	float menor = prim->coeficiente;
	int contador = 0;
	for(int i = 1; i < cabeca->num; i++){
		if(menor >= aux->coeficiente){
			menor = aux->coeficiente;
		}
		aux = aux->prox;
	}
	for(int i = 0; i < cabeca->num; i++){
		if(aux2->coeficiente == menor){
			++contador;
			if(contador == 1){
				printf("Aluno(s) com menor coeficiente\nNome: %s\nCoeficiente de rendimento: %.2f\n", aux2->nome, aux2->coeficiente);
			} else {
				printf("Nome: %s\nCoeficiente de rendimento: %.2f\n", aux2->nome, aux2->coeficiente);
			}
		}
		aux2 = aux2->prox;	
	}
}

void buscaAluno(char *nome, Cabeca **cabeca){
	int comp;
	Aluno *aux = (*cabeca)->prim;
	Aluno *anterior;

	for(int i = 0; i < (*cabeca)->num; i++){
		comp = strcmp(nome, aux->nome);
		if(comp == 0){
			break;
		}
		anterior = aux;
		aux = aux->prox;
	}

	if(comp != 0){
		printf("Nao foi encontrado o aluno %s.\n", nome);
	} else {
		printf("O aluno %s possui coeficiente %.2f.\n", aux->nome, aux->coeficiente);
	}

	if(comp == 0 && aux != (*cabeca)->prim){
		if(anterior == (*cabeca)->prim){
			anterior->prox = aux->prox;
			aux->prox = anterior;
			(*cabeca)->prim = aux;
			if(anterior->prox == NULL){
				(*cabeca)->ult = anterior;	
			}
		} else {
			anterior->prox = aux->prox;
			aux->prox = (*cabeca)->prim;
			(*cabeca)->prim = aux;
			if(anterior->prox == NULL){
				(*cabeca)->ult = anterior;
			}
		}
	}
}

void removeAluno(char *nome, Cabeca **cabeca){
	int comp;
	Aluno *aux = (*cabeca)->prim;
	Aluno *anterior, *aux2;

	for(int i = 0; i < (*cabeca)->num; i++){
		comp = strcmp(nome, aux->nome);
		if(comp == 0){
			break;
		}
		anterior = aux;
		aux = aux->prox;
	}

	if(comp != 0){
		printf("Nao foi encontrado o aluno %s.\n", nome);
	} else {
		if((*cabeca)->prim == (*cabeca)->ult){
			free((*cabeca)->prim);
			((*cabeca)->prim) = NULL;
		} else if(aux == (*cabeca)->prim){
			(*cabeca)->prim = aux->prox;
			free(aux);
			(aux) = NULL;
		} else if(aux == (*cabeca)->ult){
			anterior->prox = NULL;
			(*cabeca)->ult = anterior;
			free(aux);
			(aux) == NULL;
		} else {
			anterior->prox = aux->prox;
			free(aux);
			(aux) = NULL;
		}
		--(*cabeca)->num;
		printf("Aluno removido com sucesso.\n");
	}
}
//Fim implementacao das funcoes