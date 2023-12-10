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
    vector<vector<ll>> d(301, vector<ll>(301, 100001)), s;

    ll n, m, u, v, l;
    cin >> n >> m;
    // ll d[n][m], s[n][m];
    vector<pair<ll, ll>> r;
    FOR(i, 0, m){
        cin >> u >> v >> l;
        d[u-1][v-1] = l;
        d[v-1][u-1] = l;
        s[u-1][v-1] = 1000001;
        s[v-1][u-1] = 1000001;
        r.push_back(MP(u-1, v-1));
    }
    //floyd
    FOR(i, 0, m){
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {

                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                }
            }
        }
    }
    FOR(i, 0, m){
        cout << "i e j: " << r[i].first << " " << r[i].second << " ";
        cout << d[r[i].first][r[i].second] << endl;
    }
    return 0;
}

