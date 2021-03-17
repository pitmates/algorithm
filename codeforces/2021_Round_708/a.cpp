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
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(101, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[a[i]]++;
        }
        vector<int> c(n);
        int t = 0;
        while (t < n) {
            for (int i = 0; i < 101; ++i) {
                if (!b[i])  continue;
                c[t++] = i;
                b[i]--;
            }
        }
        for (int i = 0; i < n; ++i) cout << c[i] << " "; cout << endl;
        
    }

    return 0;
}
