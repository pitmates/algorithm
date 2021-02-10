//
// coded by zhuangliupeng
// undone
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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vector<pii > p(n, {0, 0});
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p.begin(), p.end());
    p.push_back({0, 0});

//    for (int i = 0; i <= n; ++i) cout << p[i].fi << " " << p[i].se << endl;

    vector<int > topy, yv;
    for (int i = 0; i < n; ++i) {
        yv.push_back(p[i].se);
        if (p[i].fi == p[i+1].fi) continue;
        topy.push_back(p[i].se);
    }
    sort(yv.begin(), yv.end());
    sort(topy.begin(), topy.end());
    vector<int >::iterator it = unique(yv.begin(), yv.end());
    yv.resize(distance(yv.begin(), it));

    int x_num = topy.size();
    reverse(yv.begin(), yv.end());
    ll ans = 0;
    for (auto y : yv) {
        int id = lower_bound(topy.begin(), topy.end(), y) - topy.begin();
        int num = x_num - id;
        cout << "y: " << y << "  id: " << id << "  num: " << num << endl;
        ans += 1LL * num * (num+1) / 2;
    }
    cout << ans << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
