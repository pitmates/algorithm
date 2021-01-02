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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int g, t;
    rep(i, 0, n) {
        if(s[i] == 'G') g = i;
        if(s[i] == 'T') t = i;
    }
    if(t < g) k = -k;
    bool f = 0;
    while(1) {
        if(g >= n || g < 0) break;
        g += k;
        if(s[g] == '#') break;
        if(g == t) {f = 1; break; }
    }
    if(f) cout << "YES";
    else cout << "NO";
    return 0;
}
