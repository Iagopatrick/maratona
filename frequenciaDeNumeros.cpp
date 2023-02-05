#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
    int numEntradas, x;
    vector<int> saidas, frequencia;
    cin >> numEntradas;
    for(int i = 0; i < numEntradas; i++){
        cin >> x;
        if(saidas.size() > 1){
            if(*find(saidas.begin(), saidas.end(), x) != x){
                saidas.push_back(x);
                frequencia[x] = 1;
            }
        }else{
            saidas.push_back(x);
            frequencia[x] = 1;
        }
        frequencia[x] += 1;
    }

    for(int i = 0; i < frequencia.size(); i++){
        cout << saidas[i] << " aparece " << frequencia[saidas[i]]<< " vez(es)\n";


    }






    return 0;
}