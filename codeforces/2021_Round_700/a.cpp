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
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i&1) {
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
            else {
                if (s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            }
        }
        cout << s << endl;
    }

    return 0;
}
