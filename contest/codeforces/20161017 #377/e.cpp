#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x3f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 200200;

int n, m;
int so[N], po[N];
pii power[N], socket[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    //ios_base::sync_with_stdio(false); cin.tie(0);

    scanf("%d %d", &n, &m);
    zero(so); zero(po);
    int s, p;
    rep(i, 0, n) {
        scanf("%d", &p); power[i] = {p, i};
    }
    rep(i, 0, m) {
        scanf("%d", &s); socket[i] = {s, i};
    }

    sort(power, power+n); sort(socket, socket+m);
    int res = 0, ans = 0;
    rep(k, 0, 32) {
        p = 0;
        rep(i, 0, m) if(socket[i].fi){
            while(p < n && (power[p].fi < socket[i].fi || po[power[p].se])) ++p;
            if(p < n && power[p].fi == socket[i].fi){
                ++ans; res += k;
                po[power[p].se] = socket[i].se + 1;
                so[socket[i].se] = k;
                socket[i].fi = 0;
            }
        }
        rep(i, 0, m) socket[i].fi = (socket[i].fi + 1) / 2;
    }
    printf("%d %d\n", ans, res);
    rep(i, 0, m) printf((i) ? " %d" : "%d", so[i]); puts("");
    rep(i, 0, n) printf((i) ? " %d" : "%d", po[i]); puts("");
    return 0;
}
