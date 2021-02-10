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
const int N = 100100;

struct Cir{
	int x, y;
	int r;
	void in() {cin >> x >> y >> r; }
};
Cir c[N];

double dis(Cir a) {
	return sqrt(1.0*a.x*a.x + a.y*a.y);
}

int R, d;
int n;


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> R >> d;
	cin >> n;
	rep(i, 0, n) c[i].in();
	int ans = 0, rd = R - d;
	rep(i, 0, n) {
		double df = dis(c[i]);
		if(df >= rd && df <= R) {
			if(df + c[i].r <= R && df - c[i].r >= rd) ++ans;
		}
	}
	cout << ans ;
	
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
	return 0;
}
