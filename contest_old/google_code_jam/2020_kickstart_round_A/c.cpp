//
// Created by pitmates on 2019-05-04.
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

pii judge_max(vector<int >& G, int m) {
    ++m;
    int dis = G[0], div = (dis + m - 1) / m;
    int res = 0, mx = div;
    for (int i = 1; i < G.size(); ++i) {
        if (G[i] <= div) break;
        int nu = (G[i] + div - 1) / div;
        mx = max(mx, (G[i] + nu - 1) / nu);
        res += nu;
    }
//    cout << " div: " << div << "  res: " << res << "  " << res + m << endl;
    return {res+m, mx};
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
        //cout << "Case #" << ic << ":" << endl;
        int n, k;
        cin >> n >> k;
        vector<int > gap(n-1), A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            if (i) gap[i-1] = A[i] - A[i-1];
        }

        sort(gap.begin(), gap.end());
        reverse(gap.begin(), gap.end());

        int l = 1, r = k, m;
//        cout << endl;
        while (l <= r) {
            m = (l + r) >> 1;
//            cout <<  m << " " << l << "  " << r << endl;
            auto jm = judge_max(gap, m);
            if (jm.first > k) r = m - 1;
            else if (jm.first == k) break;
            else l = m + 1;
//            cout << "    " << m << " : " << l << " " << r << endl;
        }

        cout << judge_max(gap, m).second << endl;


    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}