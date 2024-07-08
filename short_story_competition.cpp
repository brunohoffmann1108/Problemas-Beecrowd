#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
    int num_palavras;
    int linhas_ppg;
    int char_plinha; 

    while(cin >> num_palavras){
        cin >> linhas_ppg >> char_plinha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string historia;
        getline(cin, historia);
        int linhas = 0;

        while(historia.size() > 0){
            if(historia.size() <= (unsigned)char_plinha){
                historia.erase(0, historia.size());
                cout << historia << endl;
            }
            else if(historia[char_plinha - 1] == ' '){
                historia.erase(0, char_plinha);
                cout << historia << endl;
            }
            else if(historia[char_plinha] == ' '){
                historia.erase(0, char_plinha + 1);
                cout << historia << endl;
            }
            else{
                int i = char_plinha - 1;
                while(historia[i] != ' '){
                    i -= 1;
                }
                historia.erase(0, i + 1);
                cout << historia << endl;
            }
            
            linhas += 1;
        }
        cout << linhas << endl;
    }

    return 0;
}
