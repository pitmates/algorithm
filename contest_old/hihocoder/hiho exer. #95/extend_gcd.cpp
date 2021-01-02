#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int s1, s2, v1, v2, m;

inline int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

void ex_gcd(int a, int b, int& x, int& y) {
    if(a % b == 0) return ;
    ex_gcd(b, a%b, x, y);
    int t = x;
    x = y; y = t - a / b * y;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2 >> v1 >> v2 >> m;
    int a = v1 - v2, b = m, c = s2 - s1;
    if(a < 0) a += m;

    int d = gcd(a, b);
    if(c % d) puts("-1");
    else {
        a /= d, b /= d, c /= d;
        int x = 0, y = 1;
        ex_gcd(a, b, x, y);
        x = (int) (1LL*x*c % b); // *c  À©´óc±¶
        while(x < 0) x += b;
        printf("%d\n", x);
    }
    return 0;
}
