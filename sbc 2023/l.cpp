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
    ll n;
    string word, nword;
    vector<char> w1, w2;

    bool index = true;

    cin >> word >> n;
    
    FOR(i,0,word.size()){
        w1.push_back(word[i]);
        w2.push_back(word[i]);
    }
    FOR(i, 0, n){
        if(w1[i] > w1[i+n]){
            w2[i] = w1[i+n];
            w2[i+n] = w1[i];
        }
    }
    FOR(i, 0, word.size()){
        cout << w2[i] << "";
    }

    //itera do lado direito e do lado esquerdo dir-> njoab - ojnab - oanjb // <-esq - njbao - nabjo - banjo

    return 0;
}