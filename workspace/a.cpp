#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


bool judge(string s) {
    int n = s.size();
    int t = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            if (t < 2) return false;
            t = 1;
        }
        else t = t + s[i];
    }
    if (t < 2) return false;
    return true;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (judge(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
