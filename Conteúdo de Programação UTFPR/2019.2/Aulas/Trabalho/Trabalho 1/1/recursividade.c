#include <stdio.h>
char a = '\0';

int divisao(int num, int den){
	int quociente = 0, resto = 0;
	if(num > 0 && den > 0){
		if(num < den){
			resto = num;
			printf("Resto = %d\n", resto);
			return quociente;
		} else {
			++quociente;
			num = num - den;
			return quociente + divisao(num, den);
		}
	} else if(num > 0 && den < 0){
		den = den * (-1);
		if(num < den){
			resto = num;
			printf("Resto = %d\n", resto);
			return (quociente * -1);
		} else {
			++quociente;
			num = num - den;
			return (quociente + divisao(num, den)) * -1;
		}
	} else if(num < 0 && den > 0){
		num = num * (-1);
		if(num < den){
			resto = num;
			printf("Resto = %d\n", resto);
			return (quociente * -1);
		} else {
			++quociente;
			num = num - den;
			return (quociente + divisao(num, den)) * -1;
		}
	} else	if(num < 0 && den < 0){
		den = den * (-1);
		num = num * (-1);
		if(num < den){
			resto = num;
			printf("Resto = %d\n", resto);
			return quociente;
		} else {
			++quociente;
			num = num - den;
			return quociente + divisao(num, den);
		}

	}
}

float potencia(int base, int exp){
	float pot = 1;
	if(exp == 0){
		return pot;
	} else if(exp > 0) {
		pot = pot * base;
		return pot * potencia(base, exp - 1);
	} else if(exp < 0){
		pot = pot * (1 /(float) base);
		return pot * potencia(base, exp + 1);
	}
}

int fibonacci(int numtermos){
	int fib;
	//printf("%d\n", numtermos);
	if(numtermos == 1 || numtermos == 2){
		return 1;
	} else {
		fib = fibonacci(numtermos - 2) + fibonacci(numtermos - 1);
		return fib;
	}
}

int impar(int numero){
	if(numero == 1){
		return 1;
	} else if(numero % 2 == 0){
		return impar(numero -1);
	} else {
		printf("%d ", numero);
		return impar(numero - 2);
	}
}

char *devstring(int tamanho, char *nome){
	if(tamanho < 0){
		return nome;
	} else {
		printf("%c", nome[tamanho]);
		--tamanho;
		return devstring(tamanho, nome);
	}
}

int procuravetor(int tam, int num1, int *vetor){

	if(tam > 0) {
		if(vetor[tam - 1] == num1){
			printf("[%d]= %d\n", tam - 1, num1);
		} else
			return procuravetor(tam - 1, num1, vetor);
	} else {
		return -1;
	}

}

int funcao(int n, int vet[], int produto, int cont){
/*	printf("Informe um valor para n:\n");
	scanf("%d", &n);*/
	while(n>0){	
		produto = produto * vet[cont];
		return (funcao(n-1, vet, produto, cont+1));
	}
	printf("Produto = %d\n", produto);
	return 0;
}


