#include <iostream>
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

        // Entrada do número de tábuas disponíveis e alocação de um vetor do mesmo tamanho.
        int num_tabuas;
        cin >> num_tabuas;
        int* tabuas = new int[num_tabuas];

        // Espaços já preenchidos por uma ou mais tábua.
        int preenchidosX = 0, tabuasX = 0;
        for(int i = 0; i < num_tabuas; i++){
            cout << i << endl;
            cin >> tabuas[i];
            if(preenchidosX < *minimoX){
                if(tabuas[i] == y){
                    preenchidosX += 1;
                    tabuasX += 1;
                    tabuas[i] = 0;
                    continue;
                }
                else{
                    for(int j = 0; j < i; j++){
                        if(tabuas[i] + tabuas[j] == y){
                            preenchidosX += 1;
                            tabuasX += 2;
                            tabuas[i] = tabuas[j] = 0;
                            break;
                        }
                    }
                }
            }
            else if(tabuasX > *minimoX){
                if(tabuas[i] == y){
                    tabuasX -= 1;
                    continue;
                }
            }
        }
        cout << preenchidosX << endl << tabuasX << endl;


        cin >> x >> y;
    }

    return 0;
}
