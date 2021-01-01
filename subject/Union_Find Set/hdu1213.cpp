#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;

int father[N];
int n, m;

void make_set() {
    for(int i = 1; i <= n; ++i) father[i] = i;
    return ;
}

int find_set(int x) {
    if(x != father[x]) father[x] = find_set(father[x]);
    return father[x];
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x != y) father[y] = x;
    return ;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        make_set();
        while(m--) {
            int x, y;
            scanf("%d %d", &x, &y);
            union_set(x, y);
        }
        int num = 0;
        for(int i = 1; i <= n; ++i) if(father[i] == i) num++;
        printf("%d\n", num);
    }
    return 0;
}
