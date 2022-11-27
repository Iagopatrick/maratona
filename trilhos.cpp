#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main(){
    ll numTrilhos, entradas, vagao, compara1, compara2;
    queue<ll> trilhos;
    while(entradas != 0){
        do{
            cin >> numTrilhos;
            if(numTrilhos != 0){
                for(int i = 0; i < numTrilhos; i++){
                    cin >> vagao;
                    trilhos.push(vagao);
                }
                for(int i = 0; i < numTrilhos; i++){
                    compara1 = trilhos.pop();

                }
            }

        }while(numTrilhos != 0);
    }

    return 0;
}