// Este programa lê uma sequencia de até 300 caracteres. Seu objetivo é ser um tradutor do sistema dial number, onde números são representados por
// letras (útil para decorar números de telefone).
// Imprime números e os caracteres '#' e '*' normalmente. Caso seja uma letra, converte para o respectivo número. O restante é descartado.
// Encerra se a entrada estiver vazia.

#include <iostream>
#include <cctype>
using namespace std;

int main(){
    // Tabela de conversão
    int tabela[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9}; 

    char dial[302];

    while(1){
        int i = 0;
        cin.getline(dial, 300);
        if(dial[i] == '\0') break;
        while(dial[i] != '\0'){
            if(isdigit(dial[i]) || dial[i] == '*' || dial[i] == '#'){
                cout << dial[i];
            }
            else if(isalpha(dial[i])){
                cout << tabela[toupper(dial[i]) - 65]; // Deixa a letra em maiúsculo e diminui 65 do valor ASCII (A = 65) para bater com a posição do vetor
            }

            ++i;
        }
        
        cout << endl;
    }

    return 0;
}