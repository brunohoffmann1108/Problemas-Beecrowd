#include <iostream>
#include <cmath>
using namespace std;

void determina_primos(int vetor[3501], int quantidade){
    int i = 2;
    int j = 5;

    while(i < quantidade){
        for(int k = 3; k <= sqrt(j); k += 2){
            if(j % k == 0){
                j += 2;
                k = 1;
            }
        }
        vetor[i] = j;
        j += 2;
        i += 1;
    }
}

int main(){
    int qtd_pessoas;
    int seq_primos[3501] = {2, 3};

    cin >> qtd_pessoas;
    determina_primos(seq_primos, qtd_pessoas - 1);

    return 0;
}    