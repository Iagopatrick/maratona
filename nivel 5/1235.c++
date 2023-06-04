#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string decodificador(string palavra){
    int tamanho;
    string decodificada = "", final = "";
    tamanho = palavra.length()/2;
    for(int i = 0; i < tamanho; i++){
        decodificada += palavra[tamanho - i - 1];
        final += palavra[-i-1];
    }
    decodificada += final;
    return decodificada;

}



int main(){
    int num, i;
    string palavra, word;
    cin >> num;
    for(i = 0; i < num; i++){
        cin >> palavra;

        word = decodificador(palavra);
        cout << word << "\n";

    }





    return 0;
}