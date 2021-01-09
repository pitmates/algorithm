#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const int N = 5678;
const ll M = 1e9+7;

ll c[N][N], dp[N][N];
int a[N];

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i][0] = 1;
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            c[i][j] = (c[i-1][j-1] + c[i+1][j-1]) % M;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = ( c[i][j] * c[i][k-j]) % M;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][0] = (dp[i][0] +  dp[i][j]) % M;
        }
    }


    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        // printf("%lld ", dp[i][0]);
        res = (a[i] * dp[i][0] % M + res) % M;
    }
    
    // printf("   =======\nres = %lld\n", res);
    while (q--) {
        int x, d;
        cin >> x >> d;
        res = (res - (1LL *(a[x] - d) * dp[x][0] % M) + M) % M;
        a[x] = d;
        cout << res << endl;
    }



    return 0;
}
