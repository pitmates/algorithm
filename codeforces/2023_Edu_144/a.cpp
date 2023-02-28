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
        string t = "FBFFBFFBFBFFBFFBFBFFBFFB";
        int m = t.size(), f =  0;
        for (int i = 0; i < m-n; ++i) {
            string ti = t.substr(i, n);
            if (ti == s) {
                f = 1;
                break;
            }
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}