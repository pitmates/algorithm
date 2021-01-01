#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int N = 100100;

pair<double, double > t[N];
double d;
int ax, ay, bx, by, tx, ty;
int n;

double dist(int a, int b, int x, int y) {
    return sqrt(1.*(a-x)*(a-x) + 1.*(b-y)*(b-y));
}

void in() {
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%d", &n);
    int x, y;
    d = 0;
    rep(i, 0, n) {
        scanf("%d %d", &x, &y);
        double da, db, dt;
        da = dist(ax, ay, x, y);
        db = dist(bx, by, x, y);
        dt = dist(tx, ty, x, y);
        d += dt + dt;
        t[i] = {dt-da, dt-db};
    }
    sort(t, t+n);
    return ;
}

void solve() {
    double mx = -1e16;
    for(int i = n-1; i >= 0; --i) {
        mx = max(mx, t[i].fi);
        mx = max(mx, t[i].se);
        if(i == n-1) mx = max(mx, t[i-1].fi+t[i].se);
        else mx = max(mx, t[n-1].fi+t[i].se);
    }
    printf("%.8f\n", d-mx);
    return ;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    in();
    solve();
    return 0;
}
