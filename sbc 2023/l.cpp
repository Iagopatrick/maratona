#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<< #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(ll i = (a); i< ll(b); ++i)


int main(){
    ll n, j = 0;
    string word, nword, gword;
    vector<char> w2, w3;
    char tmp, w1;
    bool flag = 0;

    bool index = true;

    cin >> word >> n;
    
    FOR(i,0,word.size()){
        
        w2.push_back(word[i]);
        w3.push_back(word[i]);
    }
    // FOR(i, 0, n){
    //     if(w1[i] > w1[i+n]){
    //         w2[i] = w1[i+n];
    //         w2[i+n] = w1[i];
    //     }
    // }
    int len = word.size();
    while(j + n < word.size()){
        if(w2[j] > w2[j+n]){
            w1 = w2[j];
            w2[j] = w2[j+n];
            w2[j+n] = w1;
            
        }
        if(w3[len-j-1] > w3[len-n-j-1]){
            w1 = w3[len-j-1];
            w3[len-j-1] = w3[len-n-j-1];
            w3[len-n-j-1] = w1;
            flag = 1;
        }
        j++;
    }
    
    ll k = 0;
    

    while(!w3.empty()){

        tmp = w3.back();
        gword += tmp; 
        w3.pop_back();
        nword += w2[k];
        k++;
        // cout << gword << endl;
    }
    
    if(gword >= nword || !flag) cout  << nword << endl;
    else cout << gword << endl;
    return 0;


   

    //itera do lado direito e do lado esquerdo dir-> njoab - ojnab - oanjb // <-esq - njbao - nabjo - banjo
}