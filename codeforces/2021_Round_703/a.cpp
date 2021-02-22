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
        ll sum = 0;
        int f = 1;
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x;
            sum += x;
            if (sum < i * (i+1) / 2) { f = 0; }
        }
        if (f) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
