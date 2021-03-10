#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

double sqr(int x, int y) {
    return sqrt(1.0*x*x + 1.0*y*y);
}

int main()
{
//freopen("a.in", "r", stdin);
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; 
        scanf("%d", &n);
        vector<int> X(n), Y(n);
        int tx = 0, ty = 0;
        for (int i = 0; i < n+n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == 0) {
                Y[ty++] = abs(y);
            }
            else {
                X[tx++] = abs(x);
            }
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        double res = 0.0;
        for (int i = 0; i < n; ++i) {
            double now = sqr(X[i], Y[i]);
            res += now;
        }
        printf("%.18lf\n", res);
    }

    return 0;
}
