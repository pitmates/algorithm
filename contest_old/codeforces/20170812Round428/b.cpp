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
const int N = 103;

int a[N];
int n, k;

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	rep(i, 0, k) cin >> a[i];
	int m = n, t = 0;
	while(m) {
		if(a[t] > 3) a[t] -= 4, --m;
		else while(a[t] < 4 && t < k) ++t;
		if(t == k) break;
	}
// printf("m == %d\n", m);
	if(m) {
		int p = n+n, f = 0;
		rep(i, 0, k) {
			if(a[i] == 2) {
				if(p) --p;
				else --m, ++f;
			}
			else if(a[i] == 1) {
				if(f) --f;
				else --m, ++p;
			}
			else {
				if(m) --m;
				else p -= 2;
			}
		}
		if(p < 0) cout << "NO";
		else cout << "YES";
	}
	else {
		int p = n + n;
		rep(i, 0, k) {
			// printf("%d %d\n", i, p);
			p -= (a[t] + 1) / 2;
		}
// printf("%d \n", p);
		if(p < 0) cout << "NO";
		else cout << "YES";
	}
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
