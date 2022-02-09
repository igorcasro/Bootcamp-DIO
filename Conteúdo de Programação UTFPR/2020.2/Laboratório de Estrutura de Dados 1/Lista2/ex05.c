#include <stdio.h>
#include <string.h>

void criptografia (char *text){
	
	for(int i = 0; i < strlen(text); i++){
		if( *(text + i) == 'z' || *(text + i) == 'Z') {
			*(text + i) -= 23;
		} else if( *(text + i) == 'y' || *(text + i) == 'Y'){
			*(text + i) -= 23;
		} else if( *(text + i) == 'x' || *(text + i) == 'X'){
			*(text + i) -= 23;
		} else
			*(text + i) += 3;
	}

}

int main()	{
	
	char text[30];
	scanf("%s",text);
	criptografia(text);
	printf("%s\n",text);

}