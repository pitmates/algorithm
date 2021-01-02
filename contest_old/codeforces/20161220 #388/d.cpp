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
const int N = 200200;

int p[N];
vector<int > v[N];
bool g[N];
int idx[N];
int n, q, k;
vector<int > vk;

bool cmp(int x, int y) {
	return p[x] > p[y];
}

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) g[i] = 0, v[i].clear();
	vk.clear();
	int id, bid;
	rep(i, 1, n+1) {
		cin >> id >> bid;
		//p[i] = {bid, id};
		v[id].pb(bid);
		idx[i] = p[id] = i;
	}
	sort(idx+1, idx+n+1, cmp);
	cin >> q;
	rep(w, 0, q) {
		cin >> k;
		int x;
		rep(i, 0, k) {
			cin >> x;
			g[x] = 1;
			vk.pb(x);
		}
		int z[2]; x = 0;
		rep(i, 1, n+1) if(g[idx[i]] == 0) {
			if(v[idx[i]].empty()) break;
			z[x++] = idx[i];
			if(x == 2) break;
		}
		int f = z[0], s = z[1];
		if(x == 0) cout << 0 << " " << 0 << endl;
		else if(x == 1) cout << f << " " << v[f][0] << endl;
		else cout << f << " " << *lower_bound(v[f].begin(), v[f].end(), v[s].back()) << endl;
		rep(i, 0, sz(vk)) g[vk[i]] = 0;
		vk.clear();
	}
	return 0;
}
