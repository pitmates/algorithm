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
	string s;
	int d[6];
	cin >> s;
	rep(i, 0, 6) d[i] = s[i] - '0';
	int f = 0, e = 0;
	rep(i, 0, 3) f += d[i], e += d[3+i];
	if(f == e) cout << 0;
	else {
		int a[6];
		int mv = 4;
		if(f > e) {
			int dif = f - e, i;
			rep(i, 0, 3) a[i] = d[i];
			rep(i, 3, 6) a[i] = 9-d[i];
			sort(a, a+6);
			reverse(a, a+6);
			for(i = 0; i < 3; ++i){
				if(dif <= 0) break;
				dif -= a[i];
			}
			mv = min(mv, i);
		}
		else {
			int dif = e - f, i;
			rep(i, 0, 3) a[i] = 9 - d[i];
			rep(i, 3, 6) a[i] = d[i];
			sort(a, a+6);
			reverse(a, a+6);
			for(i = 0; i < 3; ++i) {
				if(dif <= 0) break;
				dif -= a[i];
			}
			mv = min(mv, i);
		}
		cout << mv;
	}	
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
