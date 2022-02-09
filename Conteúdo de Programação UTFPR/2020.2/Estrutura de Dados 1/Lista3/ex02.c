#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dia;
	int mes;
	int ano;
} data;

typedef struct {
	char compromisso[60];
	data inserirData;
} agenda;

void percorreStructs(agenda *inserida, int tam);
void leituraMesAno(int *mesInserido, int *anoInserido);
void apresentaCompromissos(agenda *inserida, int tam, int *mesInserido, int *anoInserido);

void main(){

	int n;
	printf("Insira quantos compromissos deseja inserir: ");
	scanf("%d", &n);

	printf("%d\n", n);

	agenda *inserida = (agenda *)malloc(n *sizeof(agenda));

	int *mesInserido, *anoInserido;
	mesInserido = (int *)malloc(sizeof(int));
	anoInserido = (int *)malloc(sizeof(int));

	if(inserida && mesInserido && anoInserido){
		percorreStructs(inserida, n);
		leituraMesAno(mesInserido, anoInserido);
		apresentaCompromissos(inserida, n, mesInserido, anoInserido);
	}


}

void percorreStructs(agenda *inserida, int tam){
	
	for(int i = 0; i < tam; i++){
		setbuf(stdin, NULL);
		printf("Insira o seu compromisso %d: ", (i + 1));
		fgets((inserida + i)->compromisso, 60, stdin);
		printf("Insira o dia do compromisso: ");
		scanf("%d", &((inserida + i)->inserirData.dia));
		printf("Insira o mes do compromisso: ");
		scanf("%d", &((inserida + i)->inserirData.mes));
		printf("Insira o ano do compromisso: ");
		scanf("%d", &((inserida + i)->inserirData.ano));
	}

}

void leituraMesAno(int *mesInserido, int *anoInserido){
	printf("Insira de qual ano deseja fazer a leitura: ");
	scanf("%d", anoInserido);
	printf("Insira a partir de qual mes deseja fazer a leitura: ");
	scanf("%d", mesInserido);
}

void apresentaCompromissos(agenda *inserida, int tam, int *mesInserido, int *anoInserido){

	for(int i = 0; i < tam; i++){
		if(*anoInserido == ((inserida + i)->inserirData.ano)){
			printf("%d/%d/%d : %s", ((inserida + i)->inserirData.dia), ((inserida + i)->inserirData.mes), ((inserida + i)->inserirData.ano), (inserida + i)->compromisso);
		}
	}

}