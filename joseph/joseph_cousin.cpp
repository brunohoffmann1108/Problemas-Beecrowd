#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int qtd_pessoas;
    cin >> qtd_pessoas;

    int pessoas[3501];
    for(int i = 0; i < qtd_pessoas; i++){
        pessoas[i] = i + 1;
    }

    int iterador_fixo = -1;
    int j = 3;

    if(qtd_pessoas > 1){
        iterador_fixo += 2;
        for(int k = iterador_fixo; k < qtd_pessoas - 1; k++){
            pessoas[k] = pessoas[k + 1];
        }
        qtd_pessoas -= 1;
        iterador_fixo -= 1;
    }

    while(1 < qtd_pessoas){
        for(int k = 3; k <= sqrt(j); k += 2){
            if(j % k == 0){
                j += 2;
                k = 1;
            }
        }
        cout << iterador_fixo + 1 << endl << j << endl << qtd_pessoas << endl;
        if(iterador_fixo + 1 + j > qtd_pessoas){
            j -= qtd_pessoas - (iterador_fixo + 1);
            iterador_fixo = -1;
        }
        cout << "J: " << j << endl;
        iterador_fixo += j;
        for(int k = iterador_fixo; k < qtd_pessoas - 1; k++){
            pessoas[k] = pessoas[k + 1];
        }
        qtd_pessoas -= 1;
        j += 2;
        iterador_fixo -= 1;

        cout << "Pessoas" << endl;
        for(int k = 0; k < qtd_pessoas; k++){
            cout << pessoas[k] << endl;
        }
        cout << endl;       
    }

    for(int k = 0; k < qtd_pessoas; k++){
        cout << pessoas[k] << endl;
    }
    return 0;
}    