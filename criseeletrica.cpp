#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int verifica(vector<int> redes, vector<int> vistas,int i, int entradas, int logica){

    int diferenca = logica - (entradas - i), j = 0, saida, count, intervalo;
    saida = diferenca;
    cout << i << "\n";
    if(i + logica >= entradas){
        for(j = 0; j < diferenca; j++){
            if(*find(vistas.begin(), vistas.end(), redes[j]) == redes[j]){
                saida += 1;
            }
        }
    }
    else{
        saida = i + logica;
        count = i + logica;
        
        for(j = i +  1; j <= count;j++){
            if(*find(vistas.begin(), vistas.end(), redes[j]) == redes[j]){
                saida += 1;
                cout << redes[j] << "Redesemj\n";
            }
        }
    }
    if(saida >= entradas){
        saida = verifica(redes, vistas, saida, entradas,logica);
    }
    cout << saida << "saida\n\n";
    return saida;
}



int main(){
    int entradas, logica, salvai;
    
    do{
        vector<int> redes, vistas;
        cin >> entradas;
        logica = (int)(entradas - 2)/2;
        
        for(int i = 1; i < entradas + 1; i++){
            redes.push_back(i);
        }
        int i = 0;
        while(redes.size() > vistas.size()){

            vistas.push_back(redes[i]);
            if(vistas.size()>1){
                i = verifica(redes, vistas, i, entradas, logica);
            }   
            else{
                i += logica;
            }
        }
        for(i = 0; i < entradas; i++){
            cout << vistas[i] << "\n";
        }

    }while(entradas != 0);
}