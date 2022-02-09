#include <stdio.h>

int Armazenar(float v[], int n);

void main(){
	float v[15];
	int n = 15, pmaior;

	pmaior = Armazenar(v, n);
	printf("[%d] = %.2f eh o maior vetor\n", pmaior + 1, v[pmaior]);
}

int Armazenar(float v[], int n){
	int i, maior, pmaior;

	printf("[1]= ");
	scanf("%f", &v[0]);
	maior = v[0];
	pmaior = 0;
	for(i = 1; i < n; i++){
		printf("[%d]= ", i + 1);
		scanf("%f", &v[i]);
		if(v[i] > maior){
			maior = v[i];
			pmaior = i;
		}
	}

	return pmaior;
}	
