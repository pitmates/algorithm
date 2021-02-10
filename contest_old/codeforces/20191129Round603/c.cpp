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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
//        if (n == 3) {
//            cout << 3 << endl << "0 1 3" << endl;
//            continue;
//        }
        int now = n+1;
        vector<pair<int, int >> sc;
        //sc.push_back({now, 0});
        sc.clear();
        int i;
        for ( i = 1; i * i <= n; ++i) {
            int c = n / i;
            if (now == c) continue;
            now = c;
            if (i * i < n) sc.push_back({now+1, i-1});
            sc.push_back({i, now});
        }
        sc.push_back({i, n / i});
        vector<int > ans;
        ans.clear();
        for (auto z : sc) {
            ans.push_back(z.second);
        }
        sort(ans.begin(), ans.end());
        auto ed = unique(ans.begin(), ans.end());
        ans.resize(std::distance(ans.begin(), ed));
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

