#include <stdio.h> //declaracao de biblioteca
#include <stdlib.h> //declaracao de biblioteca

int main() //inicializacao da main
{
	int y, x = 3, k = 5, *p, *q; //inicializacao de 3 variaveis e dois ponteiros
	p = &x; //atribuicao de p ao endereco de x
	q = (int *)malloc(6 * sizeof(int)); //criacao de ponteiro dinamico
	for(y = 0; y < 3; y++){ //inicializacao do ciclo de repeticao for
		p--; //reducao de um no valor de x
		scanf("%d", p); //leitura de um novo valor para x
		p++; //aumento de um no valor de x
		scanf("%d", p); //leitura de um novo valor de x
		*q = k; //atribuicao de k para o ponteiro de vetor *q
		*(q+1) = x; //atribuicao de x para a segunda posicao do ponteiro
		q = q + 2; //"andamento" do vetor q em duas posicoes
	} //fim do ciclo for
} //fim da main