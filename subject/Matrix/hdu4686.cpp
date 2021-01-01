#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const ll mo = 1000000007LL;
const int N = 6;

ll n, a0, ax, ay, b0, bx, by;

struct Matrix {
    int r, c;
    ll mx[N][N];

    Matrix(int _ = 0, int __ = 0) : r(_), c(__) {
        zero(mx);
    }

    void I(ll ax, ll ay, ll bx, ll by) {
        mx[0][0] = mx[0][1] = mx[4][4] = 1LL;
        mx[1][2] = ax*by % mo; mx[1][3] = bx*ay % mo;
        mx[1][1] = ax*bx % mo; mx[1][4] = ay*by % mo;
        mx[2][2] = ax ; mx[2][4] = ay ;
        mx[3][3] = bx ; mx[3][4] = by ;
    }
    void I(ll a0, ll ax, ll ay, ll b0, ll bx, ll by) {
        mx[0][0] = a0 * b0 % mo; mx[4][0] = 1;
        mx[2][0] = (a0 * ax % mo + ay) % mo;
        mx[3][0] = (b0 * bx % mo + by) % mo;
        mx[1][0] = mx[2][0] * mx[3][0] % mo;
    }

    Matrix operator * (const Matrix& M) const {
        Matrix res(r, M.c);
        rep(k, 0, c) rep(i, 0, r) {
            if(mx[i][k] == 0) continue;
            rep(j, 0, M.c)
                res.mx[i][j] = (res.mx[i][j] + mx[i][k] * M.mx[k][j] % mo) % mo;
        }
        return res;
    }

    Matrix operator ^ (ll x) {
        Matrix res(5, 1); res.I(a0, ax, ay, b0, bx, by);
        Matrix M(5, 5); M.I(ax, ay, bx, by);
        while(x) {
            if(x & 1) res = M * res;
            M = M * M;
            x >>= 1;
        }
        return res;
    }
};

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    while(cin >> n >> a0 >> ax >> ay >> b0 >> bx >> by){
        if(!n) {
            cout << 0 << endl;
            continue;
        }
        a0 %= mo; ax %= mo; ay %= mo; b0 %= mo; bx %= mo; by %= mo;
        Matrix res(5, 1);
        res = res ^ (n-1);
        cout << res.mx[0][0] << endl;
    }

    return 0;
}

/**
12334455
123 34234 46534
3423 534534534 342354353
**/
