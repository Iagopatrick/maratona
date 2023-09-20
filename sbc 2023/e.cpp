#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<< #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(ll i = (a); i< ll(b); ++i)

ll soma(ll n){
    ll a = 0;
    while(n > 0){
        a += n%10;
        n /= 10;
        
    }
    return a;
}

int main(){
    FASTIO;
    ll n, k, tmp, f, j, l = 0;
    ll flowers[1000001];
    memset(flowers, 0, sizeof(flowers));
    j = -1;

    cin >> n >> k;
    FOR(i, 0, n){
        cin >> tmp;
        flowers[tmp] += 1;
        
        if(tmp > j){
            j = tmp;
           
        }
    }
    while(k > 0 && j >= 0){
        f = 0;
        if(flowers[j] != 0){
            k -= flowers[j];
            tmp = soma(j);
            flowers[j - tmp] += flowers[j];
            f = soma(j);
        }
        j--;
        
    }
    cout << f << endl;
    



    return 0;
}