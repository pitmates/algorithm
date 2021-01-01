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
#define piii pair<int, pii >

using namespace std;
const int N = 200100;

int n;
vector<int > E[N];
int color[N];


int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x, y;
	rep(i, 1, n+1) E[i].clear();
	rep(i, 1, n) {
		cin >> x >> y;
		E[x].pb(y); E[y].pb(x);
	}

	zero(color);
	color[1] = 1;
	queue<piii > q; while(!q.empty()) q.pop();
	q.push({1, {1, 0}});
	while(!q.empty()) {
		piii z = q.front(); q.pop();
		int k = 1, f = z.se.fi, s = z.se.se, y = z.fi;
		for(auto & x : E[y]) if(!color[x]) {
			if(k == f) ++k;
			if(k == s) ++k;
			if(k == f) ++k;
			q.push({x, {k, f}});
			color[x] = k++;
		}
	}
	cout << *max_element(color+1, color+1+n) << endl;
	rep(i, 1, 1+n) cout << color[i] << " ";
	return 0;
}
