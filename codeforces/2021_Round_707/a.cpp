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
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<pii> ad(n+1, {0, 0});
        vector<int> tm(n+1);
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            ad[i] = {x, y};
        }
        for (int i = 1; i <= n; ++i) cin >> tm[i];
        int a = 0, d = 0;
        for (int i = 1; i <= n; ++i) {
            a = tm[i] + ad[i].first - ad[i-1].second + d;
            d = max(ad[i].second, a + (ad[i].second - ad[i].first + 1) / 2);
        }
        cout << a << endl;
    }

    return 0;
}
