#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const ll mo = 10000007LL;


struct Matrix{
    int r, c;
    ll mtx[13][13];

    Matrix(int r=0, int c=0) {
        this->r = r; this->c = c;
        memset(mtx, 0LL, sizeof mtx);
    }
    Matrix operator * (Matrix & M) {
        Matrix res(r, M.c);
        for(int k = 0; k < c; ++k)
        for(int i = 0; i < r; ++i){
            if(mtx[i][k] == 0) continue;
            for(int j = 0; j < M.c; ++j)
                res.mtx[i][j] = (res.mtx[i][j] + mtx[i][k] * M.mtx[k][j] % mo) % mo;
        }
        return res;
    }

    void print() {
        for(int i = 0; i < r; ++i){
            for(int j =0; j < c; ++j) printf("%lld ", mtx[i][j]);
            puts("");
        }
    }
};

int n, m;

Matrix build() {
    Matrix x(n+2, n+2);
   for(int i = 0; i <= n; ++i){
        x.mtx[i][0] = 10; x.mtx[i][n+1] = 1;
        for(int j = 1; j <= i; ++j)
            x.mtx[i][j] = 1;
   }
   x.mtx[n+1][n+1] = 1;
   return x;
}

Matrix mat_pow(Matrix res, int x) {
    Matrix mx = build();
    while(x) {
        if(x&1) res = mx * res;
        mx = mx * mx;
        x >>= 1;
    }
    return res;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    while(~scanf("%d %d", &n, &m)) {
        Matrix res(n+2, 1);
        res.mtx[0][0] = 23;
        res.mtx[n+1][0] = 3;
        ll a;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a);
            res.mtx[i][0] = a;
        }
        if(!m) {
            if(!n) puts("0");
            else printf("%lld\n", res.mtx[n][0]);
        }
        else {
            res = mat_pow(res, m);
            printf("%lld\n", res.mtx[n][0]);
        }
    }
    return 0;
}

/**
10 1000000
1 2 3 4 5 6 7 8 9 0

**/
