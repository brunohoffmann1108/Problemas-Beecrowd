#include <iostream>
using namespace std;

int calcula_minimo(int minimo_tabuas, int comprimento, int tabuas[100000], int tamanho_array, int guarda_tabuas[10000]){
    int i = 0;
    int total_tabuas = 0;
    int preenchidos = 0;
    while(i < tamanho_array && preenchidos < minimo_tabuas){
        if(comprimento - tabuas[i] == tabuas[i] && guarda_tabuas[tabuas[i] - 1] < 2){
            i += 1;
            continue;
        }
        if(tabuas[i] == comprimento){
            preenchidos += 1;
            total_tabuas += 1;
            guarda_tabuas[tabuas[i] - 1] -= 1;
        } 
        else if(tabuas[i] < comprimento && guarda_tabuas[comprimento - tabuas[i] - 1] > 0 && guarda_tabuas[tabuas[i] - 1] > 0){
            guarda_tabuas[tabuas[i] - 1] -= 1;
            guarda_tabuas[comprimento - tabuas[i] - 1] -= 1;
            preenchidos += 1;
            total_tabuas += 2;
        }
        i += 1;
    }
    while(i < tamanho_array && total_tabuas > minimo_tabuas){
        if(tabuas[i] == comprimento){
            total_tabuas -= 1;
        }
        i += 1;
    }
    if(preenchidos == minimo_tabuas) return total_tabuas;
    else return 100001;

}

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;

        int l, k;
        cin >> l >> k;

        int tabuas[100000] = {0};
        int tabuasN[10000] = {0};
        int tabuasM[10000] = {0};
        for(int i = 0; i < k; i++){ 
            cin >> tabuas[i];
            tabuasN[tabuas[i] - 1] += 1;
            tabuasM[tabuas[i] - 1] += 1;
        }

        int minimoN = 100001;
        if((n * 100) % l == 0 && n * 100 / l <= k){
            int minimo_tabuas = n * 100 / l;
            minimoN = calcula_minimo(minimo_tabuas, m,  tabuas, k, tabuasN);
        }
        
        int minimoM = 100001;
        if((m * 100) % l == 0 && m * 100 / l <= k){
            int minimo_tabuas = m * 100 / l;
            minimoM = calcula_minimo(minimo_tabuas, n, tabuas, k, tabuasM);
        }

        if(minimoM <= minimoN && minimoM != 100001) cout << minimoM << endl;
        else if(minimoN < minimoM) cout << minimoN << endl;
        else cout << "impossivel" << endl;
    }

    return 0;
}