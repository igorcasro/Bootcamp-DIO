#include <stdio.h>
#include <stdlib.h>

int tamanho();
void leitura(int *vet, int tam);
void separa(int *vet, int tam);
void desaloca(int **vet);
void imprime(int *vet, int tam);

void main(){
	int n1;

	n1 = tamanho();
	int *vet1 = (int *)malloc(n1 * sizeof(int));
	leitura(vet1, n1);
	separa(vet1, n1);

	desaloca(&vet1);
}

int tamanho(){
	int tam;

	printf("Insira o tamanho do vetor: ");
	scanf("%d", &tam);

	return tam;
}

void leitura(int *vet, int tam){
	for(int i = 0; i < tam; i++){
		printf("[%d] = ", i);
		scanf("%d", (vet + i));
	}
}

void separa(int *vet, int tam){
	int par = 0, impar = 0;

	for(int i = 0; i < tam; i++){
		if(*(vet + i) % 2 == 0){
			++par;
		} else {
			++impar;
		}
	}

	int *vetPar = (int *)malloc(par * sizeof(int));
	int *vetImpar = (int *)malloc(impar * sizeof(int));

	int auxPar = 0, auxImpar = 0;

	for(int i = 0; i < tam; i++){
		if(*(vet + i) % 2 == 0){
			*(vetPar + auxPar) = *(vet + i);
			++auxPar;
		} else {
			*(vetImpar + auxImpar) = *(vet + i);
			++auxImpar;
		}
	}

	printf("Os valores pares sao\n");
	imprime(vetPar, par);
	printf("Os valores impares sao\n");
	imprime(vetImpar, impar);

	desaloca(&vetPar);
	desaloca(&vetImpar);

}

void imprime(int *vet, int tam){
	for(int i = 0; i < tam; i++){
		printf("[%d] = %d\n", i, *(vet + i));
	}
}

void desaloca(int **vet){
	free(*vet);
	*vet = NULL;
}