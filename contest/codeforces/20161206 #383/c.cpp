#include <bits/stdc++.h>
using namespace std;
const int N = 110;
typedef long long ll;

int a[N], b[N];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    memset(b, 0, sizeof b);
    ll z = 1, y;
    for(int i = 1; i <= n; ++i) {
        int x = a[i];
        if(b[x]) continue;
        y = 0;
        while(!b[x]) {
            b[x] = 1;
            x = a[x];
            ++y;
        }
        if(y % 2 == 0) y /= 2;
        z = z / __gcd(z, y) * y;
    }
    for(int i = 1; i <= n; ++i) if(!b[i]) {
        z = -1;
        break;
    }
    printf("%I64d\n", z);
    return 0;
}