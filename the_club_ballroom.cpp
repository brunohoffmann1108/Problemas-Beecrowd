#include <iostream>
#include <string>
using namespace std;

int main(){
    int x; // largura da sala.
    int y; // Profundidade da sala.
    cin >> x >> y;

    while(x != 0 && y != 0){
        int largura_tabua;
        cin >> largura_tabua;

        int* minimoX = nullptr;
        if((x * 100) % largura_tabua == 0){
            minimoX = new int;
            *minimoX = x * 100 / largura_tabua;
        }
        int* minimoY = nullptr;
        if((y * 100) % largura_tabua == 0){
            minimoY = new int;
            *minimoY = y * 100 / largura_tabua;
        }

        // Entrada do número de tábuas disponíveis e alocação de um vetor do mesmo tamanho.
        int num_tabuas;
        cin >> num_tabuas;
        int* vetorX = new int[num_tabuas];
        int* vetorY = new int[num_tabuas];

        int preenchidosX = 0, tabuasX = 0;
        int preenchidosY = 0, tabuasY = 0;
        for(int i = 0; i < num_tabuas; i++){
            cin >> vetorX[i];
            vetorY[i] = vetorX[i];
            if(minimoX != nullptr){
                if(preenchidosX < *minimoX){
                    if(vetorX[i] == y){
                        preenchidosX += 1;
                        tabuasX += 1;
                        vetorX[i] = 0;
                    }
                    else{
                        for(int j = 0; j < i; j++){
                            if(vetorX[i] + vetorX[j] == y){
                                preenchidosX += 1;
                                tabuasX += 2;
                                vetorX[i] = vetorX[j] = 0;
                                break;
                            }
                        }
                    }
                }
                else if(tabuasX > *minimoX){
                    if(vetorX[i] == y){
                        tabuasX -= 1;
                    }
                }
            }
            if(minimoY != nullptr){
                if(preenchidosY < *minimoY){
                    if(vetorY[i] == x){
                        preenchidosY += 1;
                        tabuasY += 1;
                        vetorY[i] = 0;
                    }
                    else{
                        for(int j = 0; j < i; j++){
                            if(vetorY[i] + vetorY[j] == x){
                                preenchidosY += 1;
                                tabuasY += 2;
                                vetorY[i] = vetorY[j] = 0;
                                break;
                            }
                        }
                    }
                }
                else if(tabuasY > *minimoY){
                    if(vetorY[i] == x){
                        tabuasY -= 1;
                    }
                }
            }
        }
        int minimo = 100001;
        if(minimoY != nullptr && preenchidosY == *minimoY && tabuasY > 0) minimo = tabuasY;
        if(minimoX != nullptr && preenchidosX == *minimoX && tabuasX < minimo) minimo = tabuasX;
        if(minimo == 100001) cout << "impossivel" << endl;
        else cout << minimo << endl;

        cin >> x >> y;
    }

    return 0;
}
