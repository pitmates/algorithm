#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 200200;
const int inf = 0x3f3f3f3f;
int p[N];
int n;
char c[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%d", &n);
    scanf("%s", c);
    rep(i, 0, n) scanf("%d", p+i);
    bool flag = 0;
    int mi = inf, v;
    int po;
    rep(i, 0, n) {
        if(!flag) {
            if(c[i] == 'L') continue;
            else {
                flag = 1;
                po = p[i];
            }
        }
        else {
            if(c[i] == 'R') po = p[i];
            else {
                flag = 0;
                v = (p[i] - po) / 2;
                mi = min(mi, v);
            }
        }
    }
    if(mi == inf) puts("-1");
    else printf("%d\n", mi);
    return 0;
}
