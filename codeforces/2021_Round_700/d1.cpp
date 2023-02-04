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
    ios_base::sync_with_stdio(false); cin.tie(0);

    // int T; cin >> T;
    // while (T--) {
    int n; cin >> n;
    vector<int> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int t = 0, now = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i-1]) {
            if (now > 1) t += 2;
            else if (now == 1) t += 1;
            now = 1;
        }
        else now ++;
    }
    if (now > 1) t += 2;
    else if (now == 1) t += 1;
    cout << t << endl;

    return 0;
}
