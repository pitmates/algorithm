#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 30030;

int parent[N];
int num[N];
int n, m;

void makeset() {
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
        num[i] = 1;
    }
    return ;
}

int findset(int x) {
    if(x != parent[x]) parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y) {
    int a = findset(x);
    int b = findset(y);
    if(a != b) {
        parent[b] = a;
        num[a] += num[b];
    }
    return ;
}

int main()
{
    while(scanf("%d %d", &n, &m), n || m) {
        makeset();
        for(int i = 0, t, a; i < m; ++i) {
            scanf("%d %d", &t, &a);
            for(int j = 1, b; j < t; ++j) {
                scanf("%d", &b);
                unionset(a, b);
            }
//            for(int j = 0; j < n; ++j) printf("%d ", num[j]); puts("");
//            for(int j = 0; j < n; ++j) printf("%d ", parent[j]); puts("");

        }
        printf("%d\n", num[findset(0)]);
    }
    return 0;
}

/**
4 3
2 1 2
2 1 0
2 3 2
**/
