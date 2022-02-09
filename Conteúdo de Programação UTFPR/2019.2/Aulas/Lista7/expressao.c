#include <stdio.h>
#include <math.h>

int R, S;

void expressaoR(int A, int B){
	int soma;

	soma = A + B;
	R = pow(soma, 2);

}

void expressaoS(int B, int C){
	int soma;

	soma = B + C;
	S = pow(soma, 2);
	
}

void expressaoD(int R, int S){
	float D;
	int soma;
	
	soma = R + S;
	D = (float)(soma / 2);

	printf("D = %.2f\n", D);
}

int main(){
	int A, B, C;

	printf("Insira o numero A: ");
	scanf("%d", &A);
	printf("Insira o numero B: ");
	scanf("%d", &B);
	printf("Insira o numero C: ");
	scanf("%d", &C);

	expressaoR(A, B);
	expressaoS(B, C);
	expressaoD(*expressaoR, *expressaoS);

	return 0;
}
