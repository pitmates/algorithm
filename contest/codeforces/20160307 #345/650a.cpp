#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 200200;

struct P{
    ll x, y;
    P(ll x=0, ll y = 0) : x(x), y(y) {}
    void in() {scanf("%I64d%I64d", &x, &y); }
    void out() {printf("%I64d %I64d\n", x, y);}
    P operator - (const P& a)const {return P(x-a.x, y-a.y);}
    ll dis() {return sqrt(x*x + y*y);}
    bool operator < (const P& a)const {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator == (const P& a) const {return (x == a.x) && (y == a.y);}
};

bool cmp(P a, P b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

P p[N];
int n;

inline ll mhd(P a, P b) { return abs(a.x - b.x) + abs(a.y - b.y); }

inline ll osd(P a, P b) { return (a-b).dis(); }

void solve() {
    ll ans = 0, l = 1, r = 1;
    sort(p, p+n);
//for(int i= 0; i < n; ++i) p[i].out();

    for(int i = 1; i < n; ++i) {
        if(p[i] == p[i-1]) ++r;
        else {
            ans -= r * (r-1) / 2;
            r = 1;
        }
    }
    if(r > 1) ans -= r * (r-1) / 2;
//printf("ans1 = %I64d\n", ans);
    for(int i = 1; i < n; ++i) {
        if(p[i].x == p[i-1].x) ++l;
        else {
            ans += l * (l-1) / 2;
            l = 1;
        }
    }
    if(l > 1) ans += (l-1) * l / 2;
//printf("ans2 = %I64d   l == %d\n", ans, l);
    sort(p, p+n, cmp);
//for(int i = 0; i < n; ++i) p[i].out();
    l = 1;
    for(int i = 1; i < n; ++i) {
        if(p[i].y == p[i-1].y) ++l;
        else {
            ans += l * (l-1) / 2;
            l = 1;
        }
    }
    if(l > 1) ans += l * (l-1) / 2;
//printf("l == %d   ", l);
    printf("%I64d\n", ans);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) p[i].in();
    solve();
    return 0;
}
