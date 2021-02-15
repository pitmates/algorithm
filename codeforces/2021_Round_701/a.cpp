#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int  mi = a+100;
        for (int i = (b == 1); i < 50; ++i) {
            int x = a, y = i, z = b + i;
            while (x) x /= z, ++y;
            mi = min(mi, y);
        }
        
        cout << mi << endl;
    }

    return 0;
}
