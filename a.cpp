#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int, int> ii;
typedef pair<ll,ll> pll; // a = arestas
typedef vector<pll> vpll;
const ll MAXN = 10009;
const ll INF = 10e9;
int N, M;
bool visited[MAXN];
vector<ii> adjList[MAXN];



int prim(){
    bool taken[MAXN];
    memset(&visited, MAXN, sizeof(bool));
    taken[0] = true;
    priority_queue<ii> pq;
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
    
    

    for(int i = 1; i <= n; i++){
        cin >> entrada[0] >> entrada[1] >> entrada[2]; 
        adjList[entrada[0]][entrada[1]];
        adjList[entrada[0]].push_back({entrada[1], entrada[2]});
    } 

    
   

    
    cout << cost << "\n";
    // cout << cont << "\n";


    return 0;
}