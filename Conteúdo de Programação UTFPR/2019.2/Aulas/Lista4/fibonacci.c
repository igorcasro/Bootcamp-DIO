#include <stdio.h>

int main(){
 	int valor1, valor2, valor3, usuario, contador;
	valor1 = 1;
	valor2 = 1;
	printf("Insira quantas vezes deseja que seja calculada a Sere de Fibonacci: ");
	scanf("%d", &usuario);
	
	if(usuario == 1){
		printf("1\n");
	} else if(usuario == 2){
		printf("1  1\n");
	} else	
		printf("1  1  ");
		for(contador = 1; contador <= (usuario - 2); ++contador){
			valor3 = valor1 + valor2;
			printf("%d  ", valor3);
			valor1= valor2;
			valor2= valor3;
		}
	printf("\n");

	return 0;
}
