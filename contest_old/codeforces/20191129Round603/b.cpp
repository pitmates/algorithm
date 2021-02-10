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

inline bool cmp(pair<string, int > &a, pair<string, int > &b) {
    return a.second < b.second;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<string, int > > pin(n);
        unordered_map<char, int > show;
        for (int i = 0; i < n; ++i) {
            cin >> pin[i].first;
            pin[i].second = i;
            show[pin[i].first[0]] = 1;
        }
        sort(pin.begin(), pin.end());
        int now = 0;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (pin[i].first == pin[now].first) {
                for (int j = 0; j < 10; ++j) {
                    char c = j + '0';
                    if (show[c] == 1) continue;
                    show[c] = 1;
                    pin[i].first[0] = c;
                    ++ans;
                    break;
                }
            }
            else {
                now = i;
            }
        }
        cout << ans << endl;
        sort(pin.begin(), pin.end(), cmp);
        for (auto z : pin) cout << z.first << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
