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

ll nodes;
vll tin, low;
ll timer;
vector<bool> used, articulation_point;
vector<vll> adj;


void dfs(ll v, ll p = -1)
{

    used[v] = true;
    tin[v] = low[v] = timer++;
    ll children = 0; //só usa se for precisar de pontos articulados
    for (auto i : adj[v])
    {
        if (i == p)
            continue; // é uma aresta de volta, back edge
        if (used[i])
        {
            low[v] = min(low[v], tin[i]);
        }
        else
        {
            dfs(i, v);
            low[v] = min(low[v], low[i]);
            if(low[i] >= tin[v] && p != -1){
                articulation_point[v] = true; // P A
            } 
            children++;
            if (low[i] > tin[v]) // P
            {

                cout << i <<  " é uma ponte! " << v << endl;
            }
        }
    }
    if(p == -1 && children > 1){
        articulation_point[v] = true;
    }
}

void find_brigdes()
{
    timer = 0;
    used.assign(nodes, false);
    tin.assign(nodes, -1);
    low.assign(nodes, -1);
    articulation_point.assign(nodes, false);
    for(ll i = 0; i < nodes; i++){
        if(!used[i]){
            dfs(i);
        }
    }
}

int main()
{
    FASTIO;
    nodes = 6;
    adj.assign(nodes, vll());
    adj[0].PB(1);
    adj[0].PB(2);
    adj[1].PB(0);
    adj[1].PB(2);
    adj[1].PB(3);
    adj[2].PB(0);
    adj[2].PB(1);
    adj[2].PB(3);
    adj[3].PB(1);
    adj[3].PB(2);
    adj[3].PB(4);
    adj[3].PB(5);
    adj[4].PB(3);
    adj[5].PB(3);

    find_brigdes();

    FOR(i, 0, nodes){
        if(articulation_point[i]){
            cout << i << " É um ponto de articulação! Caso seja removido, o número de componentes conectados aumenta!" << endl;
        }
    }
    return 0;
}
