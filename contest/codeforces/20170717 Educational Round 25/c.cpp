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
const int N = 1010;

int dif[N];
int n, k;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	rep(i, 0, n) cin >> dif[i];
	sort(dif, dif+n);
	int t = 0;
	while(dif[0] > k+k) ++t, k += k;
	k = max(k, dif[0]);
	rep(i, 1, n) {
		// printf("i:%d  k:%d\n", i, k);
		while(dif[i] > k+k) ++t, k += k;
		k = max(k, dif[i]);
	}
	cout << t;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
