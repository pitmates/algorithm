#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ull unsigned long long
#define mp make_pair

using namespace std;

ull n, x, y;
ull bit[65];
int xb[32], yb[32];
int dir[2][4][4] = {1, 4, 3, 2, 1, 2, 3, 4, 1, 2, 3, 4, 3, 2, 1, 4,
                    3, 2, 1, 4, 3, 2, 1, 4, 3, 4, 1, 2, 1, 2, 3, 4};

inline void init() {
    bit[0] = 1; rep(i, 1, 65) bit[i] = (bit[i-1] << 1);
}

inline void get(int b[], ull z) {
    for(int t = 0; z; z >>= 1) b[t++] = z&1;
}

void solve() {
    int xx[40], t = 0;
    for(int i = n-1, z; i >= 0; --i) {
        if(xb[i]) z = xb[i] * 2 + (yb[i] ^ 1);
        else z = yb[i];
        xx[t++] = z;
    }
rep(i, 0, t) printf("i : %d  %d\n", i, xx[i]);
    ull ans = (ull)xx[0] * bit[n-1] * bit[n-1];
    for(int i = 1, f = 0; i < t; ++i) {
        int z = dir[0][xx[i-1]][xx[i]];
        printf("i : %d f:%d z:%d %llu\n", i, f, z, ans);
        ans += (z - 1) * bit[n-i-1] * bit[n-i-1];
        f ^= 1;
    }
    cout << ans+1 << endl;
}

int main()
{
#ifdef PIT
freopen("c.in", "r", stdin);
#endif // PIT
    init();
    cin >> n >> x >> y;
    --x; --y;
    get(xb, x); get(yb, y);
    solve();
    return 0;
}
