#include <stdio.h>

int main(){

    char carros[5][20];
    int consumo[5];
    int maisEconomico = 1, posicaoMaisEconomico;

    for(int i = 0; i < 5; ++i){
        printf("Insira a marca do carro %d: ", i + 1);
        scanf("%s", carros[i]);
        do{
            printf("Insira o consumo do %s: ", carros[i]);
            scanf("%d", &consumo[i]);
        } while(consumo[i] <= 0);
        
        if(consumo[i] > maisEconomico){
            maisEconomico = consumo[i];
            posicaoMaisEconomico = i;
        }
    }
    printf("O modelo de carro mais economico eh o: %s\n", carros[posicaoMaisEconomico]);
    
    for(int i = 0; i < 5; ++i){
        printf("Para percorrer 1000km o %s consome %dL de combustivel.\n", carros[i], (consumo[i] * 1000));
    }
    
    return 0;
}
