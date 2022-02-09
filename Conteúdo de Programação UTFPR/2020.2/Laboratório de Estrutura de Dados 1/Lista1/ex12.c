#include <stdio.h>

void main(){
	char carros[5][20];
	float consumo[5];

	for(int i = 0; i < 5; i++){
		printf("Insira a marca do carro %d: ", (i + 1));
		scanf("%s", &carros[i]);
	}

	for(int i = 0; i < 5; i++){
		printf("Insira o consumo do %s: ", carros[i]);
		scanf("%f", &consumo[i]);
	}

	int maisEconomico = consumo[0];
	int variavel = 0;

	for(int i = 4; i >= 0; i--){
		if(consumo[i] > maisEconomico){
			maisEconomico = consumo[i];
			variavel = i;
		}
	}

	printf("O modelo mais economico eh o %s.\n", carros[variavel]);

	for(int i = 0; i < 5; i++){
		printf("Para percorrer 1000km o %s consome %.1f litros de combustivel;\n", carros[i], (1000/consumo[i]));
	}
}