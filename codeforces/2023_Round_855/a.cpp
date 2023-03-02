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
        string t = "";
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
            if (!i || s[i] != t[k-1]) t += s[i], k++;
        }

        if (t != "meow") cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}