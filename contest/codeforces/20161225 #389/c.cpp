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
const int N = 200005;
int n;
int g[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> n;
	cin >> s;
	rep(i, 0, n) {
		if(s[i] == 'U') g[i] = 0;
		else if(s[i] == 'L') g[i] = 1;
		else if(s[i] == 'D') g[i] = 2;
		else g[i] = 3;
	}
	int t = 0, f = -1;
	rep(i, 1, n) if(g[i] != g[t]) 
		g[++t] = g[i];
	n = t+1; t = 1;
	int c = g[0];
	rep(i, 1, n) {
		if(g[i] == c) continue;
		if(!(c&1) && !(g[i]&1)) ++t, f = -1;
		else if((c&1) && (g[i]&1)) ++t, f = -1;
		else {
			if(f == -1) f = c;
			else {
				if(f == g[i]) f = c;
				else ++t, f = -1;
			};
		}
		c = g[i];
	}
	cout << t ;
	return 0;
}
