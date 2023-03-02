#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const int M = 998244353;

int main()
{
// freopen("./io/a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<int> pq;
        if (!pq.empty()) pq.pop();
        ll ans = 0;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (x == 0) {
                if (pq.empty()) continue;
                ans += pq.top();
                pq.pop();
            }
            else {
                pq.push(x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
