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
const int N = 400100;

struct Edge
{
	int u, v, next, to;
	bool bridge;
}E[N<<1];

int n, m, idx;
int head[N];

int dfn[N], low[N], tot;


void init(){
	zerox(head, -1);
	idx = tot = 0;
	zero(dfn);
	zero(low);
}

void addedge(int u, int v){
	E[idx].u = u;
	E[idx].v = v;
	E[idx].head = head[u];
	E[idx].bridge = 0;
	E[idx].to = 0;
	head[u] = idx++;
}

void dfs(int u, int fa) {
	dfn[u] = low[u] = ++tot;

	for(int i = head[u]; i != -1; i = E[i].next){
		int v = E[i].v;
		if(v == fa) continue;
		if(!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);

			if(low[v] > dfn[u]) {
				E[i].bridge = E[i^1].bridge = 1;
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);



	return 0;
}


