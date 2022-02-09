#include<stdio.h>
#include <alloc.h>
int main ()
{
 int y, x=3, k=5, *p,*q; //declara 5 variaveis, sendo 2 do tipo ponteiro
 p = &x; // p recebe o endereco de x
 q = (int *)malloc(6 * sizeof(int)); //aloca dinamicamente o ponteiro q com 6 posicoes
 for(y = 0; y< 3; y++) //inicia um ciclo for para ser realizado 3 vezes
 {
 p--; //diminui o valor do endereco de p em 1;
 scanf(“%d”, p); //pede um valor para o endereco de p;
 p++; //aumenta o valor do endereco inserido para p em 1;
 scanf(“%d”, p); //pede outro valor para o endereco de p
 *q = k; //atribui o ponteiro q para a variavel k;
 *(q+1) = x; //o valor da posicao q + 1 recebe o endereco de x;
 q = q + 2; //o endereco de q eh aumentado em 2(percorre o vetor em 2 posicoes);
 } 
}