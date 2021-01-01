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
#define db double
#define cn const
#define op operator
#define rt return 
#define cp cn P&

using namespace std;

cn db pi = acos(-1.0);
cn db eps = 1e-8;

inline int sig(db x) {rt (x>eps) - (x<-eps);}

struct P{
    db x, y;
    P() {}
    P(db x, db y) : x(x), y(y) {}
    void in() { cin >> x >> y;}
    P op-(cp a)cn {rt P(x-a.x, y-a.y);}
    P op+(cp a)cn {rt P(x+a.x, y+a.y);}
    db op^(cp a)cn{rt x*a.y - y*a.x;}
    db dis2() {rt x*x + y*y;}
    db dis() {rt sqrt(dis2());}
};

struct CCL{
    P o;
    db r;
    CCL() {}
    CCL(P a, db r): o(a), r(r) {}
    void in(db _) { o.in(); r = _;}
 	void out() {printf("(%.2f %.2f) %.2f\n", o.x, o.y, r); }
    /** 0:a 包含 c  1: c 包含 a  2: a 与 c 等同,  3:相交， 4：相离 **/
    int rela(CCL c) {
        db d = (o-c.o).dis();
        int d1 = sig(d + r - c.r), d2 = sig(d + c.r - r);
        if(sig(d - r - c.r) >= 0) rt 4;
        if(!d2 && !d1) rt 2;
        if(d2 <= 0) rt 0;
        if(d1 <= 0) rt 1;
        rt 3;
    }
};

#define N 2017

/** 覆盖 k 次的面积 cover[k] - cover[k+1];  cover[1]: 并集 ; cover[n]: 交集 **/
db cover[N];
CCL c[N];
pair<db, int> e[N<<2];
int cnt;
int maxv;


void sweep_ccl(CCL c[], int n) {
    memset(cover, 0, sizeof cover);
    maxv = 0;
    for(int i = 0; i < n; ++i) if(sig(c[i].r) > 0) {
        cnt = 0;
        e[cnt++] = mp(-pi, 1);
        e[cnt++] = mp(pi, -1);
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            int tmp = c[i].rela(c[j]);
            if(tmp == 1 || (tmp == 2 && i < j)) {
                e[cnt++] = mp(-pi, 1);
                e[cnt++] = mp(pi, -1);
            } else if(tmp == 3) {
                db ang = atan2((c[j].o-c[i].o).y, (c[j].o-c[i].o).x);
                db d = (c[i].o - c[j].o).dis(), d2 = (c[i].o - c[j].o).dis2();
                db tp = acos((c[i].r*c[i].r + d2 - c[j].r*c[j].r) / (2.*d*c[i].r));
                db l = ang - tp, r = ang + tp;

                if(sig(l + pi) < 0) l += 2. * pi;
                if(sig(r - pi) > 0) r -= 2. * pi;

                e[cnt++] = mp(l, 1);
                e[cnt++] = mp(r, -1);

                if(sig(l - r) > 0) {
                    e[cnt++] = mp(-pi, 1);
                    e[cnt++] = mp(pi, -1);
                }
            }
        }
        sort(e, e+cnt);

        int t = 0;
        /* 
        // count the area of cover circle
        db l = -pi;
        P p = c[i].o + P(-c[i].r, 0), q;
        for(int k = 0; k < cnt; ++k) {
            db r = e[k].first;
            q = c[i].o + P(c[i].r*cos(r), c[i].r * sin(r));
            cover[t] += 0.5*c[i].r*c[i].r*(r-l-sin(r-l)) + (p^q)*0.5;
            t += e[k].second;
            p = q, l = r;
        }
        */
       	for(int k = 0; k < cnt; ++k) {
       		t += e[k].second;
       		maxv = max(maxv, t);
       	}
    }

}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
int _time_zlp = clock();
#endif //PIT

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	db r;
	cin >> n >> r;
	rep(i, 0, n) c[i].in(r);
	//rep(i, 0, n) c[i].out();
	sweep_ccl(c, n);
	cout << maxv << endl;

#ifdef PIT
debug("Time: %f s\n", double(clock()-_time_zlp)/CLOCKS_PER_SEC);
#endif //PIT
	return 0;
}
