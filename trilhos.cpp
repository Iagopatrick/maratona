#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main(){
    int numPertumacoes, entrada = -1, vagaoA, ultimo, primeiro, segundo;
    queue<int> trilhos;
    vector<string> respostas;
    
    while(entrada != 0){
        cin >> entrada;
        do{
            // cin >> numPertumacoes;
            primeiro = -1;
            segundo = 0;
            ultimo = 0;
            vagaoA = 0;
            if(entrada != 0){
                for(int i = 0; i < entrada; i++){
                    cin >> vagaoA;
                    if(vagaoA != 0){
                        trilhos.push(vagaoA);
                        if(i == 0){
                            ultimo = vagaoA;
                        }else if(i == numPertumacoes - 2){
                            segundo = vagaoA;

                        }
                        if(i == numPertumacoes - 1){
                            primeiro = vagaoA;
                        }
                        trilhos.pop();
                    }

                }
                if((primeiro > segundo && segundo > ultimo) || (primeiro < segundo && segundo < ultimo) ){
                    respostas.push_back("Yes");
                    cout << "oi\n";
                }else if(vagaoA!=0){
                    respostas.push_back("No");
                    


                }
                
                
            }


        }while( vagaoA != 0);
        for(int i = 0; i < respostas.size(); i++){
            cout << respostas[i] << "\n";
        }
    }

    return 0;
}