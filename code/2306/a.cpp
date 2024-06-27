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
        ll num, a, b, c, r1, r2, r3;
        vll numbers;
        FOR(j, 0, 3){
            cin >> num;
            numbers.PB(num);
        }
        a = numbers[0];
        b = numbers[1];
        c = numbers[2];

        r1 = abs(a-b) + abs(a-a) + abs(a-c);
        r2 = abs(b-b) + abs(b-a) + abs(b-c);
        r3 = abs(c-b) + abs(c-a) + abs(c-c);
        cout << min(r1, min(r2, r3)) << endl;
    }

    return 0;
}

