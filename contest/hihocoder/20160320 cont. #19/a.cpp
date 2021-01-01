#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j; i<(int)k; ++i)
#define ll long long

using namespace std;
const int N = 1594323;
const int M = 2187;
const int G = 128;

ll dp[2][N][2];
int H[N], L[N];
int tr[M][G][2];
int te[13] = {1, 3, 9, 27, 81, 243, 729, 2187};

void deal() {
    rep(i, 8, 13) te[i] = te[i-1]*3;
    rep(i, 0, N) H[i] = i / M, L[i] = i % M;

    rep(i, 0, M) rep(j, 0, G) rep(p, 0, 2) {
                int v = i;
                rep(k, 0, 7) {
                    int x = i / te[k] % 3;
                    if((j >> k & 1)) {
                        if(x < 2) v += te[k] * (x ? -1 : 1);
                    }
                    else if(x == 2) v += te[k] * (p - 2);
                }
                tr[i][j][p] = v;
            }
    return ;
}

inline bool g(int v, int k) {
    for(int i = 0, x = v%3; i < 13; ++i, v/=3, x=v%3)
        if(x==2&&!k || x==1) return false;
    return true;
}

int main()
{
    deal();
    int n, p = 0;
    scanf("%d", &n);
    dp[p][N-1][0] = 1;
    rep(i, 0, n) {
        int x; scanf("%d", &x);
        int xh = x / G, xl = x % G;
        memset(dp[p^1], 0, sizeof dp[p^1]);
        rep(j, 0, N) {
            rep(k, 0, 2) {
                if(!dp[p][j][k]) continue;
                int h = tr[H[j]][xh][k], l = tr[L[j]][xl][k];
                int s = h * M + l;

                dp[p^1][s][k^1] += dp[p][j][k];
                dp[p^1][j][k] += dp[p][j][k];
            }
        }
        p ^= 1;
    }

    ll s = 0;
    rep(j, 0, N) rep(k, 0, 2)
        if(dp[p][j][k] && g(j, k)) s += dp[p][j][k];
    printf("%lld\n", s);

    return 0;
}

// 1381179311326
