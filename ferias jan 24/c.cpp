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
typedef struct point{
    ll x, y;
}Point;

int main(){
    FASTIO;
    ll t, n, f, a, b, tm = 0;
    cin >> t;
    FOR(i, 0, t){
        cin >> n >> f >> a >> b;
        vll messages;
        ll temp;
        tm = 0;
        FOR(j, 0, n){
            cin >> temp;
            messages.push_back(temp);
            
        }
        FOR(j, 0, n){
            if(messages[j] - tm >= b || (messages[j] - tm) * a >= b){
                tm = messages[j];
                f -= b;
                
                
            }else{
                f -= a * (messages[j] - tm);
                tm = messages[j];
            }
            if(f < 0) break;
            
        }
        if(f > 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}

