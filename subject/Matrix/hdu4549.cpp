#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const ll mo = 1000000007LL;

struct Matrix{
    int r, c;
    ll mtx[2][2];

    Matrix(int _=0, int __=0) : r(_), c(__){
        memset(mtx, 0, sizeof mtx);
    }
    void I() {
        rep(i, 0, r) mtx[i][i] = 1;
    }

    Matrix operator * (Matrix & mx) {
        Matrix ret(r, mx.c);
        rep(k, 0, c)
        rep(i, 0, r){
            if(mtx[i][k] == 0) continue;
            rep(j, 0, mx.c)
                ret.mtx[i][j] = (ret.mtx[i][j] + mtx[i][k] * mx.mtx[k][j]) % (mo-1);
        }
        return ret;
    }
};

Matrix mat_pow(ll n) {
    Matrix ret(2, 2); ret.I();
    Matrix tmp(2, 2);
    tmp.mtx[0][0] = tmp.mtx[0][1] = tmp.mtx[1][0] = 1;
    while(n) {
        if(n&1) ret = tmp * ret;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ret;
}

ll mul_mod(ll x, ll y) {
    ll z = 1LL;
    while(y) {
        if(y&1) z = (z * x) % mo;
        x = (x * x) % mo;
        y >>= 1;
    }
    return z;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ll a, b, n;
    while(scanf("%I64d %I64d %I64d", &a, &b, &n) != EOF) {
        Matrix res = mat_pow(n);
        ll ans = mul_mod(b, res.mtx[1][0]) * mul_mod(a, res.mtx[1][1]) % mo;
        printf("%lld\n", ans);
    }
    return 0;
}
