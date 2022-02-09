#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[64];
	int idade;
} pessoa;

int iguais(pessoa a, pessoa b){
	int resultado_nome;
	
	resultado_nome = strcmp(a.nome, b.nome);
	if(resultado_nome == 0 && a.idade == b.idade){
		return 1;
	} else {
		return 0;
	}
}

void main(){
	pessoa pessoa_1, pessoa_2;
	int result;
	
	printf("Insira o nome da primeira pessoa: ");
	scanf("%s", &pessoa_1.nome);
	printf("Insira a idade da primeira pessoa: ");
	scanf("%d", &pessoa_1.idade);
	
	printf("Insira o nome da segunda pessoa: ");
	scanf("%s", &pessoa_2.nome);
	printf("Insira a idade da segunda pessoa: ");
	scanf("%d", &pessoa_2.idade);

	result = iguais(pessoa_1, pessoa_2);

	if(result == 1){
		printf("Sao a mesma pessoa.\n");
	} else {
		printf("Nao sao a mesma pessoa.\n");
	}

}