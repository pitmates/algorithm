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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, r = n-1;
        int f = 0, z = 0;
        for (; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                s[r] = s[l];
                if (!z) f++, z = 1;
            }
            else {
                z = 0;
            }
        }
        if (f > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}