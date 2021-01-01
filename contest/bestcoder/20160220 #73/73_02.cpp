#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
const int MOD = 998244353;

inline void add(int& x, int y) {
    x += y; if(x >= MOD) x -= MOD;
    return ;
}

char c[N/3];
int dg[N], len;
int f[N][N<<1][2][2][2];

int deal() {
    int le = strlen(c);
    int len = 0, k, l = 0;
    int g[N/3];
    for(int i = 0; i < le; ++i) g[i] = c[i] - '0';
    while(l < le) {
        k = 0;
        for(int i = l; i < le; ++i) {
            g[i] = (k * 10 + g[i]);
            k = g[i] % 2;
            g[i] /= 2;
        }
        dg[len++] = k;
        if(g[l] == 0) ++l;
    }
    return len;
}

int dfs(int i, int s, bool e1, bool e2, bool g) {
    int& ans = f[i][s][e1][e2][g];
    if ( ans != -1) return ans;
    ans = 0;
    if (i == len) return ans = (s > len && g);
    int u1 = e1 ? dg[i] : 1;
    int u2 = e2 ? dg[i] : 1;
    for (int x1 = 0; x1 <= u1; x1++) {
        for (int x2 = 0; x2 <= u2; x2++) {
            int ff3 = g;
            if (ff3 == 0) {
                if (x1 > x2) continue;
                if (x1 < x2) ff3 = 1;
            }
            add(ans, dfs(i + 1, s + x1 - x2, e1&&(x1==u1), e2&&(x2==u2), ff3));
        }
    }
    return ans;//(e1||e2) ? ans : f[i][s][e1][e2][g] = ans;
    /**
    int& res = f[i][s][g];
    if(~res) return res;
    res = 0;
    if(i == -1) return res = (s > len && g);
    int u1 = e1 ? dg[i] : 1;
    int u2 = e2 ? dg[i] : 1;
    for(int d1 = 0; d1 <= u1; ++d1){
        for(int d2 = 0; d2 <= u2; ++d2) {
            bool gf = g;
            if(!gf) {
                if(d1 > d2) continue;
                if(d1 < d2) gf = 1;
            }
    printf("i:%d  d1:%d  d2:%d  e1:%d  e2:%d  g:%d  gf:%d  s:%d  \n", i, d1, d2, e1, e2, g, gf, s);
            add(res, dfs(i-1, s+d1-d2, e1&&d1==u1, e2&&d2==u2, gf));
    printf("res : %d\n", res);
        }
    }
    return res;
    */
}

int solve() {
    len = deal();
    reverse(dg, dg+len);
    return dfs(0, len, 1, 1, 0);
}

int main()
{
#ifdef PIT
freopen("73_02.in", "r", stdin);
#endif // PIT
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", c);
        memset(f, -1, sizeof f);
        printf("%d\n", solve());
    }
    return 0;
}
