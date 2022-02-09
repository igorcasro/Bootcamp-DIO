#include <stdio.h>
#include <stdlib.h>

void tamanho_string(char *string, int *result){
	int i = 0;

	while(*(string + i) != '\0' && *(string + i) != '\n'){
		++(*result); 
		++ i;
	}

}

void copia_string(char *string1,char *string2){
	for(int i = 0; *(string1 + i) != '\n' && *(string1 + i) != '\0'; i++){
		*(string2 + i) = *(string1 + i);
	}

}

void minusculo_string(char *string1, char *string2){
	for(int i = 0; *(string1 + i) != '\0' && *(string1 + i) != '\n'; ++i){
		if(*(string1 + i) >= 'A' && *(string1 + i) <= 'Z'){
			*(string2 + i) = *(string1 + i) + 32;
		} else {
			*(string2 + i) = *(string1 + i);
		}
	}	
}

void maiusculo_string(char *string1, char *string2){
	for(int i = 0; *(string1 + i) != '\0' && *(string1 + i) != '\n'; ++i){
		if(*(string1 + i) >= 'a' && *(string1 + i) <= 'z'){
			*(string2 + i) = *(string1 + i) - 32;
		} else {
			*(string2 + i) = *(string1 + i);
		}
	}
}

void encontra_char(char *string1,char *string2){
	char carac;
	printf("Insira o caractere a ser encontrado na string: ");
	scanf("%c", &carac);	
	for(int i = 0; *(string1 + i) != '\n' && *(string1 + i) != '\0'; ++i){
		if(carac == *(string1 + i)){
			*string2 = carac;
		} else {
			*string2 = '\0';
		}
	}
}

void main(){
	char *string = (char *)calloc(100, sizeof(char));
	char *resultado = (char *)calloc(100, sizeof(char));
	int *resultado_numero = (int *)calloc(1, sizeof(int));
	char *caractere = (char *)calloc(1, sizeof(int));


	printf("Insira uma string: ");
	fgets(string, 100, stdin);

	tamanho_string(string, resultado_numero);
	printf("O tamanho dessa string eh: %d\n", *resultado_numero);
	free(resultado_numero);
	resultado_numero = NULL;

	copia_string(string, resultado);
	printf("A copia dessa string eh: %s\n", resultado);

	minusculo_string(string, resultado);
	printf("Essa string toda minuscula fica: %s\n", resultado);

	maiusculo_string(string, resultado);
	printf("Essa string toda maiuscula fica: %s\n", resultado);
	free(resultado);
	resultado = NULL;


	encontra_char(string, caractere);
	if(*caractere == '\0'){
		printf("Nao foi encontrado o caractere na string.\n");
	} else {
		printf("O caractere \'%c\' foi encontrado na string.\n", *caractere);
	}
	free(caractere);
	caractere = NULL;

	free(string);
	string = NULL;
}