#include <bits/stdc++.h>

using namespace std;

int main(){
    int op, cont = 0, index = 1;
    string p;

    cin >> op >> p;

    for(int i = 0; i < op; i++){
       
        if(p[i] == 'L'){
            if(index == 1){
                index = 1;
                continue;
            }else{
                index--;
            }
        }else{
            if(index == 3){
                index = 3;
            }
            else{
                index++;
            }
        }
        if(index == 3){
            cont++;
        }
    }
    cout << cont;




    return 0;
}