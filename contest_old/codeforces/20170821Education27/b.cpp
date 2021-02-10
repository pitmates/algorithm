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
	cin >> s;
	int d[6];
	rep(i, 0, 6) d[i] = s[i] - '0';
	int f = d[0] + d[1] + d[2];
	int e = d[3] + d[4] + d[5];
	if(f == e) cout << 0 ;
	else {
		int df = f - e;
		if(df > 0) {
			int a[3];
			rep(i, 0, 3) a[i] = d[i];
			sort(a, a+3);
			int dff = df, mv = 4;
			rep(i, 0, 3) {
				if(dff - a[2-i] <= 0) {
					mv = min(mv, 1+i);
					break;
				}
				dff -= a[2-i];
			}
			dff = df;
			rep(i, 0, 3) a[i] = 9-d[i+3];
			sort(a, a+3);
			rep(i, 0, 3) {
				if(dff - a[2-i] <= 0) {
					mv = min(mv, 1+i);
					break;
				}
				dff -= a[2-i];
			}
			cout << mv;
		}
		else {
			int a[3];
			df = -df;
			// cout << "df = " << df << endl;
			rep(i, 0, 3) a[i] = 9-d[i];
			sort(a, a+3);
			int dff = df, mv = 4;
			rep(i, 0, 3) {
				if(dff - a[2-i] <= 0) {
					mv = min(mv, i+1);
					// printf("i:%d.  mv:%d\n", i, mv);
					break;
				}
				dff -= a[2-i];
			}
			dff = df;
			rep(i, 0, 3) a[i] = d[i+3];
			sort(a, a+3);
			rep(i, 0, 3) {
				if(dff - a[2-i] <= 0) {
					mv = min(mv, 1+i);
					break;
				}
				dff -= a[2-i];
			}
			cout << mv;
		}
	}
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
