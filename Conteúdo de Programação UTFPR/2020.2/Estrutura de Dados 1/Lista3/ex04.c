#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[15];
	int numAmigos;
	char *listaAmigos;
} user;

void desalocaMemoria(int **vet){
	free(*vet);
	*vet = NULL;
}

user *aloca(int n){
	user *usuario;
	usuario = (user *)malloc(n * (sizeof(user)));
	if(usuario == NULL){
		return NULL;
	} else {
		return usuario;
	}
}

void preenche(user *usuario, int n){
	int amizades;

	for(int i = 0; i < n; i++){
		setbuf(stdin, NULL);
		printf("\n***USUARIO %d***\n", i + 1);
		printf("Nome: ");
//		fgets((usuario+i)->nome, 15, stdin);
		scanf("%s", (usuario+i)->nome);
		printf("Num de amigos: ");
		scanf("%d", &(usuario+i)->numAmigos);
		amizades = (usuario + i)->numAmigos;
		(usuario + i)->listaAmigos = (char *)malloc(15*sizeof(char));
		for(int j = 0; j < amizades; j++){
			setbuf(stdin, NULL);
			printf("Amigo %d: ", j+1);
//			fgets(usuario[i]->listaAmigos[j], 15, stdin);
			scanf("%s", &(usuario + i)->listaAmigos[j]);
		}
	}
}

int *popularidade(user *usuario, int n){
	int *popular = (int *)malloc(n * sizeof(int));

	printf("\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int aux = 0; aux < n; aux++){
				if(*(usuario+i)->nome == (usuario+j)->listaAmigos[aux] && i != j){
					++*(popular + i);
				}
			}
		}
		printf("Popularidade do %s: %d\n", (usuario+i)->nome, *(popular + i));
	}
}

void main(){
	int n;
	printf("Insira a quantidade de usuarios da sua rede social: ");
	scanf("%d", &n);

	user *usuarios;
	int *popular;

	usuarios = aloca(n);
	preenche(usuarios, n);
	popular = popularidade(usuarios, n);


}
