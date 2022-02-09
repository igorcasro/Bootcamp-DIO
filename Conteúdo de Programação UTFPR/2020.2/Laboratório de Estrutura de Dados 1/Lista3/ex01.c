#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[64];
	int idade;
} pessoa;

int iguais(pessoa *p){
	int comp = strcmp((p)->nome, (p+1)->nome);

	if(comp == 0 && p->idade == (p+1)->idade){
		return 0;
	} else {
		return -1;
	}
}

void main(){
	pessoa *p = (pessoa *)malloc(2 * sizeof(pessoa));
	
	if(p){
		for(int i = 0; i < 2; i++){
			printf("Pessoa %d\n", i+1);
			setbuf(stdin, NULL);
			printf("Insira o nome da pessoa: ");
			fgets((p+i)->nome, 64, stdin);
			printf("Insira sua idade: ");
			scanf("%d", &(p+i)->idade);
		}
	}

	if(iguais(p) == 0){
		printf("Sao a mesma pessoa!\n");
	} else {
		printf("Nao sao a mesma pessoa!\n");
	}

}