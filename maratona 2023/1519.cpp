#include <bits/stdc++.h>
using namespace std;


vector<pair<string, int>> troca(vector<pair<string, int>> abcdario){
    int flag = 0; //se tiver diferente de 0 esta na mesma letra
    char uL;
    string temp;
    for(int i = 0; i < abcdario.size(); i++){
        if(abcdario[i].first.size() <= 2){
            continue;
        }else{
            if(uL == abcdario[i].first[0]){
                flag++;
            }

            if(flag > 0){
                temp = "";
                for(int j = 0; j < flag; j++){
                    temp += abcdario[i].first[j];
                }
            
                abcdario[i].first = temp + '.';
            }else{
                abcdario[i].first = abcdario[i].first[0] + '.';
            }
        }

        uL = abcdario[i].first[0];
    }
    return abcdario;
}
// estava = es. estudei = e.



int main(){
    string entrada, copia, saida = "";
    char a;
    vector<pair<string, int>> abcdario;
    pair<string, int> abc;
    char aux;
    int cont = 0;
    do{
        cont = 0;
        getline(cin, entrada);
        for(int i = 0; i < entrada.size(); i++){
            copia = entrada; //colocar a copia = entrada para realizar o print do glossario "entrada" = "copia"

        }
            abc = make_pair(entrada, cont);
            abcdario.push_back(abc);
            cont++;
        cout << "saiu\n";
        sort(abcdario.begin(), abcdario.end());

        int flag = 0; //se tiver diferente de 0 esta na mesma letra
        char uL;
        string temp;
        for(int i = 0; i < abcdario.size(); i++){
            if(abcdario[i].first.size() <= 2){
                continue;
            }else{
                if(uL == abcdario[i].first[0]){
                    flag++;
                }

                if(flag > 0){
                    temp = "";
                    for(int j = 0; j < flag; j++){
                        temp += abcdario[i].first[j];
                    }
                
                    abcdario[i].first = temp + '.';
                }else{
                    abcdario[i].first = abcdario[i].first[0] + '.';
                }
            }

            uL = abcdario[i].first[0];
        }

        cout << abcdario.at(0).first;



    }while(entrada != ".");


    return 0;
}