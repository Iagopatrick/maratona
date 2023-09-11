#include <bits/stdc++.h>

using namespace std;

int main(){
    int dia, semanas;
    
    cin >> dia >> semanas;
    if(dia + (semanas * 7) > 30){
        cout << "0\n";
    }else{
        cout << "1\n";

    }



    return 0;
}   