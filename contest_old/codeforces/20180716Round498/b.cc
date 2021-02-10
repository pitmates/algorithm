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

const int N = 2345;

int n, k;
pii a[N];

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    reverse(a, a+n);
    if (k == 1) {
        cout << a[0].first << endl << n << endl;
    }
    else {
        vector<int > b(k+1, 0);
        int ans = 0;
        for (int i = 1; i <= k; ++i) ans += a[i-1].first, b[i] = a[i-1].second;
        sort(b.begin(), b.end());
        b[0] = -1;
        cout << ans << endl;
        // rep(i, 0, k+1) cout << b[i] << " "; cout << endl;
        for (int i = 1; i < k; ++i) {
            cout << b[i] - b[i-1] << " ";
        }
        cout << n-1 - b[k-1];
        cout << endl;
    }


    
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
