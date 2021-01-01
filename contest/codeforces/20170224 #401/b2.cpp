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
const int N = 10;

int ds[N], dc[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	string s, c;
	cin >> n;
	cin >> s >> c;
	zero(ds); zero(dc);
	rep(i, 0, n) ds[s[i]-'0']++, dc[c[i]-'0']++;
	int x, y, mi = 0, ma = 0;
	for(x = y = 0; x < 10 && y < 10; ++x) {
		if(y < x) y = x;
		while(ds[x]) {
			--ds[x];
			if(dc[y]) --dc[y];
			else {
				while(y < 10 && !dc[y]) ++y;
				--dc[y];
			}
			if(y > 9) break;
		}
	}
	rep(i, 0, 10) mi += dc[i];
	zero(ds); zero(dc);
	rep(i, 0, n) ds[s[i]-'0']++, dc[c[i]-'0']++;
	for(x = 0, y = 1; x < 10 && y < 10; ++x) {
		if(y <= x) y = x + 1;
		while(ds[x]) {
			if(dc[y]) --dc[y];
			else {
				while(y < 10 && !dc[y]) ++y;
				--dc[y];
			}
			if(y > 9) break;
			--ds[x];
		}
	}
	rep(i, 0, 10) ma += ds[i];
	cout << mi << endl << n-ma << endl;
	return 0;
}
