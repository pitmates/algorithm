#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1010;
int a[N];
int n;

void solve() {
    if(n == 1) {
        printf("%d\n", a[1]);
        return ;
    }
    sort(a+1, a+n+1);
    int m = (n+1) / 2;
    int k = n - m - 1;
    printf("%d %d", a[1], a[m+1]);
    for(int i = 2; i <= m; ++i, --k) {
        printf(" %d", a[i]);
        if(k) printf(" %d", a[m+i]);
    }
    puts("");
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        solve();
    }
    return 0;
}
