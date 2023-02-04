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
        int n, m;
        cin >> n >> m;
        if (m < n) cout << "NO" << endl;
        else {
            if (n % 2 == 1) {
                cout << "YES" << endl;
                for (int i = 0; i < n-1; ++i) cout << 1 << " ";
                cout << m - n + 1 << endl;
            }
            else {
                if (m&1) {
                    cout << "NO" << endl;
                }
                else {
                    cout << "YES" << endl;
                    for (int i = 0; i < n-2; ++i) cout << 1 << " ";
                    int x = (m - n + 2) / 2;
                    cout << x << " " << x << endl;
                }
            }
        }
    }

    return 0;
}