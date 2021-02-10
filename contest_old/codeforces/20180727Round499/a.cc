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
    string s;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    unique(s.begin(), s.end());
    string tmp = "";
    for (int i = 0, f = 1; i < s.size(); ++i) {
        if (f) tmp += s[i], f = 0;
        else {
            if (s[i] - s[i-1] < 2) f = 1;
            else tmp += s[i];
        }
    } 
    int ans = 0;
    if (tmp.size() < k) {
        ans = -1;
    }
    else {
        for (int i = 0; i < k; ++i) ans += tmp[i] - 'a' + 1;
    }
    
    cout << ans << endl;
    
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
