#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



ll gcd(ll a, ll b){
    if( b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){

    ll f1, f2, entradas, mdc, maior, menor;
    vector<ll> saidas;
    cin >> entradas;
    for(int i = 0; i < entradas; i++){
        cin >> f1 >> f2;    
        if(f1 > f2){
            maior = f1;
            menor = f2;
        }else{
            maior = f1;
            menor = f2;
        }
        mdc = gcd(maior, menor);
        saidas.push_back(mdc);
    }
    for(int i = 0; i < entradas; i++){
        cout << saidas[i] << "\n";
    }

    return 0;
}