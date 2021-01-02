#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int N = 100100;
ll city[N], tower[N];
int n, m;
pair<ll, ll > p[N];

int main()
{
#ifdef PIT
freopen("c.in", "r", stdin);
#endif // PIT

    scanf("%d %d", &n, &m);
    rep(i, 0, n) scanf("%I64d", city+i);
    rep(i, 0, m) scanf("%I64d", tower+i);

    ll l = 0, r = 2e9+10, x;
    p[m].fi = p[m].se = r+r;
    while(l <= r) {
        x = l + r >> 1;
//printf("l:%I64d  r:%I64d  x:%I64d\n", l, r, x);
        rep(i, 0, m) {
            p[i].fi = tower[i] - x;
            p[i].se = tower[i] + x;
        }
//rep(i, 0, m) printf("(%I64d %I64d) ", p[i].fi, p[i].se); printf("|| %I64d ", city[0]); puts("");
        int k = 0, flag = 0;
        rep(i, 0, n) {
            if(city[i] >= p[k].fi && city[i] <= p[k].se) continue;
            if((city[i] > p[k].se && city[i] < p[k+1].fi) || (city[0] < p[0].fi)) {
                flag = 1;
                break;
            }
            while(city[i] > p[k].se) ++k;
        }
        if(flag) l = x + 1;
        else r = x - 1;
    }
    printf("%I64d\n", l);
    return 0;
}
