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
        string a, b;
        cin >> a >> b;
        vector<int> c(30, 0);
        int cnt = 1;
        c[a[0] - 'a'] = 1;
        if (c[a[1] - 'a'] == 0)
            cnt++;
        c[a[1] - 'a']++;
        if (c[b[0] - 'a'] == 0)
            cnt++;
        c[b[0] - 'a']++;
        if (c[b[1] - 'a'] == 0)
            cnt++;
        c[b[1] - 'a']++;
        // for (int i = 0; i < 30; ++i)
        //     cout << c[i] << " ";
        // cout << endl;
        cout << cnt - 1 << endl;
    }

    return 0;
}