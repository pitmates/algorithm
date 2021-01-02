#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
using namespace std;
const int N = 1010;

struct P{
    int x, y;
    P(int x = 0, int y = 0) : x(x), y(y) {}
    void in() {scanf("%d %d", &x, &y);}
    P operator-(const P& a) {return P(x-a.x, y-a.y);}
    int cross(const P& a) {return x*a.y - y*a.x;}
}p[N];

int n, m;

int main()
{
    scanf("%d", &n);
    rep(i, 0, n) p[i].in();
    m = 0;
    rep(i, 2, n) {
        int z = (p[i-1]-p[i-2]).cross(p[i]-p[i-1]);
        if(z > 0) ++m;
    }
    printf("%d\n", m);
    return 0;
}
