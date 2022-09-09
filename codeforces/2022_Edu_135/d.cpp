#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll M = 1e9+7;

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n-1;
        while (l < r) {
            if (s[l] == s[r]) ++l, --r;
            else break;
        }

        bool draw = 1;
        for (int i = l; i < r; i += 2) {
            draw &= (s[i] == s[i+1]);
        }

        cout << (draw ? "Draw" : "Alice") << endl;
    }
    

    return 0;
}