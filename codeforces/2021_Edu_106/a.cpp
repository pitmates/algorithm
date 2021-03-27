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
    while (T--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int wc = k1 + k2, bc = n + n - wc;
        int w, b;
        cin >> w >> b;
        if (wc / 2 >= w && bc / 2 >= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
