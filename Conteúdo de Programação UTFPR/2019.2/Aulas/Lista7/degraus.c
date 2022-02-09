#include <stdio.h>

int subida(float degrau, float altura){
	int numdegraus;
	numdegraus = altura / degrau;
	printf("O numero de degraus eh: %d\n", numdegraus);
}

int main(){
	float degrau, altura;


	printf("Insira a altura, em centimetros, de cada degrau: ");
	scanf("%f", &degrau);
	printf("Insira a altura que deseja alcancar: ");
	scanf("%f", &altura);

	subida(degrau, altura);


	return 0;
}
