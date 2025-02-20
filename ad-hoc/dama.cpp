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
    ll a, b, c, d;
    while(cin >> a >> b >> c >> d){
        ll cont = 0;
        if(a == b && b == c && b == d  && b == 0){
            break;
        }
        ll dif_line, dif_col;

        dif_line = a - c;
        dif_col = b - d;
        if(dif_line == 0 && dif_col == 0){
            cont = 0;
        }else if(dif_line == 0 || dif_col == 0){
            cont = 1;
        }else if(abs(dif_col) == abs(dif_line)){
            cont = 1;
        }else{
            cont = 2;
        }
    
        cout << cont << endl;
    }

    return 0;
}

