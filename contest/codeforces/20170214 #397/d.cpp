#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 1e5+7;

int f[N], h[N], g[N];
int n;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    int m = 0;
    zero(g);
    rep(i, 1, n+1) {
        cin >> f[i];
        if(i == f[i]) g[i] = ++m, h[m] = i;
    }
    rep(i, 1, 1+n) if(!g[i] && !g[f[i]]){
        cout << -1; return 0;
    }
    rep(i, 1, 1+n) if(!g[i]) g[i] = g[f[i]];
    cout << m << endl;
    rep(i, 1, n+1) cout << g[i] << " "; cout << endl;
    rep(i, 1, 1+m) cout << h[i] << " "; cout << endl;

    return 0;
}
