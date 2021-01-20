#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


int main()
{
// freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n+2, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> pre(n+2, 0), suf(n+2, 0);
        
        for (int i = 1; i <= n; ++i) {
            if (pre[i-1] == -1) pre[i] = -1;
            else if (pre[i-1] > a[i]) pre[i] = -1;
            else pre[i] = a[i] - pre[i-1];
        }

        for (int i = n; i ; --i) {
            if (suf[i+1] == -1) suf[i] = -1;
            else if (a[i] < suf[i+1]) suf[i] = -1;
            else suf[i] = a[i] - suf[i+1];
        }

        int f = 0;
        if (pre[n] == 0) f = 1;
        for (int i = 1; i < n; ++i) {
            if (pre[i-1] == -1 || suf[i+2] == -1) continue;
            int l = a[i+1] - pre[i-1], r = a[i] - suf[i+2];
            if (l < 0 || r < 0) continue;
            if (l == r) {
                f = 1;
                break;
            }

        }
        
        if (!f)  cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
