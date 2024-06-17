// O objetivo deste código é imprimir apenas a primeira letra de cada palavra de uma string.
// Mais especificamente, ele imprime o primeiro caractere (variavel[0]) se for alpha e os caracteres alpha que vêm logo após um espaço.

#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

int main(){
    int num_casos;
    char mensagens[52];

    cin >> num_casos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i = 0; i < num_casos; i++){
        cin.getline(mensagens, 52);

        int j = 0;
        while(mensagens[j] != '\0'){
            if((j == 0 && isalpha(mensagens[j])) || (isblank(mensagens[j - 1]) && isalpha(mensagens[j]))){
                cout << mensagens[j];
            }
            j += 1;
        }
        cout << endl;
    }

    return 0;
}
