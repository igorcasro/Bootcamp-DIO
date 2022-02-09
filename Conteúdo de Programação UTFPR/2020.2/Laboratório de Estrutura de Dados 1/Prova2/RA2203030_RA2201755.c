/*
*	Compilado via LINUX
*	REALIZADO EM DUPLA
*	Weiry Ferreira Goncalves 2201755
*	Igor Castro 2203030
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limite 8.00

typedef struct conteiner{
 char nome_lanc[15];
 float peso;
 int posicao;
 struct conteiner *prox;
}Conteiner; 

typedef struct cabecaConteiner{
	int qtd;			//Quantidade de itens na Lista
	Conteiner *prim;	//Primeiro da Lista
	Conteiner *ult;		//Ultimo da Lista
}CabecaConteiner; 

typedef struct pilhaConteiner{
	float pesoTotal;	//Soma de todos os pessos 
	Conteiner *prim;	//Primeiro da pilha
	Conteiner *ultimo;	//Ultimo da Pilha
	struct pilhaConteiner *proxPilha;
}Pilha;

typedef struct cabecaPilha{
	int qtd; //Quantidade de Pilhas
	Pilha *prim;	//Primeira Pilha
	Pilha *ultimo;	//Ultima Pilha
}FilaPilha;

//Inicio chamada das funcoes
Conteiner *alocaConteiner(char *nome_lanc, float peso, int posicao);
void insereFim(CabecaConteiner **cabeca, char *nome_lanc, float peso, int posicao);
void empilhar_Conteiner(Conteiner *novoContainer, FilaPilha *filaPilha);
Pilha *criaPilha();
//Fim chamada das funcoes

void main(){
	int op;

	//declara variaveis usadas para registrar conteineres
	char nomeInserido[15];
	float pesoInserido;
	int posicaoInserida;
	//fim declaracao das variaveis usadas para registrar conteineres
	
	//inicio declaracao cabeças
	CabecaConteiner *cabecaFila = (CabecaConteiner *)malloc(sizeof(CabecaConteiner));
	if(cabecaFila != NULL){
		cabecaFila->qtd = 0;
		cabecaFila->prim = NULL;
		cabecaFila->ult = NULL;
	} else {
		printf("Nao foi possivel alocar o no cabeca da fila.\n");
	}

	FilaPilha filaP;
	filaP.qtd = 0;
	filaP.prim = NULL;
	filaP.ultimo = NULL;

	//fim declaracao cabecas

	do{
		printf("\n****NOVO ESPACO DE ALIMENTACAO****\n\n");
		printf("***MENU***\n");
		printf("1: REGISTRAR CONTEINER\n");
		printf("2: EMPILHAR CONTEINER\n");
		printf("3: IMPRIMIR PILHAS DE CONTEINERES\n");
		printf("4: SAIR\n");
		printf("\nInsira qual opcao voce deseja: ");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("\nREGISTRAR CONTEINER\n");
				printf("\nInsira nome da lanchonete: ");
				scanf("%s", nomeInserido);
				setbuf(stdin, NULL);
				do{
				    printf("Insira o peso da lanchonete: ");
				    scanf("%f", &pesoInserido);
				} while(pesoInserido <= 0 || pesoInserido > 8);
				do{
				    printf("Insira a posicao que ocupara na area de alimentacao: ");
				    scanf("%d", &posicaoInserida);
				} while(posicaoInserida <= 0);
				printf("\n");
				insereFim(&cabecaFila, nomeInserido, pesoInserido, posicaoInserida);
				break;
			case 2:
				printf("\nEMPILHAR CONTEINER\n");
				Conteiner *aux = cabecaFila->prim;
				if(cabecaFila->prim){
					cabecaFila->prim = aux->prox;
					empilhar_Conteiner(aux, &filaP);
					cabecaFila->qtd--;
					printf("\nConteiner registrado.\n");
				} else {
					printf("\nNao ha conteineres registrados.\n");
					cabecaFila->prim = NULL;
				}
				break;
			case 3:
				printf("\nIMPRIMIR PILHAS DE CONTEINERES\n");
				if(!(filaP.prim)){
					printf("\nNao existe pilha de conteineres.\n");
				}else{
					Conteiner *c;			
					Pilha *pilha = filaP.prim;
				
					for(int i=0; i<filaP.qtd; i++){
						printf("\nPilha %d\n", i+1);
						c = pilha->ultimo;
						while(c != NULL){
							printf("%s %.2f\n", c->nome_lanc, c->peso);
							c = c->prox;
						}
						printf("Total toneladas %.2f\n", pilha->pesoTotal);
						pilha=pilha->proxPilha;
					}
				}			
				break;
			case 4:
				printf("\nObrigado por seus servicos!\n");
				break;
			default:
				printf("\nOpcao invalida. Insira uma opcao valida, por favor.\n");
				break;
		}
	} while(op != 4);
}

//Inicio implementacao das funcoes
Conteiner *alocaConteiner(char *nome_lanc, float peso, int posicao){
	Conteiner *no = (Conteiner *)malloc(sizeof(Conteiner));
	if(no == NULL){
		printf("No nao foi alocado!\n");	
		exit(1);
	} else {
		strcpy(no->nome_lanc, nome_lanc);
		no->peso = peso;
		no->posicao = posicao;
		no->prox = NULL;
		return no;
	}

}

void insereFim(CabecaConteiner **cabeca, char *nome_lanc, float peso, int posicao){
	CabecaConteiner *auxCab = *cabeca;
	Conteiner *auxCont;
	auxCont = alocaConteiner(nome_lanc, peso, posicao);
	if(auxCont != NULL){
		if(auxCab->prim == NULL){
			auxCab->qtd = 1;
			auxCab->prim = auxCab->ult = auxCont;
		} else {
			auxCab->qtd = auxCab->qtd + 1;
			auxCab->ult->prox = auxCont;
			auxCab->ult = auxCont;
		}
	} else {
		exit(1);
	}
}

void empilhar_Conteiner(Conteiner *novoContainer, FilaPilha *filaPilha){

	if(!(novoContainer))
		printf("[!]Nao ha caminhoes registrados\n");
	else{
		Pilha *pilha;
		novoContainer->prox = NULL;
		if(filaPilha->prim == NULL){
			//Criar uma nova pilha
			pilha = (Pilha *) malloc(sizeof(Pilha));
			pilha->proxPilha = NULL;
			filaPilha->prim = pilha;
			filaPilha->ultimo = pilha;
			filaPilha->qtd++;
		}
		pilha = filaPilha->prim;

		for(int i = 0; i<filaPilha->qtd; i++){

			float aux = pilha->pesoTotal;

			if((aux + novoContainer->peso) <= limite){
				//Pode ser inserido na pilha
				if(pilha->prim == NULL){
					//Nao ha ninguem na lista
					pilha->prim = novoContainer;
					pilha->ultimo = novoContainer;
					pilha->pesoTotal = pilha->pesoTotal + novoContainer->peso;
				}else{
					//Caso ja exista alguem mas nao excede o limite de peso
					novoContainer->prox = pilha->ultimo;
					pilha->ultimo = novoContainer;
					pilha->pesoTotal = pilha->pesoTotal + novoContainer->peso;
				}
				break;
			} else {
				pilha = pilha->proxPilha;
			}
		}
//		printf("Pilha: %p\n", pilha);
		if(pilha == NULL){
			Pilha *aux;
			//Criar uma pilha nova
			pilha = (Pilha *) malloc(sizeof(Pilha));

			aux = filaPilha->ultimo;

			aux->proxPilha = pilha;
		
			pilha->proxPilha= NULL;
		
			filaPilha->ultimo = pilha;
		
			filaPilha->qtd++;

			pilha->prim = novoContainer;
			pilha->ultimo = novoContainer;
			pilha->pesoTotal = novoContainer->peso;

		}
	}
}
//Fim implementacao das funcoes