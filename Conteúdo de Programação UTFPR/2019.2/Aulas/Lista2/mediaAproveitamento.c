#include <stdio.h> 

int main() {

	float N1, N2, N3, ME, MA;
	int identificacao;
	char conceito;
	printf("Insira seu numero de identificacao: ");
	scanf("%d", &identificacao);
	printf("Insira as 3 notas obtidas nas verificacoes e depois a media dos exercicios.\n");
	printf("N1 = ");
	scanf("%f", &N1);
	printf("N2 = ");
	scanf("%f", &N2);
	printf("N3 = ");
	scanf("%f", &N3);
	printf("ME = ");
	scanf("%f", &ME);
	MA = (N1 + (N2 * 2) + (N3 * 3) + ME)/7;
	if(MA > 10) {
		printf("VALORES INVALIDOS!\n");
	} else if(MA >= 9){
			conceito = 'A';
			printf("Identificacao = %d \n", identificacao);
			printf("N1 = %.2f \n", N1);
			printf("N2 = %.2f \n", N2);
			printf("N3 = %.2f \n", N3);
			printf("ME = %.2f \n", ME);
			printf("MA = %.2f \n", MA);
			printf("Conceito = %c \n", conceito);
			printf("APROVADO!\n");
		} else if(MA >= 7.5) { 
			conceito = 'B';
			printf("Identificacao = %d \n", identificacao);
			printf("N1 = %.2f \n", N1);
			printf("N2 = %.2f \n", N2);
			printf("N3 = %.2f \n", N3);
			printf("ME = %.2f \n", ME);
			printf("MA = %.2f \n", MA);
			printf("Conceito = %c \n", conceito);
			printf("APROVADO!\n");
		} else if(MA >= 6) { 
			conceito = 'C';
			printf("Identificacao = %d \n", identificacao);
			printf("N1 = %.2f \n", N1);
			printf("N2 = %.2f \n", N2);
			printf("N3 = %.2f \n", N3);
			printf("ME = %.2f \n", ME);
			printf("MA = %.2f \n", MA);
			printf("Conceito = %c \n", conceito);
			printf("APROVADO!\n");
		} else if(MA >= 4) { 
			conceito = 'D';
			printf("Identificacao = %d \n", identificacao);
			printf("N1 = %.2f \n", N1);
			printf("N2 = %.2f \n", N2);
			printf("N3 = %.2f \n", N3);
			printf("ME = %.2f \n", ME);
			printf("MA = %.2f \n", MA);
			printf("Conceito = %c \n", conceito);
			printf("REPROVADO!\n");
		} else if(MA >= 0) { 
			conceito = 'E';
			printf("Identificacao = %d \n", identificacao);
			printf("N1 = %.2f \n", N1);
			printf("N2 = %.2f \n", N2);
			printf("N3 = %.2f \n", N3);
			printf("ME = %.2f \n", ME);
			printf("MA = %.2f \n", MA);
			printf("Conceito = %c \n", conceito);
			printf("REPROVADO!\n");
		} else
			printf("Insira valores coerentes!\n");

	return 0;
}