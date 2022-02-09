#include <stdio.h>

int main(){
	int idade,aux, contD, contM, contA;
	contA = 0;

	do{
		printf("Insira sua idade em dias: ");
		scanf("%d", &idade);
		aux = idade;
		contD = contM = contA = 0;
		if(aux < 30) {
			contD = aux;
			printf("%d dia(s)\n", contD);
		} else if (aux <= 365){
			while(aux >= 30){
				aux = aux - 30;
				++contM;
			}
			contD = aux;
			printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", contM, contD);
		} else	{
			while(aux >= 365){
				aux = aux - 365;
				++contA;
				while(aux > 30){
					aux = aux - 30;
					++contM;
				}
				contD = aux;
			printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", contA, contM, contD);
			}
		}
	}while(idade < 0);



	return 0;
}
