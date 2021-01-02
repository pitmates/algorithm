#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
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
const int N = 1023;

int n, m, W;
pii wb[N];
vector<int > st[N];
int fa[N];
int d[N];

int findset(int x) {
    if(x == fa[x]) return x;
    return x = findset(fa[x]);
}

void unionset(int x, int y) {
    x = findset(x); y = findset(y);
    if(x != y) fa[x] = y;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> W;
    int w, b, x, y;
    rep(i, 1, n) cin >> w, wb[i].fi = w;
    rep(i, 1, n) cin >> b, wb[i].se = b;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        cin >> x >> y;
        unionset(x, y);
    }
    rep(i, 1, n) st[findset(i)].pb(i);
    w = b = x = y = 0;
    zero(d);
    rep(i, 1, n) {
        if(fa[i] != i) continue; // only the root used to calculate
        for(int j = W; j >= 0; --j) {
            x = y = 0;
            // only one person takes part in
            for(int k = 0; k < sz(st[i]); ++k) {
                w = wb[st[i][k]].fi, b = wb[st[i][k]].se;
                x += w, y += b;
                if(j >= w) d[j] = max(d[j], d[j-w]+b);
            }
            // all union take part in
            if(j >= x) d[j] = max(d[j], d[j-x]+y);
        }
    }
    int mx = 0;
    rep(i, 0, W) if(d[i] > mx) mx = d[i];
    cout << mx;
    return 0;
}
