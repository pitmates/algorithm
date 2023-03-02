#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

bool sortedEqual(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

void solve(int n, int k, string s, string t) {
    if (!sortedEqual(s, t)) {
        cout << "NO" << endl;
        return ;
    }
    if (k + k <= n) {
        cout << "YES" << endl;
        return ;
    }
    int l = max(0, n - k), r = min(n-1, k-1);
    // cout << l << " " << r << endl;
    string sm = s.substr(l, r-l+1), tm = t.substr(l, r-l+1);
    if (sm == tm) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        solve(n, k, s, t);
    }

    return 0;
}

/*
1
13 8
abcabcabcabca
caacbcababcab
*/