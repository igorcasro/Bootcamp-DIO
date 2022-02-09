#include <stdio.h>

void main(){
	char nome[100];

	printf("Insira um nome: ");
	fgets(nome, 100, stdin);
	setbuf(stdin, NULL);

	if(nome[0] == 'A' || nome[0] == 'a'){
		printf("%s\n", nome);
	}

}