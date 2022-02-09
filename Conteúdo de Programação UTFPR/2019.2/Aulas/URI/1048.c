#include <stdio.h>

int main(){
	float salario, salarioNovo, ajuste, reajuste;
	printf("***AUMENTO SALARIAL***\n\n");
	do{
	printf("Insira o salario atual: ");
	scanf("%f", &salario);
	} while(salario < 0);
	if(salario <= 400){
		ajuste = 0.15;
		salarioNovo = salario * (1 + ajuste); 
		reajuste =  salario * ajuste;
		printf("Novo salario: %.2f\n", salarioNovo);
		printf("Reajuste ganho: %.2f\n", reajuste);
		printf("Em percentual: %.0f %\n", 100 * ajuste);
	} else if(salario <= 800){
		ajuste = 0.12;
		salarioNovo = salario * (1 + ajuste);
		reajuste = salario * ajuste;
		printf("Novo salario: %.2f\n", salarioNovo);
		printf("Reajuste ganho: %.2f\n", reajuste);
		printf("Em percentual: %.0f %\n", 100 * ajuste);
	} else if(salario <= 1200){
		ajuste = 0.10;
		salarioNovo = salario * (1 + ajuste);
		reajuste = salario * ajuste;
		printf("Novo salario: %.2f\n", salarioNovo);
		printf("Reajuste ganho: %.2f\n", reajuste);
		printf("Em percentual: %.0f %\n", 100 * ajuste);
	} else if(salario <= 2000){
		ajuste = 0.07;
		salarioNovo = salario * (1 + ajuste);
		reajuste = salario * ajuste;
		printf("Novo salario: %.2f\n", salarioNovo);
		printf("Reajuste ganho: %.2f\n", reajuste);
		printf("Em percentual: %.0f %\n", 100 * ajuste);
	} else {
		ajuste = 0.04;
		salarioNovo = salario * (1 + ajuste);
		reajuste = salario * ajuste;
		printf("Novo salario: %.2f\n", salarioNovo);
		printf("Reajuste ganho: %.2f\n", reajuste);
		printf("Em percentual: %.0f %\n", 100 * ajuste);
	}

	return 0;
}	
