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

void bfs(vector<vll> adj, ll nodes, ll start){
    vector<bool> used(nodes, false);
    vll queue;
    vector<ll> distance(nodes), parents(nodes);

    queue.PB(start);
    used[start] = true;
    while(!queue.empty()){
        ll v = queue.back();
        queue.pop_back();
        cout << "Parent: " << v << endl;
        for(ll i: adj[v]){
            if(!used[i]){
                used[i] = true;
                queue.PB(i);
                distance[i] = distance[v] + 1;
                parents[i] = v;
                cout << i << " ";
            }
        }
        cout << endl;
    }

}


int main(){
    FASTIO;
    ll nodes = 5;
    vector<vll> adj(nodes);
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
    bfs(adj, nodes, 0);
    return 0;
}

