#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int valor;
} inteiros;

int adicionar(inteiros numeros[], int arm){
	int mais;

	printf("Quantos numeros voce deseja armazenar a mais? ");
	scanf("%d", &mais);

	for(int i = arm; i < (arm + mais); i++){
		printf("[%d] = ", i);
		scanf("%d", &numeros[i].valor);
	}

	return (arm + mais);
}

int nElementos(int *num_elem){
	printf("O numero de elementos armazenados na lista eh de: %d\n", *num_elem);
}

int remover(inteiros numeros[], int *num_elem){
	int rem, aux = 0;
	printf("Insira um valor inteiro para ser removido da lista: ");
	scanf("%d", &rem);
	for(int i = 0; i < *num_elem; i++){
		if(rem == numeros[i].valor){
			--*num_elem;
			for(int j = 0; j < *num_elem; j++){
				if(j == i){
					for(int k = j; k < *num_elem; ++k){
						numeros[k].valor = numeros[k+1].valor;
						++j;
					}
				} else {
					numeros[j].valor = numeros[j].valor;
				}
			}
		} 

	}

	return *num_elem;
}

void imprimir(inteiros numeros[], int num_elem){
	printf("Os elementos sao \n");

	for(int i = 0; i < num_elem; i++){
		printf("[%d] = %d\n", i, numeros[i].valor);
	}
}

void main(){
	inteiros numeros[100];
	int armazenados;
	int *numero_elem;
	int numero_elem2, outro;

	do{
	printf("Insira quantos inteiros serao armazenados entre 0 e 100 em um primeiro momento: ");
	scanf("%d", &armazenados);
	} while(armazenados < 0 || armazenados > 100);
	
	for(int i = 0; i < armazenados; i++){
		printf("[%d] = ", i);
		scanf("%d", &numeros[i].valor);
	}

	*numero_elem = adicionar(numeros, armazenados);
	nElementos(numero_elem);
	outro = *numero_elem;
	numero_elem2 = remover(numeros, numero_elem);
	if(numero_elem2 == outro){
		printf("ERRO: ELEMENTO NAO ENCONTRADO!\n");
	}
	imprimir(numeros, numero_elem2);

}