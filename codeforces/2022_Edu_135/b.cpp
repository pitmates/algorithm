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
        vector<int> a(n+1), b(n+1, 1);
        if (n&1) {
            b[n] = b[n-2] = b[1] = 0;
            a[n] = n; a[n-1] = n-2; a[n-2] = 1;
            for (int i = n, t = 1; i; --i) {
                if (b[i]) a[t++] = i, b[i] = 0; 
            }
        }
        else {
            a[n] = n; a[n-1] = n-1;
            for (int i = n-2, t = 1; i; --i) a[t++] = i;
        }
        
        for (int i = 1; i <= n; ++i) cout << a[i] << " "; cout << endl;
    }

    return 0;
}