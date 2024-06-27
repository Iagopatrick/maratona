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
        ll x, y, ax, ay, greater, lower;
        cin >> x >> y >> ax >> ay;
        vll g, ag;
        if(x > y){
            g.PB(1);
            g.PB(0);
        }else{
            g.PB(0);
            g.PB(1);
        }
        if(ax > ay){
            ag.PB(1);
            ag.PB(0);
        }else{
            ag.PB(0);
            ag.PB(1);
        }
        if(g[0] == 1 && ag[0] == 1){
            cout << "YES";
        }else if(g[1] == 1 && ag[1] == 1){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}

