#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;
    int c = b > 0 ? 1 : -1;
    int d = abs(b);
    for(int i = 0; i < d; ++i) {
        a += c;
        if(a > n) a = 1;
        if(a < 1) a = n;
    }
    printf("%d\n", a);
    return 0;
}
