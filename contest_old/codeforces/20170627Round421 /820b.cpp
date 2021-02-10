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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, i;
	cin >> n >> a;
	if(n == 3) {
		cout << 1 << " " << 2 << " " << 3 << endl;
		return 0;
	}
	double ang = 180.0 * (n-2) / n;
	for( i = 0; i < n-3; ++i) {
		double an = ang - 180.0 / n;
		if(abs(ang-a) < abs(an-a)) break;
		ang = an;
	}
	cout << n-i << " 1 2" << endl;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
