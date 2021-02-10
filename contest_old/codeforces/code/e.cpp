//
// coded by lp.z
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


class BIT {
public:
    vector<ll > b;
    BIT(int n) {
        b.resize(n+1, 0LL);
    }
    void upd(int x, ll y);
    ll qry(int x);
    ~BIT() {}
};

void BIT::upd(int x, long long y=1LL) {
    for (int i = x; i < b.size(); i += i&(-i)) {
        b[i] += y;
    }
    return;
}

ll BIT::qry(int x) {
    ll res = 0;
    for (int i = x; i; i -= i&(-i)) {
        res += b[i];
    }
    return res;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int > v = {3, 2, 5, 1, 4}, d(6);
    int n = 5;
    for (int i = 0; i < n; ++i) d[v[i]] = i+1;
    BIT bit(n);
    for (int i = 1; i <= n; ++i) {
        ll x = bit.qry(d[i]), y = i - 1 - x, z = bit.qry(n);
        bit.upd(d[i]);
        if (i&1) z = bit.qry(n);
        for (int i = 1; i <= n; ++i) cout << bit.b[i] << " ";
        cout << "  " << x << " " << y << " " << (z+1)/2 << endl;
    }

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
