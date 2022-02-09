#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char nome[15];
	int q_amigos;
	char lista_amigos[10][15];
}amigos;

void preenche(int n, amigos usuarios[n]){

	for(int i = 0; i < n; i++){
		printf("Insira o nome do usuario %d: ", i + 1);
		setbuf(stdin, NULL);
		fgets(usuarios[i].nome, 15, stdin);
		printf("Insira a quantidade de amigos deste usuario: ");
		scanf("%d", &usuarios[i].q_amigos);
		for(int j = 0; j < usuarios[i].q_amigos; j++){
			printf("Insira o nome do amigo %d: ", j + 1);
			setbuf(stdin, NULL);
			*fgets(usuarios[i].lista_amigos[j], 15, stdin);
		}
	}

}


void popularidade(int n, amigos usuarios[n]){
	int comp = 0, cont;

	for(int i = 0; i < n; i++){
		cont = 0;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < usuarios[j+1].q_amigos; k++){
				if(j != n-1){
					comp = strcmp(usuarios[i].nome, usuarios[j + 1].lista_amigos[k]);
					if(comp == 0){
						++cont;
					}
				} else{
					comp = strcmp(usuarios[i].nome, usuarios[0].lista_amigos[k]);
					if(comp == 0){
						++cont;
					}
				}
			}		
		}
		printf("%s %d\n", usuarios[i].nome, cont);
	}
}

void main(){
	int n;
	printf("Insira o numero de usuarios: ");
	scanf("%d", &n);

	amigos usuarios[n];

	preenche(n, usuarios);
	popularidade(n, usuarios);
}