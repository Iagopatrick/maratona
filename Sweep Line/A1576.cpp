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

#define IN 1
#define OUT 0

struct event{
    ll p;
    ll i;
    ll ty;
    ll id;
    bool operator<(const event &e) const {
        if (i != e.i) {
            return i < e.i;
        }else if (p != e.p) {
            return p > e.p;
        }
        else{
            return id < e.id;
        }
    }
};

struct Compare{

    bool operator()(event a, event b) const{
        if(a.p > b.p){
            return true;
        }else if(a.p == b.p){
            if(a.i < b.i){
                return true;
            }else{
                if(a.id > b.id){
                    return true;
                }else{
                    return false;

                }
            }
        }else{
            return false;
        }
    }
};

int main(){
    FASTIO;
    ll l, h, r, count = 1;
    vector<event> v;
    
    vector<ll> aux(100001, 0);
    while(cin >> l >> h >> r){
        
    
        v.PB({h , l, IN, count});
        v.PB({h, r, OUT, count}); 
        aux[count] = l;
        count ++;
    }
    
    sort(v.begin(), v.end());

    ll s, currentValue = 0, currentId = 0;
    vector<ll> resp;
    
    ll meuId = v[0].id;
    // currentValue = v.begin()->p;
    // currentId = v.begin()->id;
    // resp.PB(v.begin()->i);
    // resp.PB(v.begin()->p);

    set<event, Compare> x;
    
    
    // x.insert(v[0]);
    
    
    for(auto i: v){
        
        if(i.ty){
            x.insert(i);
            if(currentValue < x.begin()->p && currentId != x.begin()->id){
                resp.PB(i.i);
                resp.PB(x.begin()->p);
                currentValue = i.p;
                currentId = i.id;
            }
        }else{
            
            x.erase({i.p, aux[i.id], IN, i.id});
            
            if(x.empty()){
                resp.PB(i.i);
                resp.PB(0);
                cout << "oi";
                currentId = i.id;
                currentValue = 0;
                continue;
            }
                
            if(currentValue < x.begin()->p){
                resp.PB(i.i);
                resp.PB(x.begin()->p);
                currentValue = i.p;
                
            }
        }
        
    }

    for(auto i: resp){
        cout << i << " ";
    }
    cout << endl;
    

    

    return 0;
}

