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
        string b, r;
        cin >> b >> r;
        int flag = 0;
        for (int i = 1; i < n; ++i) {
            if (b[i] == b[i-1]) ++flag;
        }
        for (int i = 1; i < m; ++i) {
            if (r[i] == r[i-1]) ++flag;
        }
        if (flag > 1) cout << "NO" << endl;
        else if (flag == 0) cout << "YES" << endl;
        else cout << (b[n-1] != r[m-1] ? "YES" : "NO") << endl;
    }

    return 0;
}