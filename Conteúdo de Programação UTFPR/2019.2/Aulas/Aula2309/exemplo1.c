#include<stdio.h>
int main()
{
int n, contador;
int soma = 0;

printf("Digite um numero positivo para ser somado ou negativo para sair: ");
scanf("%d", &n);
contador = 0;
while( n >= 0 ) 
{
soma = soma + n;
printf("Digite um numero positivo para ser somado ou negativo para sair: ");
scanf("%d", &n);
contador = contador + 1;
}
printf("A quantidade de numeros somados eh %d\n", contador);
printf("A soma eh %d\n", soma);
return 0;
}
