#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 1010;
int a[N], b[N], c[N];

inline int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    int k = 0;
    b[0] = c[0] = -1;
    rep(i, 1, n) {
        if(gcd(a[i-1], a[i]) == 1) continue;
        int x = a[i-1], y = a[i];
        if(x > y) swap(x, y);
        c[k] = i-1;
        b[k++] = 1;
    }
    printf("%d\n", k);
    int x = 0;
    rep(i, 0, n) {
        printf("%d ", a[i]);
        if(c[x] == i) printf("%d ", b[x++]);
    }
    puts("");
    return 0;
}
