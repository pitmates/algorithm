#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 100100;

int n;
ll m, z;
bool x[N], y[N];

int main()
{
#ifdef PIT
freopen("701b.in", "r", stdin);
#endif // PIT
    scanf("%d %I64d", &n, &m);
    memset(x, 0, sizeof x); memset(y, 0, sizeof y);
    z = 1LL * n * n;
    int u = n, v = n;
    while(m--) {
        int a, b, c = 0, d = 0;
        scanf("%d %d", &a, &b);
        if(!x[a]) x[a] = 1, z -= u, c = 1;
        v -= c;
        if(!y[b]) y[b] = 1, z -= v, d = 1;
        u -= d;
        printf("%I64d%c", z, (m) ? ' ' : '\n');
    }

    return 0;
}
