#include <stdio.h>

int main(){
	int opcao;
	printf("1-7: soma\n8: subtracao\nQqr numero: sair\nEscolha: ");
	scanf("%d", &opcao);
	switch(opcao){
		case (1 . . int 7):
			printf("Soma\n");
			break;
		case 8:
			printf("Subtracao\n");
			break;
		default:
			printf("Sair\n");
			break;
	}
	
	return 0;
}
