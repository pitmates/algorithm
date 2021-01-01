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
const int N = 260;

int n;
string s;

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	cin >> s;
	if(n % 4) {
		cout << "===" << endl;
		return 0;
	}
	int t = 0, a = 0, c = 0, g = 0, m = 0;
	rep(i, 0, n) {
		if(s[i] == 'A') ++a;
		else if(s[i] == 'G') ++g;
		else if(s[i] == 'C') ++c;
		else if(s[i] == 'T') ++t;
		else ++m;
	}
	int v = n / 4;
	if(a > v || c > v || g > v || t > v) {
		cout << "===" << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i) if(s[i] == '?'){
		if(a < v) s[i] = 'A', ++a;
		else if(c < v) s[i] = 'C', ++c;
		else if(g < v) s[i] = 'G', ++g;
		else s[i] = 'T', ++t;
	}
	cout << s << endl;

	return 0;
}
