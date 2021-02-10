//
// coded by lp.z
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;


bool equal(vector<int > a, vector<int > b, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int solve(vector<int > a, vector<int > b, int n, int m) {
    if (equal(a, b, n)) return 0;

    int ans = m+1;
    for (int i = 0; i < n; ++i) {
        vector<int > c(n);
        int x = b[0] - a[i];
        for (int j = 0; j < n; ++j) c[j] = (a[j] + x + m) % m;
        sort(c.begin(), c.end());
        if (equal(c, b, n)) ans = min(ans, (x+m)%m);
    }
    return ans;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int > a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int x = solve(a, b, n, m);
    cout << x << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
