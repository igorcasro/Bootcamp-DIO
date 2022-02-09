#include <stdio.h>

int main(){
	int funcionario;
	float salario,contador, filhos, mediaSalario, mediaFilhos;
	
	for(funcionario = 0; funcionario < 100; ++funcionario){
		do{
			printf("***FUNCIONARIO %d***\n", (funcionario + 1) );
			printf("Insira o salario: ");
			scanf("%f", &salario);
			printf("Insira o numero de filhos: ");
			scanf("%f", &filhos);
			mediaSalario = mediaSalario + salario;
			mediaFilhos = mediaFilhos + filhos;
		}while(salario < 0 || filhos < 0);
		if(salario <= 300 && filhos > 0){
			++contador;
		}
	}	
	mediaSalario = mediaSalario / 100;
	mediaFilhos = mediaFilhos / 100;
	contador = contador / 100;
	printf("O percentual de pessoa com salario ate 300 reais e que possuem filhos eh: %.2f", contador);

	return 0;
}
