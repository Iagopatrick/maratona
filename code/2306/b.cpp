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

int main(){
    FASTIO;
    ll t;
    cin >> t;
    FOR(i, 0, t){
        ll n, m;
        vector<vll> matrix;
        cin >> n >> m;
        FOR(j, 0, n){
            vll temp;
            matrix.PB(temp);
            FOR(k, 0, m){
                ll aux;
                cin >> aux;
                matrix[j].PB(aux);
            }
        }
        //1 verificar se existem os vizinhos
        //guardar o maior vizinho
        // verificar se todos vizinhos são menores que o ponto atual
        FOR(j, 0, matrix.size()){
            
            FOR(k, 0, matrix[j].size()){
                ll nmax = 0;
                bool greater = false;
                if(j - 1 >= 0){
                    greater = matrix[j][k] > matrix[j-1][k];
                    nmax = matrix[j-1][k];
                }else greater = true;
                if(!greater) continue;
                if(j + 1 < matrix.size()){
                    greater = matrix[j][k] > matrix[j+1][k];
                    if(nmax < matrix[j+1][k]){
                        nmax = matrix[j+1][k];
                    }
                }else greater = true;
                if(!greater) continue;
                if(k-1 >= 0){
                    greater = matrix[j][k] > matrix[j][k-1];
                    if(nmax < matrix[j][k-1]){
                        nmax = matrix[j][k-1];
                    }
                }else greater = true;
                if(!greater) continue;
                if(k + 1 < matrix[j].size()){
                    greater = matrix[j][k] > matrix[j][k+1];
                    if(nmax < matrix[j][k+1]){
                        nmax = matrix[j][k+1];
                    }
                }else greater = true;
                if(!greater) continue;
                ll dif = matrix[j][k] - nmax;
                matrix[j][k] = nmax;
            }
        }

        for(auto row: matrix){
            for(auto column: row){
                cout << column << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

