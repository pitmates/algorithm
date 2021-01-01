#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;

const int N = 200200;
int n, a;
int x[N];
int y[N<<1];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    zero(x); zero(y);
    cin >> n;
    rep(i, 0, n) cin >> a, x[a]++;
    for(int i = N-10; i; --i) y[i] = y[i+1] + x[i];
    ll ans = 0;
    rep(i, 1, N) if(x[i]){
        ll v = 0, t;
        for(int j = i; j < N; j += i) {
            t = y[j] - y[j+i];
            v += t * j;
        }
        ans = max(ans, v);
    }
    cout << ans;
    return 0;
}
