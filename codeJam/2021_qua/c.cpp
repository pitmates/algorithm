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
    for (int icase = 1; icase <= T; ++icase) {
        cout << "Case #" << icase << ": ";
        int n, c; 
        cin >> n >> c;
        int minT = n-1, maxT = (1 + n) * n / 2;
        if (c < minT || c > maxT) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int t = 0;
        while (true) {
            int x = n - t + n - 1 - t;
            if (c <= t) {
                break;
            }
            
            c -= t;
        }

         
    }

    return 0;
}
