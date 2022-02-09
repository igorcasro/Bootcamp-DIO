#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <time.h>

typedef struct {
	char code[3], comment[256];
	int tam_x, tam_y;
	int branco;
	unsigned short int * dados;
} imagem;

imagem entrada, saida;

void ajuste_branco(imagem* img) {

	int branco;
	branco = img->dados[0];
	for (long long int i = 1; i < img->tam_x*img->tam_y; i++)
	{
		if (img->dados[i] > branco)
		{
			branco = img->dados[i];
		}
	}
	img->branco = branco;
}

void grava_matriz(FILE* f, imagem img) {
	fprintf(f, "%s\n%s\n", img.code, img.comment);
	fprintf(f, "%d %d\n%d\n", img.tam_x, img.tam_y, img.branco);

	for (long long int i = 0; i < img.tam_y; i++)
	{
		for (long long int j = 0; j < img.tam_x; j++)
		{
			fprintf(f, "%0.3hu ", img.dados[(i*img.tam_x)+j]);
		}
		fprintf(f,"\n");
	}
	puts("saida gravada...");
}

void deleta_matriz(imagem *img) {
	free(img->dados);
}

void aloca_matriz(imagem *img) {
	if (NULL == (img->dados = (unsigned short int*)calloc(sizeof(unsigned short int),img->tam_x * img->tam_y * sizeof(unsigned short int)))) {
		puts("falha na alocacao de memoria.");
		exit(1);
	}
}

void leitura_matriz(FILE* in) {

	unsigned int  temp;
	aloca_matriz(&entrada);
	puts("entrada alocada");
	for (unsigned long long int i = 0; i < entrada.tam_x*entrada.tam_y; i++)
	{
		fscanf(in, "%u ", &temp);
		entrada.dados[i] = temp;
		//puts("dados lidos\n");
	}
}

void leitura_cabecalho(FILE* in, FILE* ou) {
	fscanf(in, "%s\n", entrada.code);
	fgets(entrada.comment, 256, in);
	fscanf(in, "%d %d\n%d", &entrada.tam_x, &entrada.tam_y, &entrada.branco);

	// copiando o cabecalho para a saida
	strcpy(saida.code, entrada.code);
	strcpy(saida.comment, entrada.comment);
	saida.tam_x = entrada.tam_x;
	saida.tam_y = entrada.tam_y;
	saida.branco = entrada.branco;
}

unsigned short int acessa_matriz(imagem img, unsigned long long int i, unsigned long long int j) {
	return img.dados[(i*img.tam_x)+j];
}

void escreve_matriz(imagem *img,unsigned long long int i, unsigned long long int j, unsigned short int valor) {
	img->dados[(i * img->tam_x) + j] = valor;
}

int distancia_quadrada(int x1, int y1, int x2, int y2) {
	return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

void T1(imagem* ou, imagem in, unsigned long long int i) {
	for (unsigned long long int  j = 0; j < ou->tam_x; j++)
	{
		escreve_matriz(ou, i, j, ou->tam_x * ou->tam_x);
	}
	for (unsigned long long int j = 0; j < in.tam_x; j++)
	{
		if (acessa_matriz(in,i,j) != in.branco)
		{
			for (unsigned long long int k = 0; k < in.tam_x; k++)
			{
				if (acessa_matriz(in,i,k) == in.branco)
				{
					int d = distancia_quadrada(j, i, k, i);
					if ((d < acessa_matriz(*ou, i, k)) || (acessa_matriz(*ou, i, k) == 0))
					{
						escreve_matriz(ou, i, k, d);
					}
				}
				else
				{
					if (k == j)
					{
						escreve_matriz(ou, i, k, 0);
					}
				}
			}
		}
	}
}

void T2(imagem* ou, imagem in, unsigned long long int j) {
	for (unsigned long long int  i = 0; i < in.tam_y; i++)
	{
		int soma = in.tam_x* in.tam_y;
		for (unsigned long long int  k = 0; k < in.tam_y; k++)
		{
			int d = distancia_quadrada(j, i, j, k);
			if ((d + acessa_matriz(in,k,j) < soma))
			{
				soma = d + acessa_matriz(in, k, j);
			}
		}
		escreve_matriz(ou, i, j, soma);
	}
}

void Calcula_TDE(imagem *saida, imagem entrada) {

	imagem transf_1 = entrada;
	aloca_matriz(&transf_1);

	
		for ( long long int i = 0; i < entrada.tam_y; i++)
		{
			T1(&transf_1, entrada, i);
		}
	
			
		for ( long long int j = 0; j < entrada.tam_x; j++)
		{
			T2(saida, transf_1, j);
		}
	
	
	deleta_matriz(&transf_1);
}

int main() {
	FILE* fin, * fou;
	char str[256];

	printf	("Nome do arquivo de entrada: ");
	scanf("%s", str);

	if (NULL == (fin = fopen(str, "r"))) {
		puts("erro na abrtura do arquivo de entrada.");
		exit(1);
	}

	str[strlen(str) - 4] = '\0';
	strcat(str, "-saida.pgm");
	if (NULL == (fou = fopen(str, "w"))) {
		puts("Erro na abertura do arquivo de saida.");
		exit(1);
	}

	// iniciando o programa...

	leitura_cabecalho(fin, fou);
	puts("cabecalho lido");
	leitura_matriz(fin);
	puts("leitura correta");
	aloca_matriz(&saida);


	clock_t ticks[2]; // usado para medir o tempo
	ticks[0] = clock();

	Calcula_TDE(&saida, entrada); // calculo da TDE

	ticks[1] = clock();
	double tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto em milissegundos % .3f\n", tempo);

	ajuste_branco(&saida);
	grava_matriz(fou,saida);

	fclose(fin);
	fclose(fou);

	deleta_matriz(&entrada);
	deleta_matriz(&saida);
}