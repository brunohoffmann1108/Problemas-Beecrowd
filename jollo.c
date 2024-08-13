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
}

int checa_minimo(int carta_checada, int cartas[5]){
    carta_checada += 1;
    int i = 0;
    while(i < 5){
        if(carta_checada == 53) return -1;
        if(carta_checada == *(cartas + i)){
            carta_checada += 1;
            i = 0;
            continue;
        }
        i += 1;
    }
    return carta_checada;
}

int compara_cartas(int princesa[3], int principe[2], int cartas[5]){
    int vitorias = 0;
    int n = 3;
    for(int i = 1; i > -1; i--){
        int j;
        for(j = 0; j < n; j++){
            if(princesa[j] > principe[i]){
                vitorias += 1;
                break;
            }
        }
        if(j == n) j = 0;
        for(int k = j; k < n - 1; k++){
            princesa[k] = princesa[k + 1];
        }
        n -= 1;
    }
    if(vitorias == 2) return -1;
    if(vitorias == 0){
        int checada = 1;
        int i = 0;
        while(i < 5){
            if(checada == *(cartas + i)){
                checada += 1;
                i = 0;
                continue;
            }
        }
        return checada;
    }
    return checa_minimo(princesa[0], cartas);

}

int main(){
    int princesa[3];
    int principe[2];
    while(1){
        int cartas[5];
        int iterador_cartas = 0;
        for(int i = 0; i < 3; i++){
            scanf("%i", &princesa[i]);
            cartas[iterador_cartas] = princesa[i];
            iterador_cartas += 1;
        }
        for(int i = 0; i < 2; i++){
            scanf("%i", &principe[i]);
            cartas[iterador_cartas] = principe[i];
            iterador_cartas += 1;
        }
        if(princesa[0] == 0) break;
        // Ordena vetores.
        if(principe[0] > principe[1]){
            int temp = principe[0];
            principe[0] = principe[1];
            principe[1] = temp;
        }
        insertion_sort(princesa);
        // Compara cartas e retorna resultado.
        printf("%i\n", compara_cartas(princesa, principe, cartas));
    }

    return 0;
}
