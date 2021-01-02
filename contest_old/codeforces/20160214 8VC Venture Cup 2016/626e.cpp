#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

int n;
int a[N];

void solve() {
    if(n == 1 || n == 2) {
        printf("%d\n%d", n, a[0]);
        for(int i = 1; i < n; ++i) printf(" %d", a[i]); puts("");
        return ;
    }
    sort(a, a+n);
    int mid , mark ;
    double maxv = -1.0, s = a[0];
    int len = 0, le = 1;

    for(int i = 1; i < n; ++i) {
        len++; le += 2;
        s += a[i] + a[n-len];
        while(len > 0 && (a[i-len] + a[n-len]) / 2. <= s / le) {
            s -= a[i-len] + a[n-len];
            len--;
            le -= 2;
        }
        if(s / le - a[i] > maxv) {
            maxv = s / le - a[i];
            mark = len;
            mid = i;
        }
    }


    printf("%d\n%d", mark+mark+1, a[mid-mark]);
    for(int i = mid-mark+1; i <= mid; ++i) printf(" %d", a[i]);
    for(int i = n-mark; i < n; ++i) printf(" %d", a[i]); puts("");
}

int main()
{
#ifdef PIT
freopen("626e.in", "r", stdin);
#endif // PIT
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i) scanf("%d", a+i);
        solve();
    }
    return 0;
}
