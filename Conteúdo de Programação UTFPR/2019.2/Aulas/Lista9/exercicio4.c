#include <stdio.h>

void Armazenar(int vet[], int n);

void Separar(int vet[], int i[], int p[], int n);

void main(){
	int vet[15], i[15], p[15], n = 15;

	Armazenar(vet, n);
	Separar(vet, i, p, n);
}

void Armazenar(int vet[], int n){
	int i;

	for(i = 0; i < n; i++){
		printf("[%d]= ", i);
		scanf("%d", &vet[i]);
	}

}

void Separar(int vet[], int i[], int p[], int n){
	int j, ip = 0, ii = 0, k;

	for(j = 0; j < n; j++){
		if(vet[j] % 2 == 0){
			p[ip] = vet[j];
			++ip;
		} else {
			i[ii] = vet[j];
			++ii;
		}
	}
	printf("\nImprime Par.\n");
	for(k = 0; k < ip; ++k){
		printf("[%d]= %d\n", k, p[k]);
	}
	printf("Imprime Impar.\n");
	for(k = 0; k < ii; ++k){
		printf("[%d]= %d\n", k, i[k]);
	}
}
