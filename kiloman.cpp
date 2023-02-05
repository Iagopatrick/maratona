#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int numEntrada, qntdT;
    vector<int> saida;
    cin >> numEntrada;
    for(int i = 0; i < numEntrada; i++){
        string entrada;
        
        vector<int> tiros;
        saida.push_back(0);
        cin >> qntdT;
        for(int k=0; k < qntdT; k++){
            int x;
            cin >> x;
            tiros.push_back(x);
            
        }
        cin >> entrada;
        for(int j = 0; j < qntdT; j++){
            if(entrada[j] == 'S'){
                if(tiros[j] < 3){
                    
                    saida[i] += 1;
                }
            }
            else{
                if(tiros[j] > 2){
                    saida[i] += 1;
                }
            }
        }
    }

    for(int i = 0; i < saida.size(); i++){
        cout << saida[i] << "\n";
    }




    return 0;
}