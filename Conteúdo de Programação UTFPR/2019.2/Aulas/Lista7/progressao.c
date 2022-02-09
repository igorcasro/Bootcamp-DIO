#include <stdio.h>

void soma(int primeiro, int razao){
	int soma;

	soma = primeiro + (4 * razao);

	printf("Soma dos cinco primeiros termos: %d\n", soma);
}


int main(){
	int primeiro, razao;

	printf("Insira o primeiro termo da P.A.: ");
	scanf("%d", &primeiro);
	printf("Insira a razao da P.A.: ");
	scanf("%d", &razao);

	soma(primeiro, razao);


	return 0;
}
