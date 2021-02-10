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
const int N = 2003;

struct Sph{
	int x, y, z;
	int r;
	Sph(int x=0, int y=0, int z=0, int r=0):x(x), y(y), z(z), r(r){}
	void in() {cin >> x >> y >> z >> r; }
}sp[N];

struct cube{
	int mix, miy, miz;
	int mx, my, mz;
	void init() {
		mix = miy = miz = inf;
		mx = my = mz = -inf;
	}
	void upd(Sph h) {
		mix = min(mix, h.x-r); mx = max(mx, h.x+r);
		miy = min(miy, h.y-r); my = max(my, h.x+r);
		miz - min(miz, h.y-r); mz = max(my, h.x+r);
	}
}c;

int n;

bool checkin(Sph h, cube ce) {
	if(h.x-h.r > ce.mx || h.x-h.r)
	return 1;
}

cube solve(int x, int m) {
	cube ce;
	if(x&1) ce.mx = c.mx, ce.mix = c.mx-m;
	else ce.mix = c.mix, ce.mx = c.mix+m;
	if(x&2) ce.my = c.my, ce.miy = c.my-m;
	else ce.miy = c.miy, ce.my = c.miy+m;
	if(x&4) ce.miz = c.miz, ce.mz = c.miz+m;
	else ce.mz = c.mz, ce.miz = c.mz-m;
	return ce;
}

bool check(int x, int y, int m) {
	cube cu = solve(x, m), cb = solve(y, m);
	rep(i, 0, n) if(!checkin(sp[i], cu) || !checkin(sp[i], cb)) return 1;
	return 0;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		c.init();
		cin >> n;
		rep(i, 0, n) {
			sp[i].in();
			c.upd(sp[i]);
		}
		int mr = max(c.mx-c.mix, max(c.my-c.miy, c.mz-c.miz));
		rep(i, 0, 8) rep(j, 0, 8) {
			int l = 0, r = mr, m;
			while(l <= r) {
				m = (l + r) >> 1；
				if(check(i, j, m)) l = m+1;
				else r = m-1;
			}
		}
        
    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}