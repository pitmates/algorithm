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

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	if(n % 4 == 0) puts("0");
	else {
		int md = n % 4;
		if(md == 3) cout << min(min(a, b+c), c+c+c) << endl;
		else if(md == 2) cout << min(min(a+a, b), c+c) << endl;
		else cout << min(min(a+a+a, c), a+b) << endl;
	}

	return 0;
}
