//
// coded by zhuangliupeng
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

const ll mo = 1000000007LL;

struct Matrix{
    ll m[3][3];
    Matrix() {}
    void zerom() { zero(m); }
    void I() {
        zerom();
        m[0][0] = m[1][1] = m[2][2] = 1;
    }
    void init() {
        zerom();
        m[0][0] = m[0][1] = m[0][2] = m[1][0] = m[2][1] = 1;
    }
    void print() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) cout << m[i][j] << " ";
            cout << endl;
        }
    }
    Matrix mul(Matrix a) {
        Matrix ans;
        ans.zerom();
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    ans.m[i][j] += (m[i][k] * a.m[k][j]) % (mo-1);
                }
                ans.m[i][j] %= (mo-1);
            }
        }
        return ans;
    }
    Matrix exp(ll y) {
        Matrix ans, res;
        ans.I(); res.init();
        while(y) {
            if (y&1) ans = ans.mul(res);
            res = res.mul(res);
            y >>= 1;
        }
        //ans.print();
        return ans;
    }
}matrix;

ll exp(ll x, ll y) {
    ll ans = 1, res = x;
    while(y) {
        if (y & 1) ans = ans * res % mo;
        res  = res * res % mo;
        y >>= 1;
    }
    return ans;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    //cout << exp(2, 4) << " " << exp(2, 5) << endl; 4 1 2 5 3
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix a = matrix.exp(n-3);
    ll ff3 = exp(c, 3) * f3 % mo, ff2 = exp(c, 2) * f2 % mo, ff1 = c * f1 % mo;
    ll tn = (exp(ff3, a.m[0][0]) * exp(ff2, a.m[0][1]) % mo) * exp(ff1, a.m[0][2]) % mo;
    ll y = mo - 1 - (n % (mo-1));
    ll cn_1 = exp(c, y);
    ll fn = tn * cn_1 % mo;
    //cout << cn_1 << "  " << tn << endl;
    cout << fn << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
