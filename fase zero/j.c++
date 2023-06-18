#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll entrada, fb = 1, fb1 = 1, tmp;
    string c1, c2;
    cin >> entrada;
    cin >> c1 >> c2;

    for(ll i = 0 ;i < entrada; i++){
        tmp = fb;
        fb = fb1;
        fb1 += tmp;
    }
    if (entrada != 0){
        cout << fb1 << "\n";
    }else{
        cout << 0 << "\n";
    }
    

    return 0;
}