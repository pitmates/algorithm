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
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 200100;

vector<int > E[N];
int n;
int a[N];

void dfs(int u, int f) {
	for(auto& v : E[u])  if(v != f){
		a[v] = max(a[v], a[u]);
		dfs(v, u);
	}
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 1, 1+n) cin >> a[i];
	rep(i, 1, n) {
		int x,y ;
		cin >> x >> y;
		E[x].pb(y);
		E[y].pb(x);
	}
	dfs(1, 1);
	rep(i, 1, 1+n) cout << a[1] << " ";
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
/*
8
4 3 5 6 7 10 9 2
1 2
1 3
2 4
2 5
3 6
3 7
6 8

 */
