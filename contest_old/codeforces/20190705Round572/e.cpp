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


ll calc(ll x, ll k, ll p) {
    ll four_exp_x = x * x % p * x % p * x % p;
    ll kx = x * k % p;
    ll res = (four_exp_x - kx + p) % p;
    return res;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    ll p, k;
    cin >> n >> p >> k;
    map<ll, int > mmp; mmp.clear();
    
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        ll res = calc(x, k, p);
        mmp[res]++;
    }
    
    ll ans = 0;
    for (auto z : mmp) {
        int y = z.second;
        ans += 1LL * y * (y-1) / 2;
    }
    cout << ans << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
