#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 105;
int a[N];
bool g[N];
int n;

pair<int, int > p[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%d", &n);
    int t = 0;
    rep(i, 0, n) scanf("%d", a+i), t += a[i];
    t = t * 2 / n;
    memset(g, 0, sizeof g);
    int k = 0;
    rep(i, 0, n) {
        if(g[i]) continue;
        rep(j, i+1, n) {
            if(g[j]) continue;
            if(a[i] + a[j] == t) {
                p[k++] = mp(i, j);
                g[i] = g[j] = 1;
                break;
            }
        }
    }
    rep(i, 0, k) printf("%d %d\n", p[i].first+1, p[i].second+1);
    return 0;
}
