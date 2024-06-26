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

struct point
{
    ll x, y, pieces;
};

int main()
{
    FASTIO;
    ll n, m;
    cin >> n >> m;
    ll k, l;
    cin >> k >> l;
    k--;
    l--;
    vector<string> M;
    FOR(i, 0, n)
    {
        string temp;
        cin >> temp;
        M.PB(temp);
    }
    for(auto i: M){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    point max;
    max.pieces = 0;
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if (M[i][j] == '*')
            {
                continue;
            }
            ll p = 0;
            if (i + k < n)
            {
                if (j + l < m)
                {
                    if (M[i + k][j + l] == '*')
                        p++;
                }
                if (j - l >= 0)
                {
                    if (M[i + k][j - l] == '*')
                        p++;
                }
            }
            if (i - k >= 0)
            {
                if (j + l < m)
                {
                    if (M[i - k][j + l] == '*')
                        p++;
                }
                if (j - l >= 0)
                {
                    if (M[i - k][j - l] == '*')
                        p++;
                }
            }
            if (i - l >= 0)
            {
                if (j + k < m)
                {
                    if (M[i - l][j + k] == '*')
                        p++;
                }
                if (j - k >= 0)
                {
                    if (M[i - l][j - k] == '*')
                        p++;
                }
            }
            if (i + l < n)
            {
                if (j + k < m)
                {
                    if (M[i - l][j + k] == '*')
                        p++;
                }
                if (j - k >= 0)
                {
                    if (M[i - l][j - k] == '*')
                        p++;
                }
            }
            if(max.pieces < p){
                max.pieces = p;
                max.x = i;
                max.y = j;
            }
        }
    }
    cout << max.x << " " << max.y << endl;

    return 0;
}
