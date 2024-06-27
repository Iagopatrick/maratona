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
        ll x, y, k, _k = 0, aux;
        cin >> x >> y >> k;
        aux = k;
        while(_k < k){
            ll divisor, ob;
            if(x % y == 0){
                x += 1;
                _k ++;
                
            }
            divisor = x/y + 1;
            ob = divisor * y;
            _k += abs(ob-x);
            if(_k > k){
                x += aux;
                break;;
            }
            x = ob;
            aux -= aux - _k >= 0? _k: 0;
            x = ll(log10(x)/log10(y));

            
        }
        cout << x<< endl;
        
        
    }

    return 0;
}

