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
#define FOR(i, a, b) for (ll i = (a); i < ll(b); ++i)
#define INT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a) / __gcd(a, b)) * b)
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define FASTIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);


ll mexFunction(vll s){
    //return the minimun non-negative number that is out of sequence s
    ll min = 0, siz = s.size();
    sort(s.begin(), s.end());
    FOR(i, 0, siz){
        if(s[i] == min){
            min++;
        }else if(s[i] < min){
            min = s[i];
        }
    }
    return min;
} 


int main()
{
    FASTIO;
    ll t, n;
    cin >> t;
    FOR(i, 0, t)
    {
        vll a;
        cin >> n;
        FOR(j, 0, n){
            ll x;
            cin >> x;
            a.PB(x);
            
        }
        vll p;
        ll f, sizeOfA = a.size(), j = 0, numberP = 0, c = 0, mex = 1;
        p.PB(0);
        while(sizeOfA > 1){
            //percorrendo a logica das permutações
            
            f = mex - p.back();
                
            if(a[j] == f){
                j++;
                sizeOfA--;
                
                numberP = mex;
                mex++;
                p.PB(numberP);
            }else{
                mex = numberP;
                p.pop_back();
                numberP++;
                p.PB(numberP);
            }
            
            
        }
        
        FOR(k, 0, p.size()){
            cout<< p[k] << " ";
        }
        cout << endl;
    }
    return 0;
}
