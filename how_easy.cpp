// Este código resolve o problema 1243 do Beecrowd

#include <iostream>
#include <string>
using namespace std;

int main(){
    string enunciado;
    while(getline(cin, enunciado)){
        int num_palavras = 0;
        int tamanho_total = 0;
        
        unsigned i = 0;
        while(i < enunciado.size()){
            int tamanho_palavra = 0;

            // Caso o symbol comece com uma letra.
            if(isalpha(enunciado[i]) && (enunciado[i - 1] == ' ' || i == 0)){
                i += 1;
                tamanho_palavra += 1;
                while(i < enunciado.size() + 1){
                    if(isalpha(enunciado[i])){
                        tamanho_palavra += 1;
                        i +=1;
                    }
                    else if(enunciado[i] == '.' && (enunciado[i + 1] == ' ' || i + 1 == enunciado.size())){
                        i += 2;
                        num_palavras += 1;
                        break;
                    }
                    else if(enunciado[i] == ' ' || i == enunciado.size()){
                        num_palavras += 1;
                        i += 1;
                        break;
                    }
                    else{
                        tamanho_palavra = 0;
                        i += 1;
                        while(i < enunciado.size()){
                            if(enunciado[i] != ' ' && enunciado[i - 1] == ' '){
                                break;
                            }
                            i += 1;
                        }
                        break;
                    }
                }
            }

            // Caso não comece com uma letra.
            else{
                i += 1;
                while(i < enunciado.size()){
                    if(enunciado[i] != ' ' && enunciado[i - 1] == ' '){
                        break;
                    }
                    i += 1;
                }
            } 
            tamanho_total += tamanho_palavra;
        }

        int media;
        if(num_palavras == 0) media = 0;
        else media = tamanho_total / num_palavras;

        if(media <= 3) cout << 250 << endl;
        else if(media <= 5) cout << 500 << endl;
        else cout << 1000 << endl;
    }

    return 0;
}
