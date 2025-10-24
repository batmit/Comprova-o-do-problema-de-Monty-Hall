#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){


    int contTroca = 0, contKeep = 0;
    
    srand(time(NULL));

    for(int i = 0; i < 1000000; i++){
    
        int portas[3] = {0, 0, 0};

        // SORTEIA A CHAVE
        int sorteioChave = rand() % 3;

        portas[sorteioChave] = 1;

        //ESCOLHO UMA PORTA
        int escolha = rand() % 3;

        // UM GORILA SAI
        int saiGorila = rand() % 2;
        int cont = 0;
        for(int j = 0; j < 3; j++){

            if(portas[j] == 0 && saiGorila == cont){

                portas[j] = -1;
                break;

            }else if(portas[j] == 0){
                cont++;

            }

        }

        // NÃO VOU TROCAR DE PORTA
        if(i % 2 == 0){

            if(portas[escolha] == 1){
                contKeep++;
            }

        //VOU TROCAR DE PORTA
        }else{

            for(int j = 0; j < 3; j++){

                if(portas[j] != -1 && j != escolha){
                    escolha = j;
                    break;
                }


            }

            if(portas[escolha] == 1){
                contTroca++;
            }

        }



    }

    printf("\nQuantidade de vitórias sem trocar de porta: %d", contKeep);
    printf("\nQuantidade de vitórias trocando de porta: %d", contTroca);





    return 0;
}