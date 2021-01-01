#include <iostream>
#include <cstdio>

using namespace std;

const int N = 50050;

int f[N];
int n, m, ans;

void make_set() {
    for(int i = 0; i <= n; ++i) f[i] = i;
    return ;
}

int find_set(int x) {
    if(x != f[x]) f[x] = find_set(f[x]);
    return f[x];
}

void union_set(int a, int b) {
    int x = find_set(a);
    int y = find_set(b);
    if(x != y) {
        f[y] = x;
    }
    return ;
}

int main()
{
    while(~scanf("%d %d", &n, &m)) {
        make_set();
        ans = 0;
        int d, a, b;
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &d, &a, &b);
            if(d == 2 && a == b) ++ans;
            else if(a > n || b > n) ++ans;
            else union_set(a, b);
        }
    }
    return 0;
}
