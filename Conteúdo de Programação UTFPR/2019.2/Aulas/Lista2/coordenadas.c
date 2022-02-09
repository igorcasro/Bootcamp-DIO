#include <stdio.h>

int main() {

	float coord1, coord2;
	printf("Insira a primeira coordenada do plano cartesiano: ");
	scanf("%f", &coord1);
	printf("Insira a segunda coordenada do plano cartesiano: ");
	scanf("%f", &coord2);
	if(coord1 == 0 & coord2 == 0) {
		printf("O seu ponto (%.2f, %.2f) esta na Origem.\n", coord1, coord2);
	} else if(coord1 == 0) {
		printf("O seu ponto (%.2f, %.2f) esta no Eixo Y.\n", coord1, coord2);
	} else if(coord2 == 0) {
		printf("O seu ponto (%.2f, %.2f) esta no Eixo X.\n", coord1, coord2);
	} else if(coord1 > 0 && coord2 > 0) {
		printf("O seu ponto (%.2f, %.2f) esta no Primeiro Quadrante.\n", coord1, coord2);
	} else if(coord1 < 0 && coord2 > 0) {
		printf("O seu ponto (%.2f, %.2f) esta no Segundo Quadrante.\n", coord1, coord2);
	} else if(coord1 < 0 && coord2 < 0) {
		printf("O seu ponto (%.2f, %.2f) esta no Terceiro Quadrante.\n", coord1, coord2);
	} else if(coord1 > 0 && coord2 < 0) {
		printf("O seu ponto (%.2f, %.2f) esta no Quarto Quadrante.\n", coord1, coord2);
	}

	return 0;
}