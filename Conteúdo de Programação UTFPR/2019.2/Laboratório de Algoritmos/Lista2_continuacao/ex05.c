#include <stdio.h>
#include <stdlib.h>

void criptografia(char *text){
	int contador = 0, i = 0;
	while(text[contador] != '\0'){
		++contador;
		text + contador;
	}


	for(int i = 0; i < contador; i++){
		if(*(text + i) >= 'A' && *(text + i) <= 'Z'){
			if(*(text + i) == 'Z'){
				*(text + i) = 'C';
			} else if(*(text + i) == 'Y'){
				*(text + i) = 'B';
			} else if(*(text + i) == 'X'){
			 	*(text + i) = 'A';
			} else {
				*(text + i) = *(text + i) + 3;
			}
		} else {
			*(text + i) = '*';
		}
	}
}

int main(){
	char text[30];
	scanf("%s", text);
	criptografia(text);
	printf("%s\n", text);
}	