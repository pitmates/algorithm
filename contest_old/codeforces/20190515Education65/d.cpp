//
// Created by pitmates on 2019-05-15.
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
    string s;
    cin >> n >> s;

    vector<int > val(n, 0);
    int d = 0, f = 0;
    vector<int > v;
    v.push_back(0);
    for (int i = 1; i < n; ++i) {
        if (s[i] == ')') {
            int x = v[d++] == 0 ? 0 : 1;
            val[i] = x;
        }
        else {
            int x = f == 0 ? 1 : 0;
            f ^= 1;
            v.push_back(x);
            val[i] = x;
        }
    }
    for (int i = 0; i < n; ++i) cout << val[i];
    cout << endl;

#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
