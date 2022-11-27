#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
    ll entradas, n, m, x, y;
        vector<string> saidas;
    do{
        cin >> entradas;
        if(entradas != 0){
            cin >> n >> m;
            
            for(int i = 0; i < entradas; i++){
                cin >> x >> y;
                if(x == n || y == m){
                    saidas.push_back("divisa");
                }else if(x > n && y > m){
                    saidas.push_back("NE");
                }else if(x > n && y < m){
                    saidas.push_back("SE");
                }else if(x < n && y > m){
                    saidas.push_back("NO");
                }else{                
                    saidas.push_back("SO");
                }
            }
        }
    }while(entradas != 0);

    for(int i = 0; i < saidas.size(); i++){
        cout << saidas[i] << "\n";
    }

    return 0;
}