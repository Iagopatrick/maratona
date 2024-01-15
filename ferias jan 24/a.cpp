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
    ll n, a, b, x, y, k;
    cin >> n;
    Point ax[2], ay[2];
    FOR(i, 0, n){
        k = 0;
        for(ll j = 0; j < 4; j++){
            cin >> a >> b;
            if(j == 0){
                ax[0].x = a;
                ax[0].y = b;
                continue;
            }else{
                if(ax[0].x == a){
                    ax[1].x = a;
                    ax[1].y = b;
                }else{
                    
                    ay[k].x = a;
                    ay[k].y = b;
                    k++;
                    
                }
            }
            

        }


        x = abs(ax[0].y - ax[1].y);
        y = abs(ay[0].x - ax[1].x);

        cout << x*y << endl;
    }

    return 0;
}

