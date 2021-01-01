#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const double eps = 1e-8;

inline int sig(double x) {return (x > eps) - (x < -eps);}

double a[4];
int t;
bool flag;

void dfs(double x, double y, int d) {
    if(flag) return ;
    if(d == 3) {
        if(!sig(x+y-24) || !sig(x-y-24) || !sig(y-x-24) || !sig(x*y-24)) flag = 1;
        else if(sig(x) && !sig(y/x-24)) flag = 1;
        else if(sig(y) && !sig(x/y-24)) flag = 1;
        return ;
    }
    // front
    dfs(x+y, a[d+1], d+1);
    dfs(x-y, a[d+1], d+1);
    dfs(y-x, a[d+1], d+1);
    dfs(x*y, a[d+1], d+1);
    if(sig(y)) dfs(x/y, a[d+1], d+1);
    if(sig(x)) dfs(y/x, a[d+1], d+1);
    // behind
    dfs(x, y+a[d+1], d+1);
    dfs(x, y-a[d+1], d+1);
    dfs(x, y*a[d+1], d+1);
    dfs(x, a[d+1]-y, d+1);
    if(sig(a[d+1])) dfs(x, y/a[d+1], d+1);
    if(sig(y)) dfs(x, a[d+1]/y, d+1);
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    for(scanf("%d", &t); t; --t) {
        rep(i, 0, 4) scanf("%lf", a+i);
        flag = 0;
        sort(a, a+4);
        do {
            dfs(a[0], a[1], 1);
        } while(next_permutation(a, a+4) && !flag);
        puts((flag) ? "Yes" : "No");
    }
    return 0;
}
