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

int n;
int g[N<<2];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	int d = 0, r = 0, dd = 0, rr = 0;
	cin >> n;
	cin >> s;
	rep(i, 0, n) {
		g[i] = (s[i] == 'R');
		if(g[i]) ++rr;
		else ++dd;
	}
	for(int i = 0; i < n && dd && rr; ++i) {
		if(g[i]) {
			if(d > 0) --d, --rr;
			else g[n++] = 1, ++r;
		}
		else{
			if(r > 0) --r, --dd;
			else g[n++] = 0, ++d;
		}
	}
	cout << (dd ? 'D' : 'R') << endl;
	return 0;
}
