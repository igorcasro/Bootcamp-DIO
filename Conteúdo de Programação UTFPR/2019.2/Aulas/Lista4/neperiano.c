#include <stdio.h>

int main(){
	float neperiano, fatorial;
	int contador, auxiliar;	
	auxiliar = 1;
	neperiano = 1;
	
	while(auxiliar < 15){
		fatorial = 1;
		contador = auxiliar;
		while(contador > 0) {
			fatorial = fatorial * contador;
			--contador;	
		}
		neperiano = neperiano + (1 / fatorial);
		++auxiliar;
	}
	printf("O numero neperiano eh: %.6f\n", neperiano);

	return 0;
}
