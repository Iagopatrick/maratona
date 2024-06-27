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

ll leftLogic(vll num, ll n, ll l, ll r){
    ll sum = 0, round_win = 0;
    FOR(j, 0, n/2){
        sum = num[j];
        

        if(sum >= l && sum <= r){
            round_win++;
            continue;
        }else if(sum > r){
            continue;
        }else{
            ll aux = j;
            while(true){
                aux ++;
                if(aux >= n){
                    break;
                }
                sum += num[aux];
                if(sum >= l && sum <= r){
                    round_win++;
                    j += aux - j;
                    break;
                }else if(sum > r){
                    break;
                }else{
                    continue;
                }
            }
        }
    }
    return round_win;
}

ll rightLogic(vll num, ll n, ll l, ll r){
    ll rsum = 0, round_win = 0;
    for(ll j = n - 1; j >= n/2; j--){
        rsum = num[j];
        

        if(rsum >= l && rsum <= r){
            round_win++;
            continue;
        }else if(rsum > r){
            continue;
        }else{
            ll aux = j;
            while(true){
                aux --;
                if(aux < n/2){
                    break;
                }
                rsum += num[aux];
                if(rsum >= l && rsum <= r){
                    round_win++;
                    j -= j - aux;
                    break;
                }else if(rsum > r){
                    break;
                }else{
                    continue;
                }
            }
        }
    }
    return round_win;
}

int main(){
    FASTIO;
    ll t;
    cin >> t;
    FOR(i, 0, t){
        ll n, l, r;
        cin >> n >> l >> r;
        vll num;
        FOR(j, 0, n){
            ll temp;
            cin >> temp;
            num.PB(temp);
        }
        ll round_win = 0;
        round_win = rightLogic(num, n, l, r) + leftLogic(num, n, l, r);
        cout << round_win << endl;
    }

    return 0;
}

