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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    //cout << int(-3.0000) << " " << int (3.9999) << endl; // -3 3
    int n; cin >> n;
    vector<pair<double, int> > a(n, {0.0, -1});
    vector<int > b(n, 0);
    vector<int > v(n, 0);

    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());

    int sep;
    for (sep = 0; sep < n; ++sep) if (a[sep].fi >= 0) break;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if ((double(int(a[i].fi)) == a[i].fi)) {
            v[i] = 1;
        }
        int x = int(a[i].fi);
        b[a[i].se] = x;
        res += x;
    }

    if (res > 0) {
        for (int r = 0; r < sep; ++r) if (v[r] == 0) {
            b[a[r].se]--;
            res--;
            if (res == 0) break;
        }
    }
    else if (res < 0) {
        for (int r = sep; r < n; ++r) if(v[r] == 0){
            b[a[r].se]++;
            res++;
            if (res == 0) break;
        }
    }

    for (int i = 0; i < n; ++i) cout << b[i] << endl;



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
