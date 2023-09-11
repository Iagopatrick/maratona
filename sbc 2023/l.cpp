// Comparação de substring
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

int main(){
    FASTIO;
    string p;
    char c;
    ll n;

    cin >> p >> n;
    for(ll i = 0; i < p.size(); i += n){
        c = p[i];
        p[i] = p[n -i];
        p[n-i] = c;
        cout << p[i] << endl;
    }
    cout << p << endl;

    return 0;
}

