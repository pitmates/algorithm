#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

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

ll n, m, a, b;

struct Matrix{
    int r, c;
    ll mx[2][2];

    Matrix(int _ = 0, int __ = 0) : r(_), c(__) {
        zero(mx);
    }

    void init() {
        mx[0][0] = 2*a; mx[0][1] = -a*a + b;
        mx[1][0] = 1; mx[1][1] = 0;
    }

    Matrix operator * (const Matrix& M) const {
        Matrix res(r, M.c);
        rep(k, 0, c) rep(i, 0, r) {
            if(mx[i][k] == 0) continue;
            rep(j, 0, M.c)
                res.mx[i][j] = (res.mx[i][j] + mx[i][k] * M.mx[k][j] % m) % m;
        }
        return res;
    }

    Matrix operator ^ (ll z) {
        Matrix res(2, 1); res.mx[0][0] = 2*a ; res.mx[1][0] = 2;
        Matrix x(2, 2); x.init();
        while(z) {
            if(z&1) res = x * res;
            x = x * x;
            z >>= 1;
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
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);

    while(cin >> a >> b >> n >> m) {
        Matrix res(2, 1);
        res = res ^ n;
        cout << (res.mx[1][0] + m) % m << endl;
    }
    return 0;
}
