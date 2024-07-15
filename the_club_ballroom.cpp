#include <iostream>
using namespace std;

int main(){
    int x; // largura da sala.
    int y; // Profundidade da sala.
    cin >> x >> y;

    while(x != 0 && y != 0){
        int larg_tabua;
        cin >> larg_tabua;
        // int num_tabuas;
        // cin >> num_tabuas;

        int* vetorX = nullptr;
        // Caso a largura das tábuas feche com a largura da sala.
        if((x * 100) % larg_tabua == 0){
            int tabuas_necessarias = (x * 100) / larg_tabua; 
            vetorX = new int[tabuas_necessarias];
            for(int i = 0; i < tabuas_necessarias; i++){
                vetorX[i] = y;
            }
        }
        int* vetorY = nullptr;
        // Caso a largura das tábuas feche com a profundidade da sala.
        if((y * 100) % larg_tabua == 0){
            int tabuas_necessarias = (y * 100) / larg_tabua;
            vetorY = new int[tabuas_necessarias];
            for(int i = 0; i < tabuas_necessarias; i++){
                vetorY[i] = x;
            }
        }

        cin >> x >> y;
    }

    return 0;
}
