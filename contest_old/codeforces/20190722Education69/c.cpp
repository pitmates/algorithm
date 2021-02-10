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

    int n, k;
    cin >> n >> k;
    vector<int > a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (k == n) {
        cout << 0 << endl;
    }
    else if (k == 1) {
        cout << a[n] - a[1] << endl;
    }
    else {
        vector<pii > b(n+1);
        for (int i = 2; i <= n; ++i) {
            b[i] = {a[i] - a[i-1], i-1};
        }
        sort(b.begin(), b.end());
        vector<int > idx;
        for (int i = 0, j = n; i < k-1; ++i, --j) {
            idx.push_back(b[j].second);
        }
        sort(idx.begin(), idx.end());
        ll ans = 0;
//        for (int i = 0; i < k-1; ++i) cout << idx[i] << " "; cout << endl;
        int l = 1;
        for (int i = 0; i < k-1; ++i) {
            ans += a[idx[i]] - a[l];
            l = idx[i] + 1;
        }
        cout << ans + a[n] - a[l] << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
6 3
4 7 15 16 23 42

 */