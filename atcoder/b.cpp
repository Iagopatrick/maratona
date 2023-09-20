



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


int dp[1001][1001];
bool isPalindrome(string &s, ll i, ll j) {
    if (i > j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] != s[j])
        return dp[i][j] = 0;
    return dp[i][j] = isPalindrome(s, i + 1, j - 1);
}

ll lenMax(string &s, ll l, ll r){
    if(l == r){
        
        return dp[l][r] = 1;
    }
    else if(l + 1 == r){
        return s[l] == s[r]? dp[l+1][r] = 2:dp[l+1][r] = 1;
    }
    if(s[l] == s[r]){
        
        return 2 + lenMax(s, l+1, r-1);
    }else{
        
        return max(lenMax(s, l, r-1), lenMax(s, l+1, r));
    }



}



int main(){
    FASTIO;
    string s;
    ll lenOfMaxPalindrome;
    memset(dp, 0, sizeof(dp));
    cin >> s;
    lenOfMaxPalindrome = lenMax(s, 0, s.size());
    cout << lenOfMaxPalindrome << endl;

}


