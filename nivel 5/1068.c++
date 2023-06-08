#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string expression;
    while(cin >> expression){
        char a;
        ll cont = 0;
        stack<char> lista;

        for(ll i = 0; i < expression.length(); i++){
            a = expression[i];
            if(a == ')' && lista.empty()){
                cout << "incorrect\n";
            }else if(a == ')'){
                cont++;
                lista.push(a);
            }else if(a == '('){
                cont--;
                lista.push(a);
            }

        if(cont == 0){
            cout << "correct" << "\n";
        }else{
            cout << "incorrect" << "\n";
        }
        cout << "passei por aqui \n";
        }
    };






    return 0;
}