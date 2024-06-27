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

vll memo;
vector<bool> found;

void divisores(ll n)
{   
    for (ll a = 2; a <= n; a *= 2)
    {
        if (n % a == 0)
        {

            
            memo[n] += memo[a];
        }
    }
    found[n] = true;
}

int main()
{
    FASTIO;
    found.assign(1000000001, false);
    memo.assign(1000000001, 0);
    found[0] = found[1] = found[3] = true;
    found[2] = true;
    memo[2] = 1;
    ll t;
    cin >> t;
    FOR(i, 0, t)
    {
        vll v1, v2;
        ll n;
        cin >> n;
        FOR(j, 0, n)
        {
            ll temp;
            cin >> temp;

            v1.PB(temp);
            v2.PB(temp * (j + 1));
        }
        ll s = v1.size();
        ll cont = 0;
        ll goal = n;
        FOR(k, 0, s)
        {
            if (goal <= 0)
            {
                break;
            }
            if (!found[v1[k]])
            {
                divisores(v1[k]);
            }
            if (!found[v2[k]])
            {
                divisores(v2[k]);
            }
            if (memo[v1[k]] == memo[v2[k]] || goal - memo[v1[k]] <= 0 || memo[v1[k]] > memo[v2[k]] || v2[k] % 2 != 0)
            { // São iguais, não vamos querer fazer nenhuma operação, vamos escolher v1
                goal -= memo[v1[k]];
            }
            else
            {
                goal -= memo[v2[k]];
                cont++;
            }
        }
        cout << "Olha ele " << memo[100001] << endl;
        cout << (goal <= 0? cont : -1) << endl;
    }
    return 0;
}
