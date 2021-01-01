#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define inf 0x3f3f3f3f
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;
const int N = 100100;
int x[N];
int n, k;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    rep(i, 0, n) cin >> x[i];
    sort(x, x+n);
    n = unique(x, x+n) - x;
    int left = 0, ans = 1, flag = 0;
    rep(i, 0, n) {
        if(!flag && x[i] - x[left] > k) {
            left = i-1; flag = 1;
        }
        if(flag && x[i] - x[left] > k) {
            left = i; flag = 0; ++ans;
        }
    }
    cout << ans;
    return 0;
}
