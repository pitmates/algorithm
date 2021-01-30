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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        s = " " + s;
        vector<int> pre(n+3, 0), suf(n+3, 0);
        pre[2] = s[1] == 'L';
        for (int i = 3; i <= n+1; ++i) {
            if (s[i-2] == 'R' && s[i-1] == 'L') pre[i] = pre[i-2] + 2;
            else if (s[i-1] == 'L') pre[i] = 1;
        }
        suf[n] = s[n] == 'R';
        for (int i = n-1; i ; --i) {
            if (s[i] == 'R' && s[i+1] == 'L') suf[i] = suf[i+2] + 2;
            else if (s[i] == 'R') suf[i] = 1;
        }
        // for (int i = 0; i <= n+1; ++i) cout << pre[i] << " "; cout << endl;
        // for (int i = 0; i <= n+1; ++i) cout << suf[i] << " "; cout << endl;
        
        for (int i = 1; i <= n+1; ++i) {
            cout << (1 + pre[i] + suf[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}
