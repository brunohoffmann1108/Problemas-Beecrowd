 #include <iostream>
 #include <string>
 using namespace std;

int main(){
  string cavalheiro;
  getline(cin, cavalheiro);

  while(cavalheiro != "0"){
    // Calcula os movimentos de todos os peões e armazena-os.
    string peoes[8];
    string movimentos_peoes[16];
    int k = 0;
    for(int i = 0; i < 8; i++){
      getline(cin, peoes[i]);
      movimentos_peoes[k] = string(1, peoes[i][0] - 1) + string(1, peoes[i][1] + 1);
      k += 1;
      movimentos_peoes[k] = string(1, peoes[i][0] - 1) + string(1, peoes[i][1] - 1);
      k += 1;
    }

    // Calcula os movimentos do cavalo e armazena-os.
    k = 0;
    string movimentos__cavalheiro[8];
    for(int i = -2; i <= 2; i += 4){
      for(int j = -1; j <= 1; j += 2){
        movimentos__cavalheiro[k] = string(1, cavalheiro[0] + i) + string(1, cavalheiro[1] + j);
        k += 1;
        movimentos__cavalheiro[k] = string(1, cavalheiro[0] + j) + string(1, cavalheiro[1] + i);
        k += 1;
      }
    }

    getline(cin, cavalheiro);
  }


  return 0;
 }
