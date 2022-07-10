#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

bool judge() {
    int n, t, x, d = 0;
    cin >> n;
    cin >> t;
    if (n == 1) return true;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        d += x - t - 1;
        t = x;
    }
    return d < 3;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        if (judge()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
