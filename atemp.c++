#include<bits/stdc++.h>

using namespace std;

int main(){
    bool flag = true;
   

    for(int i = 0; i < 1000; i++){
        cout << (flag? "Verdadeiro":"Falso!" )<< "\n";
        flag = !flag;
    }
    return 0;
}

// Maneira não otimizada
// int main(){
//     bool flag = true;
//     int x = 10;

//     for(int i = 0; i < x; i++){
//         if(flag){
//             cout << "Verdadeiro" << "\n";
//             flag = false;
//         }else if(!flag){
//             cout << "Falso!" << "\n";
//             flag = true;
//         }
//     }
//     return 0;
// }