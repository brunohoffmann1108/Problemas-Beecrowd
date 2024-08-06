#include <stdio.h>
#include <stdlib.h>

typedef struct gnomo{
    char nome[20];
    int idade;
} gnomo;

void insertion_sort(gnomo lista_gnomos[], int num_gnomos){
    for(int k = 1; k < num_gnomos; k++){
        gnomo chave_struct = lista_gnomos[k];
        int i = k - 1;
        while(lista_gnomos[i].idade < chave_struct.idade && i > -1){
            lista_gnomos[i + 1] = lista_gnomos[i];
            i -= 1;
        }
        lista_gnomos[i + 1] = chave_struct;
    }
}


int main(){
    int num_gnomos;
    scanf("%i", &num_gnomos);

    gnomo* lista_gnomos;
    lista_gnomos = (gnomo*)malloc(num_gnomos * sizeof(gnomo));
    for(int i = 0; i < num_gnomos; i++){
        scanf("%s", lista_gnomos[i].nome);
        scanf("%i", &lista_gnomos[i].idade);
    }    

    insertion_sort(lista_gnomos, num_gnomos);

    int num_times = num_gnomos / 3;
    for(int i = 0; i < num_times; i++){
        printf("Time %i\n", i + 1);
        for(int j =  i; j < num_gnomos; j += num_times){
            printf("%s %i\n", lista_gnomos[j].nome, lista_gnomos[j].idade);    
        }
        printf("\n");
    }

    return 0;
}
