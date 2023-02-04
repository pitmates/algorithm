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
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        int f = 1;
        for (int i = 0; i < n && f; ++i) {
            f &= (a[i] <= b[i]);
            int nxt = (i+1) % n;
            if (a[i] < b[i]) f &= (b[i] - 1 <= b[nxt]);
        }

        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}