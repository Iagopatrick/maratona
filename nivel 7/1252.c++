#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void ordena(list<int> lista, int m){
    list<int>::iterator i;
    list<int> nl;
    int maior, menor, meio;
    
    maior = menor = meio = lista.back();
    for(i = lista.begin(); i != lista.end(); i++){
        if ( *i%m >= maior%m){
            if(*i%m == maior%m){
                if((*i%m)%2 == 0){
                    nl.push_front(*i);
                    maior = *i;
                }else{
                    nl.
                }

            }
        }else if(*i%m <= menor%m){
            nl.push_back(*i);
            menor = *i;
        }else if(*i%m >= meio%m){
            nl[]
        }
    }
    


}


int main(){
    list<int> lista;
    int n = 1, m = 1, maior = 0, num;
    while((cin >> n >> m)&&(n != 0 && m != 0)){
        
        for(int i = 0; i < n; i++){
            cin >> num;
            if(num%m > maior%m){
                maior = num;
                lista.
            }
        }
        

    }



    return 0;
}