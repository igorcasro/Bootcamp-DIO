#include <stdio.h>
#include <string.h>
#include "recursividade.h"

void main(){
	int num1, num2, op, tam;
	float res;
	char nome[50];
	do{
		printf("\n***PROJETO FINAL - B***\n\n");
		printf("1 - Divisao\n");
		printf("2 - Potencia\n");
		printf("3 - Fibonacci\n");
		printf("4 - Impares\n");
		printf("5 - Ordem inversa de uma string\n");
		printf("6 - Indice de vetor\n");
		printf("7 - Produto de elementos de um vetor\n");
		printf("8 - Sair\n");
		printf("Insira qual opcao voce deseja: ");
		scanf("%d", &op);
		if (op == 7)
		{
			int n;
			int produto = 1;
			int cont;
			do{
				printf("Insira o tamanho do vetor: ");
				scanf("%d", &n);
			} while(n < 0);
			int vet[n];
			for(cont = 0;cont < n; cont++){
				printf("[%d]= ", cont);
				scanf("%d", &vet[cont]);
			}
			cont = 0;
			funcao(n, vet, produto, cont);
		}
		switch(op){
			case 1:
				do {
					printf("\nInsira o primeiro valor da divisao: ");
					scanf("%d", &num1);
					printf("Insira o segundo valor da divisao: ");
					scanf("%d", &num2);
				} while(num2 == 0);
				res = divisao(num1, num2);
				printf("Resultado = %.0f\n", res);
				break;
			case 2:
				do{
					printf("\nInsira a base: ");
					scanf("%d", &num1);
					printf("Insira o expoente: ");
					scanf("%d", &num2);
				} while (num1 == 0 && num2 == 0);
				res = potencia(num1, num2);
				printf("Resultado = %.4f\n", res);				
				break;
			case 3:
				do{
				printf("\nInsira qual termo de Fibonacci voce deseja que apareca: ");
				scanf("%d", &num1);
				} while(num1 <= 0);
				res = fibonacci(num1);
				printf("%d\n", res);
				break;
			case 4:
				do{
				printf("\nInsira um numero para que sejam impressos os impares dele ate zero:  ");
				scanf("%d", &num1);
				} while(num1 <= 0);
				res = impar(num1);
				printf("%d\n", res);
				break;
			case 5:
				printf("\nInsira uma string para retornar ela invertida: ");
				scanf(" %[^\n]s", nome);

				tam = strlen(nome);

				devstring(tam, nome);
				printf("\n");
				break;
			case 6:
				printf("Digite o tamanho do vetor: ");
				scanf("%d", &tam);

				int vetor[tam];

				for(int i = 0; i < tam; ++i){
					printf("[%d]= ", i);
					scanf("%d", &vetor[i]);
				}

				printf("Digite o valor para conferir se esta no vetor: ");
				scanf("%d", &num1);
				res = procuravetor(tam, num1, vetor);
				if(res == -1){
					printf("Nao existe o valor %d no vetor.\n", num1);
				} 
				break;
			}
	}while(op != 8);
}
