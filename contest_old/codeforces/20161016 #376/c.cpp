#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define loop(i, st, ed, step) for(int i = (int) st; i != (int) ed; i += (int) step)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 200020;

int n, m, k;
int co[N];
vector<int > e[N];
bool vis[N];
vector<int > color;
int v[N];

void dfs(int x) {
    color.push_back(co[x]);
    v[co[x]]++;

    vis[x] = 1;
    for(auto i: e[x]) if(!vis[i])
            dfs(i);
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    rep(i, 1, n+1) cin >> co[i];
    rep(j, 0, m) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b); e[b].push_back(a);
    }
    zero(vis);
    int ans = 0;
    rep(i, 1, n+1) {
        if(!vis[i]) {
            dfs(i);
            int mv = 0;
            for(auto x: color) mv = max(mv, v[x]);
            for(auto x: color) v[x] = 0;
            ans += SZ(color) - mv;
            color.clear();
        }
    }
    cout << ans << endl;
    return 0;
}

