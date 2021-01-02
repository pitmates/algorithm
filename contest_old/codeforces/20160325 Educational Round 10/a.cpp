#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, h, v;
    scanf("%d %d %d %d", &h, &v, &a, &b);
    int s = v - h;
    if(a <= b) {
        if(s > a*8) puts("-1");
        else puts("0");
    }
    else {
        if(s <= a*8) puts("0");
        else {
            s = s - a*8 + b*12;
            int l = 1, r = 100000, m;
            int k = (a - b) * 12;
            while(l <= r) {
                m = l + r >> 1;
                if(1LL*m * k + b * 12 >= 1LL*s) r = m-1;
                else l = m+1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}
