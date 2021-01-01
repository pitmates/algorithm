#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const ll mo = 1000000007LL;

struct Matrix{
    int n, m;
    ll mx[2][2];
    Matrix(int a=2, int b=2) {
        n = a; m = b;
        memset(mx, 0, sizeof mx);
    }
    void e() { rep(i, 0, n) mx[i][i] = 1; }
    void init() { mx[0][0] = mx[1][0] = 1; mx[0][1] = -1; }
    Matrix operator * ( Matrix a)  {
        Matrix res;
        rep(i, 0, n) rep(j, 0, m) rep(k, 0, m)
            res.mx[i][j] = (res.mx[i][j] + mx[i][k] * a.mx[k][j] % mo) % mo;
        return res;
    }
};

Matrix mul(ll z) {
    Matrix res; res.e();
    Matrix w; w.init();
    while(z) {
        if(z&1) res = res * w;
        w = w * w;
        z >>= 1;
    }
    return res;

}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    ll x, y, z;
    cin >> x >> y >> z;
    if(z == 1) cout << (x + mo) % mo << endl;
    else if(z == 2) cout << (y + mo) % mo << endl;
    else {
        z -= 2;
        Matrix v = mul(z);
        ll u = ((v.mx[0][0]*y % mo + mo) % mo + (v.mx[0][1]*x % mo + mo) % mo) % mo;
        cout << u << endl;
    }
    return 0;
}
