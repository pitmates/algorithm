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
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n-1;
        while(l < n && s[l] == '0') ++l;
        while(r >= 0 && s[r] == '1') --r;
        if (l >= r) cout << "YES" << endl;
        else {
            int d1 = 0, id = -1;
            for (int i = l+1; i <= r; ++i) {
                if (s[i] == '1' && s[i-1] == '1') {
                    d1 = 1;
                    id = i;
                    break;
                }
            }
            if (d1 == 0) cout << "YES" << endl;
            else {
                d1 = 0;
                for (int i = id+1; i <= r; ++i) {
                    if (s[i] == '0' && s[i-1] == '0') {
                        d1 = 1;
                        break;
                    }
                }
                if (d1 == 1) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
            
        }
    }

    return 0;
}
