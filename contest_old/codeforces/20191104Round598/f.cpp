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


bool judge(string s, string t) {
    int n = s.size();
    string ts = s, tt = t;
    sort(ts.begin(), ts.end());
    sort(tt.begin(), tt.end());
    if (ts != tt) return false;
    if (n > 26) return true;

    auto rem = unique(ts.begin(), ts.end());
    ts.resize(std::distance(ts.begin(), rem));
    if (ts.size() < n) return true;

    int ct = 0, cs = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (s[i] > s[j]) ++cs;
            if (t[i] > t[j]) ++ct;
        }
    }
    return (cs&1) == (ct&1);
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        cout << (judge(s, t) ? "YES" : "NO") << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
