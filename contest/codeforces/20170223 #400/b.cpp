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
const int N = 100010;

int n, x;
int g[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 0, 2+n) g[i] = 1; x = 0;
	rep(i, 2, 2+n) if(g[i]&1) {
		for(int j = i+i; j < 2+n; j += i) g[j] = 2;
	}
	rep(i, 2, 2+n) if(x < g[i]) x = g[i];
	cout << x << endl;
	rep(i, 2, 2+n) cout << g[i] << " ";
	return 0;
}
