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
const int N = 200020;

vector<int > E[N];
vector<int > G[N];
int out[N], id[N];
int n;

inline bool cmp(int x, int y) {
    return out[x] < out[y];
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep(i, 0, n+1) E[i].clear(), G[i].clear();
    zero(out);
    rep(i, 1, 1+n) {
        int x, y;
        cin >> x >> y;
        E[x].pb(y);
        E[y].pb(x);
        ++out[x];
        ++out[y];
        id[i] = i;
    }
    sort(id+1, id+n+1, cmp);
    for(int p = 1; p <= n; ++p) {
        if(out[id[p]] > 1) break;
        int f = id[p], fa = 0, len = 1;
        while(1) {
            if(out[f] > 2) break;
            if(out[f] == 1 && fa) {
                cout << n-1 ;
                return 0;
            }
            for(auto& u : E[f]) if(u != fa) {
                f = u;
                fa = f;
            }
            ++len;
        }
        G[f].pb(len);
    }
    return 0;
}
