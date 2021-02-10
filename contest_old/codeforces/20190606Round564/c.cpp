//
// coded by zhuangliupeng
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

const int N = 212345;
int a[N], b[N];
int n;


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    int x;
    zero(a);
    for (int i = 1; i <= n; ++i)  {
        cin >> x;
        a[x] = 0;
    }
    int z = -inf, d = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        x = b[i];
        a[x] = i;
    }

    int f = 0;
    if (a[1]) {
        for (int i = a[1]; i <= n; ++i) {
            if (b[i] == 1 + i - a[1]) continue;
            else {
                f = 1;
                break;
            }
        }
    }
//    int m = n;
//    if (f == 1) m = a[1] - 1;
    if (f == 1) {
        for (int i = 1; i <= n; ++i) if(a[i]) {
            int y = a[i] - i;
            if (y > z) {
                z = y;
                d = i;
            }
        }
        cout << n + max(0, a[d]-d+1) << endl;
    }
    else {
        for (int i = 1; i <= n; ++i) if(a[i]) {
                int y = a[i] - i;
                if (y > z) {
                    z = y;
                    d = i;
                }
            }
        int p = n-a[1] + 2, l = 1, fl = 0;
        for (int i = p; i <= n; ++i) {
            if (a[i] == 0) {
                a[b[l]] = 0;
                l++;
            }
            else {
                fl = 1;
                break;
            }
        }
        if (fl) cout << n + max(0, a[d]-d+1) << endl;
        else cout << n-a[1]+n-1 << endl;
    }





#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
