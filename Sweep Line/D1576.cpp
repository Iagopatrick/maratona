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

#define IN 1
#define OUT 0
typedef struct building
{
    ll x, height;
    ll way;
} Building;
// 

bool compare(Building a, Building b)
{
    
    if (a.x == b.x)
    {
        if(a.way > b.way){
            return true;
        }
        return a.height > b.height;
    }
    return a.x < b.x;
}

struct Compare
{
    bool operator()(ll a, ll b) const
    {
        return a > b;
    }
};

int main()
{
    FASTIO;
    ll l, h, r;

    vector<Building> events;
    vector<ll> res;
    set<ll, Compare> heightBuildings;
    map<ll, ll> numberOfcurrentHeights;
    vector<ll> numberOfOut(10001, 0);
    Building currentBuilding;
    ll currentH = 0;
    while (cin >> l >> h >> r)
    {
        Building temp;
        temp.height = h;
        temp.x = l;
        temp.way = IN;
        events.push_back(temp);
        numberOfcurrentHeights[temp.height] = 0;
        numberOfOut[r]++;
        temp.way = OUT;
        temp.x = r;
        events.push_back(temp);
    }
    sort(events.begin(), events.end(), compare);

    ll s = events.size();

    currentBuilding = events[0];
    currentH = currentBuilding.height;
    res.push_back(currentBuilding.x);
    res.push_back(currentBuilding.height);

    // Print of the vector of events after the sort
    // for (auto i : events)
    // {
    //     cout << "( O x é: " << i.x << " altura: " << i.height << (i.way?" Entrada":" Saida") << ") " << endl;
    // }
    for (ll i = 1; i < s; i++)
    {

        if (events[i].way == IN)
        {
            
            heightBuildings.insert(events[i].height);
            numberOfcurrentHeights[events[i].height]+= 1;
            if (events[i].height > currentBuilding.height)
            {
                res.push_back(events[i].x);
                res.push_back(events[i].height);
                currentBuilding = events[i];
            }
        }
        else
        {
            numberOfcurrentHeights[events[i].height] -= 1;
            numberOfOut[events[i].x]--;
            if (numberOfcurrentHeights[events[i].height] == 0)
            {
                heightBuildings.erase(events[i].height);
            }

            if (*heightBuildings.begin() < currentBuilding.height && numberOfOut[events[i].x] == 0)
            {
                res.push_back(events[i].x);
                res.push_back(*heightBuildings.begin());
                currentBuilding.height = *heightBuildings.begin();
            }
        }
    }
    ll rs = res.size();
    FOR(i, 0, rs)
    {
        cout << res[i] << (i + 1 == rs ? "" : " ");
    }
    cout << endl;
    return 0;
}
