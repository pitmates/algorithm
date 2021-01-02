#include <bits/stdc++.h>

#ifdef PIT
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

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
const int N = 1010;
inline double sqr(double x) {return x*x;}

int n;

struct P{
	double x, y;
	P(double _=0, double __=0) : x(_), y(__) {}
	void in() { cin >> x >> y; }
	P operator - (const P& a)const {return P(x-a.x, y-a.y);}
	double dis2() {return sqr(x)+sqr(y);}
	double dis() {return sqrt(dis2());}
	double operator^(const P& a)const {return x*a.y - y*a.x;}
} ;

P p[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
int _time_zlp = clock();
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) p[i].in();
	p[0] = p[n]; p[n+1] = p[1];
	double mr = 1e9;
	rep(i, 1, 1+n) {
		P pa = p[i]-p[i-1], pb = p[i+1]-p[i], pc = p[i+1]-p[i-1];
		double area = abs(pa^pb), c = pc.dis();
		double r = area / c * 0.5;
		mr = min(r, mr);
	} 
	cout.precision(10);
	cout << mr << endl;
	
#ifdef PIT
debug("Time: %f s\n", double(clock()-_time_zlp)/CLOCKS_PER_SEC);
#endif //PIT
	return 0;
}
