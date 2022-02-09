#include <stdio.h>
#include <math.h>
#define pi 3.14


int main(){
	float contador, raio, volume, potencia;

	printf("***VOLUME DA ESFERA***\n\n");

	contador = 0;
	do{
		raio = (contador / 2);
		potencia = pow(raio, 3);
		volume = 4 * pi * potencia;
		volume = volume / 3;
		printf("Raio = %.2f \t Volume = %.2f\n", raio, volume);
		++contador;
	} while(contador <= 40);

	return 0;
}
