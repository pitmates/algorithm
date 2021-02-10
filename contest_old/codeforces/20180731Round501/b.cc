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
    string s, t;
    cin >> n;
    cin >> s >> t;
    string st = s, tt = t;
    sort(st.begin(), st.end());
    sort(tt.begin(), tt.end());
    if (st != tt) {
        cout << -1 << endl;
    }
    else {
        vector<int > v;
        v.clear();
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == t[i]) {
                    int k = j-1;
                    while(k >= i) {
                        v.push_back(k);
                        swap(s[k], s[k+1]);
                        --k;
                    }
                    break;
                }
            }
        }
        cout << v.size() << endl;
        for (auto x : v) cout << x+1 << " ";
        cout << endl;
    }
    
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
