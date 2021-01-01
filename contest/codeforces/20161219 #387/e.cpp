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
const int N = 1000100;
string s;
vector<string > v[N>>1];
int level[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s; s = s + ",";
	zero(level);
	int n = sz(s), f = 1, e = 1, m = -1;
	string tp = "";
	level[0] = 1;
	for(int i = 0; i < n; ++i) {
		if(s[i] == ',') {
			if(f&1) {
				while(level[e] == 0 && e) --e;
				v[e].pb(tp); 
				if(!e && !level[e]) level[0] = 1;
				level[e]--;
			}
			else {
				int x = 0;
				for(int j = 0; j < sz(tp); ++j) x = x * 10 + tp[j] - '0';
				level[++e] = x, m = max(e, m);
			}
			f ^= 1;
			tp = "";
		}
		else tp += s[i];
	}

	cout << m << endl;
	rep(i, 0, m) {
		rep(j, 0, sz(v[i])) cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}