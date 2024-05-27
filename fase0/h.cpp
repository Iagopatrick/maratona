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
bool isPrimeFast(long long n) { // 

    if (n < 5 || n % 2 == 0 || n % 3 == 0)
        return (n == 2 || n == 3);
    long long maxP = sqrt(n) + 2;
    for (long long p = 5; p < maxP; p += 6) {
        if (p < n && n % p == 0) return false;
        if (p+2 < n && n % (p+2) == 0) return false;
    }
    return true;
}
int main(){
    FASTIO;
    ll t;
    cin >> t;
    FOR(i, 0, t){
        ll temp, x, y;
        cin >> temp;
        y = (temp + 1)/2;
        x = y - 1;
        while(isPrimeFast(x) || isPrimeFast(y)){
            x --;
            y ++;
            if(x == 0 or y > 1000000000){                
                break;
            }
            
        }
        if(x == 0 or y > 1000000000){
            cout << -1 << endl;
            continue;
        }
        cout << x << " " << y << endl;
    }

    return 0;
}

