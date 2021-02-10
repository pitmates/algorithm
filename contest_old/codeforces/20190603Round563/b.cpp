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

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int > a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int f = 0;
    for (int i = 1; i < n; ++i) {
        int y = a[0] + a[i];
        if (y & 1) {
            f = 1;
            break;
        }
    }
    if (f == 1) sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
