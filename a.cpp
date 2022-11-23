#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ll, pair<ll,ll>> aresta; // a = arestas
const ll MAXN = 10009;
const ll INF = 10e9;
int N, M;
bool visited[MAXN];
vector<ii> adjList[MAXN];

struct arestas{
    ll cost;
    ii arestas;
};

int prim(priority_queue<ii> pq){
    bool taken[MAXN];
    memset(&visited, MAXN, sizeof(bool));
    taken[0] = true;
    // priority_queue<ii> pq;
    ii v, front;
    int u, w;
    ll cost = 0;
    for(int j= 0; j < (int)adjList[0].size(); j++){
        v = adjList[0][j];
        pq.push(ii(-v.second, -v.first));
    }
    while(!pq.empty()){
        front = pq.top();
        pq.pop();
        u = -front.second;
        w = -front.first;
        if(!taken[u]){
            cost+=(ll)w; taken[u] = true;
            for(int j = 0; j < (int)adjList[u].size(); j++){
                v = adjList[u][j];
                if(!taken[v.first]) pq.push(ii(-v.second, -v.first));
            }
        }
    }
    return cost;
}

int main(){
    ll c, n, entrada[3], cont = 0, cost;
    cin >> c >> n; // c = cidades & n = número de entradas
    vector <ll> g;
    vector <ll> stack;
    
    arestas *Cidade = (arestas *) malloc(sizeof(arestas));

    for(int i = 1; i <= n; i++){
        cin >> entrada[0] >> entrada[1] >> entrada[2]; 
        g.push_back({entrada[2], {entrada[0], entrada[1]}});
    } 

    sort(g.begin(), g.end());
    for(int i = 0; i < c - 1; i++){
        stack.push_back(i);
    }

    for(int i = 0; i < c - 1; i++){
        
        cont += g[i].first;
    }

    cost = prim(g.second);
    cout << cost << "\n";
    // cout << cont << "\n";


    return 0;
}