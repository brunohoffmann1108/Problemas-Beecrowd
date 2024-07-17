#include <iostream>
using namespace std;

int calcula_minimo(int minimo_tabuas, int comprimento, int tabuas[10000], int tamanho_array){
    int i = 0;
    int total_tabuas = 0;
    int preenchidos = 0;
    while(i < tamanho_array && preenchidos < minimo_tabuas){
        if(tabuas[i] == comprimento){
            preenchidos += 1;
            total_tabuas += 1;
            tabuas[i] = 0;
        } 
        else if(i > 0){
            for(int j = 0; j < i; j++){
                if(tabuas[j] + tabuas[i] == comprimento){
                    total_tabuas += 2;
                    preenchidos += 1;
                    tabuas[i] = tabuas[j] = 0;
                    break;
                }
            }
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

        int tabuasN[100000];
        int tabuasM[100000];
        int itN = 0;
        int itM = 0;
        for(int i = 0; i < k; i++){ 
            int temp;
            cin >> temp;
            if(temp <= n){
                tabuasM[itM] = temp;
                itM += 1;
            } 
            if(temp <= m){
                tabuasN[itN] = temp;
                itN += 1;
            }
        }

        int minimoN = 100001;
        if((n * 100) % l == 0 && n * 100 / l <= k){
            int minimo_tabuas = n * 100 / l;
            minimoN = calcula_minimo(minimo_tabuas, m, tabuasN, itN);
        }
        
        int minimoM = 100001;
        if((m * 100) % l == 0 && m * 100 / l <= k){
            int minimo_tabuas = m * 100 / l;
            minimoM = calcula_minimo(minimo_tabuas, n, tabuasM, itM);
        }

        if(minimoM < minimoN) cout << minimoM << endl;
        else if(minimoN < minimoM) cout << minimoN << endl;
        else cout << "impossivel" << endl;
    }

    return 0;
}