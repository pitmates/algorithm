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

    int n;
    cin >> n;
    vector<int > a(n, 0);
    map<int, int > mmp;
    mmp.clear();
    int cnt = 0, p = -1;
    mmp[-1] = 1;
    for (int i = 0, u; i < n; ++i) {
        cin >> u;
        mmp[u]++;
        if (mmp[u] > 1) {
            cnt++;
            p = u;
        }
        a[i] = u;
    }
    if (cnt > 1 || (cnt == 1 && mmp[p-1])) {
        cout << "cslnb" << endl;
    }
    else {
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) a[i] -= i;
        int z = 0;
        // for (int i = 0; i < n; ++i) cout << a[i] << " "; cout << endl;
        for (int i = 0; i < n; ++i) z ^= a[i];
        if (!(z & 1)) cout << "cslnb" << endl;
        else cout << "sjfnb" << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
