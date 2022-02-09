#include <stdio.h>

void main(){
	char nome[20], sexo;
	int idade;

	printf("Insira seu nome: ");
	fgets(nome, 20, stdin);
	printf("Agora, insira seu sexo (M ou F): ");
	scanf("%c", &sexo);
	printf("Por ultimo, sua idade, por favor: ");
	scanf("%d", &idade);

	if(sexo == 'F' || sexo == 'f'){
		if(idade < 25){
			printf("ACEITA\n");
		} else {
			printf("NAO ACEITA\n");
		}
	} else	{
		printf("NAO ACEITA\n");
	}

}