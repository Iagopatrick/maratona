#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    
    do{
        ll num1, num2, resultado;
        cin >> num1 >> num2;

        resultado = num2 - num1;

        if(num1 > num2){
            resultado = num1 - num2;
        }
        cout << resultado << "\n";
        
    }while(EOF);


    return 0;
}