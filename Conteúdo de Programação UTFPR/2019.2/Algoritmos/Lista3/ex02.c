#include <stdio.h>
#include <stdlib.h>

struct agenda{
	char compromisso[60];
};

struct data{
	int dia;
	int mes;
	int ano;
	struct agenda qual;
};

void preenche(int quantidade, struct data quando[quantidade],struct agenda qual[quantidade]){
	
		for(int i = 0; i < quantidade; i++){
		printf("Insira o compromisso %d: ", i+1);
		scanf("%s", &qual[i]);
		do{
		printf("Dia: ");
		scanf("%d", &quando[i].dia);
		} while(quando[i].dia <= 0 || quando[i].dia > 31);
		do{
		printf("Mes: ");
		scanf("%d", &quando[i].mes);
		} while(quando[i].mes <= 0 || quando[i].mes > 12);
		do{
		printf("Ano: ");
		scanf("%d", &quando[i].ano);
		} while(quando[i].ano <= 2019 || quando[i].mes > 2100);
	}

}

void pesquisar(int mes_pesquisa, int ano_pesquisa, int quantidade, struct data quando[quantidade],struct agenda qual[quantidade]){


	for(int i = 0; i < mes_pesquisa; i++){
		if(ano_pesquisa == quando[i].ano){
			for(int j = 0; j < quantidade; j++);
				printf("Mes: %d\n", quando[i].mes);
				printf("Compromisso: %s\n", qual[i]);
		}
	}
}

void main(){
	int quant;
	int mes_pesquisa, ano_pesquisa;
	
	printf("Insira quantos compromissos terao sua agenda: ");
	scanf("%d", &quant);

	struct data quando[quant];
	struct agenda qual[quant];

	preenche(quant, quando, qual);


	printf("Insira um mes e um ano para fazer uma pesquisa recursiva nesse ano.\n");
	do{
	printf("Mes: ");
	scanf("%d", &mes_pesquisa);
	}while(mes_pesquisa <= 0 || mes_pesquisa > 12);
	do {
	printf("Ano: ");
	scanf("%d", &ano_pesquisa);
	}while(ano_pesquisa <= 2019 || mes_pesquisa > 2100);
	
	pesquisar(mes_pesquisa, ano_pesquisa, quant, quando, qual);
}