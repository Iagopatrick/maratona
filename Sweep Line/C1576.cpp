// Comparação de substring
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for(ll i = (a); i< ll(b); ++i)
#define INT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<< #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define IN 1
#define OUT 0
struct Compare{
    bool operator()(vector<ll> x, vector<ll> y) const {
        if(x[0] == y[0]){
            return (x[1] < y[1]);
        }
        return (x[0] > y[0]);
    }

};

bool compareVector(vector<ll> a, vector<ll> b){
    if(a[0] == b[0]){
        if(a[2] == IN && b[2] == IN){
            return (a[1] > b[1]);
        }else if(a[2] == OUT && b[2] == OUT){
            return (a[1] < b[1]);
        }else{
            return (a[2] > b[2]);
        }
    }else{
        return (a[0] < b[0]);
    }
} 

int main(){
    FASTIO;
    ll l, h, r;
    vector<vector<ll>> v;
    
    vector<ll> resp, aux(10002, 0);
    while(cin >> l >> h >> r){
        
        v.PB(vector<ll> {l , h, IN});
        v.PB(vector<ll>{r, h, OUT}); //estou colocando o valor de l aqui, pois o h nós sabemos pelo valor de l. Ou seja, na saida, eu so quero saber quando ele entra para retirar ele do set 
        aux[r]
    }
    
    sort(v.begin(), v.end());

    ll s, currentValue;
    s = v.size();
    set<vector<ll>, Compare> x;
    x.insert(vector<ll>{v[0][1],v[0][0], v[0][2]}); //no set precisa ter {peso, x, tipoDeEvento}
    
    auto temp = x.begin();
    aux[v[0][0]] += v[0][1];
    currentValue = temp->at(0);

    resp.PB(v[0][0]);
    resp.PB(v[0][1]);
   
    

    FOR(i, 1, s){
        if(v[i][2]){
            
            x.insert(vector<ll>{v[i][1], v[i][0], v[i][2]});
            aux[v[i][0]] = v[i][1];
            if(x.begin()->at(0) != currentValue){
                currentValue = x.begin()->at(0);
                resp.PB(v[i][0]);
                resp.PB(v[i][1]);
                
            }

        }else{
                x.erase(vector<ll>{aux[v[i][1]], v[i][1], IN}); // v[i][1] -> é o meu x, o inicio e o meu aux[v[i][1]]-> é o peso dessa posição
                if(x.empty()){
                    resp.PB(v[i][0]);
                    resp.PB(0);
                    currentValue = 0;
                    continue;
                }
                if(x.begin()->at(0) != currentValue){
                
                    currentValue = x.begin()->at(0);
                    resp.PB(v[i][0]);
                    resp.PB(currentValue);
                    
                }   
        }
          
    }
    ll resp_ = resp.size();
    FOR(i, 0, resp.size()){
        cout << resp[i] << (i == resp_-1? "" : " ");
    }
    cout << endl;

    return 0;
}

