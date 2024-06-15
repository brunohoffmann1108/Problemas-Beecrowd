#include <stdio.h>

int main() {
    char diamantes[1000];
    int testCases;
    int abre = 0, contagemDiamantes = 0;

    scanf("%i", &testCases);
    for(int i = 0; i < testCases; i++){
        scanf("%s", diamantes);
        for(int j = 0; j < 1000; j++){
            if(diamantes[j] == '\0') break;
            if(diamantes[j] == '<'){
                abre += 1;
            }
            else if(diamantes[j] == '>' && abre != 0){
                contagemDiamantes += 1;
                abre -= 1;
            }
        }
        printf("%i\n", contagemDiamantes);
        contagemDiamantes = 0;
        abre = 0;
    }

    return 0;
}
