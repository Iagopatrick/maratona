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

vector<ll> prefixKmp(string w)
{
    vector<ll> pi;
    ll j = 0;
    pi.push_back(j);
    for (ll i = 1; i < w.size(); i++)
    {
        if (w[i] == w[j])
        {
            pi.push_back(j);
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j];
            }
            pi.push_back(j);
        }
    }
    return pi;
}

int main()
{
    FASTIO;
    string w = "", n = "", s = "";
    while (getline(cin, w) && getline(cin, n) && getline(cin, s))
    {

        string lW = "", lS = "", resp = "";
        vector<ll> pi;
        FOR(i, 0, w.size())
        {
            lW += tolower(w[i]);
        }
        FOR(i, 0, s.size())
        {
            lS += tolower(s[i]);
        }

        pi = prefixKmp(lW);
        ll j = 0;
        string aux = "";
        bool flag = false;
        for (ll i = 0; i < s.size(); i++)
        {
            if (lS[i] == '<')
            {
                flag = true;
                aux = "";
                resp += s[i];
                continue;
            }
            else if (lS[i] == '>')
            {
                flag = false;
                if (aux != "")
                {
                    resp += aux;
                    aux = "";
                }
                resp += s[i];
                j = 0;
                continue;
            }
            if (flag)
            {
                if (lS[i] == lW[j])
                {
                    j++;

                    aux += s[i];
                    if (j == lW.size())
                    {
                        resp += n;
                        j = 0;
                        aux = "";
                        continue;
                    }
                    continue;
                }
                else
                {
                    if (j != 0)
                    {
                        j = pi[j];
                        resp += aux + s[i];
                        aux = "";
                        continue;
                    }
                    resp += s[i];
                    continue;
                }
            }

            resp += s[i];
        }
        cout << resp << endl;
    }

    return 0;
}
