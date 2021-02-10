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

int a[N], d[N];
int n, k;



int tri_div() {
    if (n == 1) return a[0];
    int l = 0, r = k, d = a[r] - a[l];
    for (int i = r+1; i < n; ++i) {
        int d2 = a[i] - a[i-k];
        if (d2 < d) {
            d = d2; r = i; l = i-k;
        }
    }
    return (a[r] + a[l]) / 2;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; scanf("%d", &T);
    for (int ic = 1; ic <= T; ++ic) {
        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        int x = tri_div();
        printf("%d\n", x);
    }



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
