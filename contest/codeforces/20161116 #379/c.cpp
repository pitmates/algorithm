#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll unsigned long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 200200;

ll n;
int m, k;
ll x, s;
ll a[N], b[N];
ll c[N], d[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    cin >> x >> s;
    rep(i, 0, m) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, k) cin >> c[i];
    rep(i, 0, k) cin >> d[i]; d[k] = (ll)2e9+1;
    ll t = (n - c[upper_bound(d, d+k, s)-d-1]) * x;
    rep(i, 0, m) {
        if(b[i] > s) continue;
        ll v = s - b[i];
        ll ans = 0;
        int idx = upper_bound(d, d+k+1, v) - d;
//    printf("i:%d v:%d  idx:%d\n", i, v, idx);
        if(idx) {
            if(d[idx] > v) --idx;
            ans = a[i] * (n - c[idx]);
        }
        else {
            if(d[idx] > v) ans = a[i] * n;
            else ans = a[i] * (n - c[idx]);
        }
        t = min(t, ans);
    }
    cout << t;
    return 0;
}
