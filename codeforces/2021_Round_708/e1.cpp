#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


int simple(int x) {
    int y = 1;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int t = 0;
            while (x % i == 0) {
                x /= i;
                ++t;
            }
            if (t&1) y *= i;
        }
    }
    return y * x;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a[i] = simple(x);
        }
        map<int, int> m;
        m.clear();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (m[a[i]] > 0) {
                ++ans;
                m.clear();
                m[a[i]] = 1;
            }
            else {
                m[a[i]] = 1;
            }
        }
        cout << (ans + 1) << endl;
    }

    return 0;
}
