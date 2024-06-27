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

ll n;


void dfs(vector<vll> adj, ll v)
{
    
    vector<bool> used;
    stack<ll> st;
    st.push(v);

    while (!st.empty())
    {
        ll curr = st.top();
        st.pop();
        if (!used[curr])
        {
            used[curr] = true;
            for (int i = adj[curr].size() - 1; i >= 0; i--)
            {
                st.push(adj[curr][i]);
            }
        }
    }
}

int main()
{
    FASTIO;
    ll nodes = 5;

    adj[0].PB(1);
    adj[1].PB(0);
    adj[0].PB(2);
    adj[0].PB(3);
    adj[2].PB(0);
    adj[3].PB(0);
    adj[2].PB(4);
    adj[4].PB(2);
    adj[4].PB(3);
    adj[3].PB(4);

    return 0;
}
