#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coordenadas_polares{
	int raio;
	int argumento;
};

struct coordenadas_cartesiano{
	int x;
	int y;
};

void troca(struct coordenadas_polares inserida, struct coordenadas_cartesiano trocada){
	printf("%d %d \n", inserida.raio, inserida.argumento);

	trocada.x = cos(inserida.argumento);
	trocada.y = sin(inserida.argumento);

	printf("%d %d \n", trocada.x, trocada.y);

}

void main(){
	struct coordenadas_polares inseridas;
	struct coordenadas_cartesiano trocadas;

	printf("Insira as coordenadas polares.\n");
	printf("Raio(r): ");
	scanf("%d", &inseridas.raio);
	printf("Argumento(a): ");
	scanf("%d", &inseridas.argumento);

	troca(inseridas, trocadas);

	printf("As coordenadas cartesianas a partir das polares sao:\n");
	printf("X = %d\n", (inseridas.raio * cos(inseridas.argumento)));
	printf("Y = %d\n", inseridas.argumento);

}	

