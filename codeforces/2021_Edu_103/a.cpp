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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (n > k) {
            if (n % k) cout << 2 << endl;
            else cout << 1 << endl;
        }
        else {
            int d = k / n, m = k % n;
            if (m == 0) cout << d << endl;
            else cout << d + 1 << endl;
        }

    }

    return 0;
}
