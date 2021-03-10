#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

bool isGood(int n, int k, string s) {
    if (k + k >= n) return false;
    int l = 0, r = n-1;
    while (l < r) {
        if (s[l] == s[r]) {
            ++l; --r;
        }
        else break;
    }
    // cout << "l = " << l << endl;
    return l >= k;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (isGood(n, k, s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
