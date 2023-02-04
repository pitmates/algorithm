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
        int n, k;
        cin >> n >> k;
        if (n % 3 == 0)  {
            int x = n / 3;
            cout << x << " " << x << " " << x << endl;
        }
        else {
            if (n % 2 == 0) {
                int x = n / 2;
                if (x & 1) cout << (x-1) << " " << (x-1) << " " << 2 << endl;
                else cout << x << " " << (x/2) << " " << (x/2) << endl;
            }
            else {
                cout << (n/2) << " " << (n/2) << " 1" << endl; 
            }
        }
    }

    return 0;
}
