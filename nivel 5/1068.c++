#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string expression;
    while(cin >> expression){
        char a;
        
        stack<char> pilha;

        for(ll i = 0; i < expression.length(); i++){
            a = expression[i];
            if(a == '('){
                pilha.push(a);
            }else if(a == ')' && !pilha.empty()){
                pilha.pop();
            }else if(a == ')'){
                pilha.push(a);
                break;
            }
        }

        if(pilha.empty()){
            cout << "correct" << "\n";
        }else{
            cout << "incorrect" << "\n";
        }
        
    };






    return 0;
}