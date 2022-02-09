#include <stdio.h>

void main(){
	int L, C;
	int aux, contL = 0, contC = 0, contT = 0, cont1 = 0, cont2 = 0, cont3 = 0, ordem;

	do{
		printf("Insira a quantidade de linhas: ");
		scanf("%d", &L);
		printf("Insira a quantidade de colunas: ");
		scanf("%d", &C);
	} while((L <= 0 || C <= 0) && (L >= 300 || L >= 300));

	ordem = L * C;
	int conteineres[L][C];
	int conteineres2[L][C];

	printf("Insira a posicao dos conteineres apos o protesto\n");
	for(int i = 0; i < L; i++){
		for(int j = 0; j < C; j++){
			printf("[%d][%d] = ", i, j);
			scanf("%d", &conteineres[i][j]);
			conteineres2[i][j] = conteineres[i][j];
		}
	}

	while(cont1 <= L - 1){
		for(int i = 1; i < L; i++){
			for(int j = 0; j < C; j++){
				if(conteineres[i][j] < conteineres[i - 1][j]){
					aux = conteineres[i][j];
					conteineres[i][j] = conteineres[i -1][j];
					conteineres[i -1][j] = aux;
				}
			}
		}
		++cont1;
	}
	
	for (int i = 0; i < L; i++){
		if (conteineres2[i][0] != conteineres[i][0]){
			contL++;
		}
	}
	if(contL == 0){
		contL++;
	}
	
	int conteineres3[L][C];

	for(int i = 0; i < L; i++){
		for(int j = 0; j < C; j++){
			conteineres3[i][j] = conteineres[i][j];
		}
	}

	for(int i = 0; i < L; i++){
		for(int j = 0; j < C; j++){
			if(i == L - 1){
				if(conteineres[i][j] - C == conteineres[i-1][j]){
				cont3++;
				}
			} else if (conteineres[i][j] + C == conteineres[i+1][j])
			{
				cont3++;
			}
		}
	}

	if(cont3 == ordem){
		while(cont2 <= C - 1){
			for(int i = 0; i < L; i++){
				for(int j = C - 1; j > 0; j--){
					if(conteineres[i][j] < conteineres[i][j - 1]){
						aux = conteineres[i][j];
						conteineres[i][j] = conteineres[i][j -1];
						conteineres[i][j - 1] = aux;
					}
				}
			}	
			++cont2;
		}
	
		for (int i = 0; i < C; i++){
			if (conteineres3[0][i] != conteineres[0][i]){
				contC++;
			}
		}
	
		if(contC == 0){
			contC++;
		}

		contT = contL - 1 + contC - 1;
		printf("%d\n", contT);
	} else {
		printf("*\n");
	}	

}