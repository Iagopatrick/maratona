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
bool order(vector<ll> x, vector<ll> y) {
    return (x[0] < y[0]);
}
int main(){
    FASTIO;
    ll l, h, r;
    vector<vector<ll>> v;
    
    while(cin >> l >> h >> r){
        
        v.PB(vector<ll> {l , h, IN});
        v.PB(vector<ll>{r, h, OUT});
    }
    
    sort(v.begin(), v.end(), order);
    ll s, nextY, currentValue;
    vector<ll> resp;
    s = v.size();
    resp.PB(v[0][0]);
    resp.PB(v[0][1]);
    
    nextY = 0;
    currentValue = nextY;
    FOR(i, 0, s){
        if(v[i][2]){
            if(v[i][1] > currentValue){
                
                nextY += v[i][1];
                currentValue = v[i][1];
                resp.PB(v[i][0]);
                resp.PB(v[i][1]);
            }else{
                nextY += v[i][1]; 
            }
        }else{
            if(currentValue - v[i][1] == 0){
                resp.PB(v[i][0]);
                nextY -= currentValue;
                resp.PB(nextY);
                currentValue = 
            }else{
                nextY -= v[i][1];
            }
        }
    }
    ll x = resp.size();
    FOR(i, 0, resp.size()){
        cout << resp[i] << (i == x-1? "" : " ");
    }
    cout << endl;

    return 0;
}

