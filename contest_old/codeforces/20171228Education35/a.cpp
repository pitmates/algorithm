//
// Created by pitmates on 2017/12/28.
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
const int mo = 1e9+7;
const int N = 1234567;

int a[N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int minv = inf, l = -1;
    for (int i = 0; i < n; ++i) if (a[i] < minv) minv = a[i], l = i;
    int d = inf;
    for (int i = l+1; i < n; ++i) {
        if (a[i] == minv) {
            d = min (d, i - l);
            l = i;
        }
    }
    cout << d << endl;

#ifdef PIT
    flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
