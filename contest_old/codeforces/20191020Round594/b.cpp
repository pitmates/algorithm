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


ll sqr(ll x) {
    return x * x;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<int > v(n);
    long long tot_len = 0, pre_half = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        tot_len += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n/2; ++i) {
        pre_half += v[i];
    }
//    cout << pre_half << " " << tot_len << endl;
    cout << sqr(pre_half) + sqr(tot_len - pre_half) << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
