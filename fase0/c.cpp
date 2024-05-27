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

int main(){
    FASTIO;
    ll n, m, l, r;
    cin >> n >> m;
    vpll v;

    FOR(i, 0, m){
        cin >> l >> r;
        v.PB({l, IN});
        v.PB({r, OUT});
    }
    ll pieces = 1, first = 1;

    sort(v.begin(), v.end());

    for(auto i: v){
        cout << i.first << " - " << i.second << endl;
    }
    ll s = v.size(), cont = 0;
    FOR(j, 0, s){
        if(v[j].second){
            cont = j;
            pieces++;
        }else{
            cont = abs(cont-j);
        }     
        
    }
    

    cout << pieces + cont << endl;

    return 0;
}

