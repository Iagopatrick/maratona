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

void bfs(vector<vll> adj, ll n, vll strengh, ll start)
{
    vector<bool> used(n, false), safe(n, false);
    vll lifo, p(n), d(n);
    lifo.PB(start);
    used[start] = true;
    safe[start] = true;
    p[start] = -1;
    ll restStrengh = 0;
    while (!lifo.empty())
    {
        ll v = lifo.back(), s;
        lifo.pop_back();
        s = strengh[v];
        restStrengh += s > -1? s:0;
        safe[v] = s > -1 || restStrengh > 0;
        for (ll i : adj[v])
        {
            if (!used[i])
            {
                used[i] = true;
                if (restStrengh > 0 || s >= 0)
                {
                    safe[i] = true;
                    
                }
                lifo.push_back(i);
                d[i] = d[v] + 1;
                p[i] = v;
            }
            else
            {
                // falta ajeitar a lógica de uma cidade ter somente um soldado protegendo.
                if (!safe[i])
                {
                    if (restStrengh > 0 || s > 0)
                    {
                        safe[i] = true;
                    }
                }else if(restStrengh >= 1 || s > 0){
                    safe[i] = false;
                }
            }
        }
        restStrengh -= restStrengh > 0? 1 : 0;
    }
    for (auto i : safe)
    {
        if (!i)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    FASTIO;
    ll t;
    cin >> t;
    FOR(i, 0, t)
    {
        ll nodes, roads, soldiers, maxNode = 0, maxStrengh = 0;
        cin >> nodes >> roads >> soldiers;
        vector<vll> adj(nodes);
        vll strengh(nodes, -1);
        FOR(j, 0, roads)
        {
            ll a, b;
            cin >> a >> b;
            adj[a - 1].PB(b - 1);
            adj[b - 1].PB(a - 1);
        }
        FOR(u, 0, soldiers)
        {
            ll k, s;
            cin >> k >> s;
            strengh[k - 1] = s;
            if (s >= maxStrengh)
            {
                maxNode = k - 1;
                maxStrengh = s;
            }
        }

        bfs(adj, nodes, strengh, maxNode);
    }
    return 0;
}
