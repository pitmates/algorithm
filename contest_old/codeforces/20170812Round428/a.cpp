#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int)( j); i < (int) (k); ++i)
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
const int N = 103;

int a[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	rep(i, 0, n) cin >> a[i];
	int s = 0, l = 0, t = 0;
	rep(i, 0, n) {
		int x =  min(l+a[i], 8);
		s += x;
		if(s >= k) {t = i; break; }
		l = max(0, l+a[i]-x);
	}
	if(s < k) cout << -1;
	else cout << t+1 ;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
