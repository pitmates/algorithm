#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 100100;

int reg[2][N];
ll m;
int n;

int main()
{
#ifdef PIT
freopen("d.in", "r", stdin);
freopen("d.out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int f = 0;
    rep(i, 0, n) cin >> reg[f][i];
    --m;
    while(m) {
        ll x; int i;
        for(int i = 62; i >= 0; --i) if( m >= (x = (1LL<<i))) break;
        m -= x;
        rep(j, 0, n) reg[f^1][j] = reg[f][j] ^ reg[f][(j+x)%n];
        f ^= 1;
    }
    rep(i, 0, n) cout << reg[f][i] << " ";

    return 0;
}
