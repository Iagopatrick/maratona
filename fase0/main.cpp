#include "bits/stdc++.h"
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

struct
{
    ll x, y, pieces;
    bool isSet;
} point;

vector<string> mapa;

int main()
{
    FASTIO;

    ll y, x, bLesser, bGreater;
    cin >> y >> x >> bLesser >> bGreater;

    bLesser--;
    bGreater--;

    if (bLesser > bGreater)
    {
        ll nTMP = bLesser;
        bLesser = bGreater;
        bGreater = nTMP;
    }

    string tmp;

    for (ll i = 0; i < y; i++)
    {
        cin >> tmp;

        mapa.emplace_back(tmp);
    }

    point.x = 0;
    point.y = 0;
    point.pieces = 0;
    point.isSet = false;

    for (ll i = 0; i < y; i++)
    {
        for (ll j = 0; j < x; j++)
        {
            ll piecesAtual = 0;

            if (mapa[i][j] == '*')
            {
                continue;
            }

            // cima e direta
            if (i - bGreater >= 0 &&
                j + bLesser < x &&
                mapa[i - bGreater][j + bLesser] == '*')
            {
                piecesAtual++;
            }

            // baixo
            if (i + bGreater < y &&
                j + bLesser < x &&
                mapa[i + bGreater][j + bLesser] == '*')
            {

                piecesAtual++;
            }

            // esquerda
            if (j - bGreater >= 0 &&
                i + bLesser < y &&
                mapa[i + bLesser][j - bGreater] == '*')
            {

                piecesAtual++;
            }

            // direita
            if (j + bGreater < x &&
                i + bLesser < y &&
                mapa[i + bLesser][j + bGreater] == '*')
            {

                piecesAtual++;
            }

            if (bLesser > 0 && bLesser != bGreater)
            {
                // cima e esquerda
                if (i - bGreater >= 0 &&
                    j - bLesser >= 0 &&
                    mapa[i - bGreater][j - bLesser] == '*')
                {

                    piecesAtual++;
                }

                // baixo e esquerda
                if (i + bGreater < y &&
                    j - bLesser >= 0 &&
                    mapa[i + bGreater][j - bLesser] == '*')
                {

                    piecesAtual++;
                }

                // esquerda e cima
                if (j - bGreater >= 0 &&
                    i - bLesser >= 0 &&
                    mapa[i - bLesser][j - bGreater] == '*')
                {

                    piecesAtual++;
                }

                // direita e cima
                if (j + bGreater < x &&
                    i - bLesser >= 0 &&
                    mapa[i - bLesser][j + bGreater] == '*')
                {

                    piecesAtual++;
                }
            }

            if (point.pieces < piecesAtual || !point.isSet)
            {
                point.pieces = piecesAtual;
                point.y = i + 1;
                point.x = j + 1;
                point.isSet = true;
            }
        }
    }

    cout << point.x << " " << point.y << endl;

    return 0;
}
