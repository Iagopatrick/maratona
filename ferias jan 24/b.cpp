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

// b = 0 and a = 1 then i do 1 moviment
// b = 1 and a = 1 so i dont do anything
// b = 0 and a = 0 so i dont do anything
// b = 1 and a = 0 then i have 1 credit
// if i have 1 credit and my moviments is over, i plus the credits to the moviments
int main(){
    FASTIO;
    ll numberTests, nBoxes, moviments, credits;
    string b, a;
    cin >> numberTests;
    FOR(i, 0, numberTests){
        cin >> nBoxes;
        cin >> b >> a;
        credits = 0;
        moviments = 0;
        FOR(j, 0, nBoxes){
            if(b[j] == a[j]){
                continue;
            }else if(b[j] == '0' && a[j] == '1'){
                moviments++;
            }else{
                credits++;
            }
        }
        if(moviments - credits < 0){
            moviments += abs(moviments - credits);
        }
        
        cout << moviments << endl;
    }

    return 0;
}

