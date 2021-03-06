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
    for (int ic = 1; ic <= T; ++ic) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        if (n < 11) {
            cout << "NO" << endl;
            continue;
        }

        int f = 0;
        for (int i = 0; i < n-10; ++i) {
            if (s[i] == '8') {
                f = 1;
                break;
            }
        }

        if (f == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
