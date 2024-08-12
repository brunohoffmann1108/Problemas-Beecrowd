#include <stdio.h>

void insertion_sort(int princesa[3]){
    for(int i = 1; i < 3; i++){
        int chave = princesa[i];
        int j = i - 1;
        while(j > -1 && princesa[j] > chave){
            princesa[j + 1] = princesa[j];
            j -= 1;
        }
        princesa[j + 1] = chave;
    }

    for(int i = 0; i < 3; i++){
        printf("%i ", princesa[i]);
    }
}

int compara_cartas(int princesa[3], int principe[2]){
    int vitorias_princesa = 0;

}

int main(){
    int princesa[3];
    int principe[2];
    while(1){
        scanf("%i %i %i %i %i", &princesa[0], &princesa[1], &princesa[2], &principe[0], &principe[1]);
        if(princesa[0] == 0){
            break;
        }
        // Ordena vetores.
        if(principe[0] > principe[1]){
            int temp = principe[0];
            principe[0] = principe[1];
            principe[1] = temp;
        }
        insertion_sort(princesa);

    }

    return 0;
}
