#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int)k; ++i)
using namespace std;
const int N = 100100;

int a[N];
int z[N], r;
int n, po;


int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> po;
    rep(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);
    int i = 0; r = 0;
    while(++i) {
        if(po < i) break;
        int x = lower_bound(a+1, a+1+n, i) - a;
        if(a[x] == i) continue;
        po -= i; z[r++] = i;
    }
    printf("%d\n", r);
    rep(i, 0, r-1) printf("%d ", z[i]); puts("");
    return 0;
}
