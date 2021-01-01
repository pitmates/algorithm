#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
using namespace std;

struct Matrix{
    int c;
    ll mx[3][3];
    Matrix() {
        c = 3;
        memset(mx, 0, sizeof mx);
    }
    void emx() {rep(i, 0, c) mx[i][i] = 1;}
    void init_mx() {
        mx[0][0] = 4; mx[1][0] = 2; mx[0][2] = mx[2][2] = 1;
    }
    Matrix multi(Matrix a, ll mo) {
        Matrix res;
        rep(i, 0, c) rep(j, 0, c) rep(k, 0, c)
            res.mx[i][j] = (res.mx[i][j] + (mx[i][k] * a.mx[k][j]) % mo) % mo;
        return res;
    }
    Matrix pow(int z, ll mo) {
        Matrix res; res.emx();
        Matrix a; a.init_mx();
        while(z) {
            if(z&1) res = res.multi(a, mo);
            a = a.multi(a, mo);
            z >>= 1;
        }
        return res;
    }
};

int main()
{
    ll n, m;
    while(~scanf("%lld %lld", &n, &m)){
        int x = n/2, s = 0;
        int t = (n&1) ? 0 : 1;
        Matrix y;
        y = y.pow(x, m);
        s = (y.mx[t][0] + y.mx[t][2]) % m;
        printf("%lld\n", s);
    }
    return 0;
}
