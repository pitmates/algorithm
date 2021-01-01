#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define ui unsigned int
#define mp make_pair
using namespace std;
const int M = 155;

int base, N;
int score;

struct Matrix{
    int r, c;
    ui mtx[M][M];

    Matrix(int r = 0, int c = 0) {
        this->r = r; this->c = c;
        memset(mtx, 0, sizeof mtx);
    }

    Matrix operator * (Matrix& a) {
        Matrix res(r, a.c);
        for(int k = 0; k < c; ++k)
        for(int i = 0; i < r; ++i) {
            if(!mtx[i][k]) continue;
            for(int j = 0; j < a.c; ++j)
                res.mtx[i][j] = res.mtx[i][j] + mtx[i][k] * a.mtx[k][j];
        }
        return res;
    }
};

ui dp[M][M];

void dcpm() {
    N = (base - 1) * (base - 1);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i < base; ++i) dp[0][i] = 1;

    for(int k = 1; k <= N; ++k)
    for(int i = 0; i < base; ++i)
            for(int j = 0; j < base; ++j){
                int d = (i-j) * (i-j);
                if(k >= d && d) dp[k][j] = dp[k][j] + dp[k-d][i];
            }
    return ;
}

Matrix init() {
    Matrix res(N*base, 1);
    for(int i = 1; i <= N; ++i)
    for(int j = 0; j < base; ++j)
        res.mtx[(i-1)*base+j][0] = dp[i][j];
    return res;
}

Matrix build() {
    int n = N * base;
    Matrix x(n, n);
    for(int i = base; i < n; ++i) x.mtx[i-base][i] = 1;
    for(int i = 0; i < base; ++i)
    for(int j = 0; j < base; ++j){
            int d = (i - j) * (i - j);
            if(d) x.mtx[n-base+i][(N-d)*base+j] = 1;
    }
    return x;
}

Matrix mat_pow(Matrix res, int z) {
    Matrix mx = build();

    while(z) {
        if(z & 1) res = mx * res;
        mx = mx * mx;
        z >>= 1;
    }
    return res;
}

ui solve() {
    ui ans = 0;
    if(score <= N) {
        for(int i = 0; i < base; ++i)
            ans += dp[score][i];
        return ans;
    }

    Matrix res = init();
    res = mat_pow(res, score-N);
    for(int i = 0; i < base; ++i)
        ans += res.mtx[(N-1)*base+i][0];
    return ans;
}

int main()
{
    #ifdef PIT
    freopen("uva11651.in", "r", stdin);
    freopen("uva11651.out", "w", stdout);
    #endif // PIT
    int T, ic = 1;
    for(scanf("%d", &T); T--; ic++) {
        printf("Case %d: ", ic);
        scanf("%d %d", &base, &score);
        dcpm();
        printf("%u\n", solve());
    }
    return 0;
}
/**
2
6 1
5 6
**/
