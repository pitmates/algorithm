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

vector<int > E[N];
int n;
int c[N];

int xv;
void dfs(int x, int co, int f) {
    if(c[x] != co) { xv = x; return ; }
	for(auto& u : E[x]) if(u != f) {
		dfs(u, co, x);
	}
}

bool deal(int x) {
    for(auto & y : E[x]) {
    	xv = -1;
    	dfs(y, c[y], x);
    	if(xv != -1)	return 0;
    }
    return 1;
}

bool vis[N];
int findv() {
	queue<int > q;
	while(!q.empty()) q.pop();
	zero(vis);
	q.push(1); vis[1] = 1;
	while(!q.empty()) {
		int z = q.front(); q.pop();
		for(auto & u : E[z]) if(!vis[u]){
			q.push(u); vis[u] = 1;
			if(c[u] != c[z]) {
				if(deal(z)) return z;
				if(deal(u))	return u;
				return -1;
			}

		}
	}
	return 1;
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    rep(i, 1, n) {
    	int u, v;
    	cin >> u >> v;
    	E[u].pb(v);
    	E[v].pb(u);
    }
    int cn = 1;
    rep(i, 1, 1+n) cin >> c[i];
    int z = findv();
    if(z == -1) cout << "NO" << endl;
    else cout << "YES" << endl << z << endl;
    return 0;
}
