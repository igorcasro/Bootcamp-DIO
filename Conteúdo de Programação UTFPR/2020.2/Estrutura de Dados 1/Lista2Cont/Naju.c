#include<stdio.h>

void main(){

	char nome[15], sexo;

	printf("Informe o seu nome:\n");
	//scanf("%s", nome);
	//fgets(char nome [15], nome, stdin);
	fgets(nome, 15, stdin);
	setbuf(stdin, NULL);
	printf("Informe o seu sexo (M/F):\n");
	//scanf("%s", &sexo);
	scanf("%c", &sexo);

	printf("%s\n", nome);

	if (sexo == 'F' || sexo == 'f'){
		printf("Ilma Sra. %s.\n", nome);
	}

	if (sexo == 'M' || sexo == 'm'){
		printf("Ilmo Sr. %s.\n", nome);
	}
}