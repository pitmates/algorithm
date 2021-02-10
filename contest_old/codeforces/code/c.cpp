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

bool is_beauty(string s, int n, int k) {
    for (int i = 0; i + k < n; ++i) {
        if (s[i] == s[i+k]) continue;
        return false;
    }
    return true;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    if (is_beauty(s, n, k)) cout << n << endl << s << endl;
    else {
        string ans = s;
        for (int i = 0; i + k < n; ++i) ans[i+k] = ans[i];
        if (ans >= s) cout << n << endl << ans << endl;
        else {
            int id = k-1;
            while (id >= 0) {
                if (ans[id] == '9') ans[id] = '0', --id;
                else break;
            }
            ans[id] = ans[id] - '0' + 1 + '0';
            for (int i = 0; i + k < n; ++i) ans[i+k] = ans[i];
            cout << n << endl << ans << endl;
        }

    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
