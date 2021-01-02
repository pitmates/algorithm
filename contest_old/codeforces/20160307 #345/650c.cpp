#include <bits/stdc++.h>

using namespace std;

inline int read() {
    char c; bool f = 0; int s = 0;
    while(c = getchar(), c < '0'|| c > '9') if(c == '-') f = 1;
    s = c - '0';
    while(c = getchar(), c >= '0' && c <= '9') s = s * 10 + c - '0';
    return f ? -s : s;
}

const int N = 1000100;
int f[N];
int Hx[N], Hy[N];
int X[N], Y[N];
int ans[N];

pair<int, pair<int, int> > A[N];

int find_set(int x) {return x == f[x] ? x : f[x] = find_set(f[x]);}

int union_set(int x, int y) {
    x = find_set(x), y = find_set(y);
    if(x != y) f[x] = y;
}

int main()
{
    int n, m;
    n = read(); m = read();
    int M = n*m;
    for(int i = 0; i < M; ++i) {
        A[i].first = read();
        A[i].second = make_pair(i/m, i%m);
        f[i] = i;
    }
    sort(A, A+M);
    int j = -1;
    for(int i = 0; i < M; ++i) {
        if(i < M-1 && A[i].first == A[i+1].first) continue;
        for(int k = j+1; k <= i; ++k) {
            int x = A[k].second.first, y = A[k].second.second;
            int p = x*m + y;
            Hx[x] = Hy[y] = p;
        }
        for(int k = j+1; k <= i; ++k) {
            int x = A[k].second.first, y = A[k].second.second;
            int p = x*m + y;
            union_set(Hx[x], p); union_set(Hy[y], p);
        }
        for(int k = j+1; k <= i; ++k) {
            int x = A[k].second.first, y = A[k].second.second;
            int p = x*m + y;
            int pp = find_set(p);
            ans[pp] = max(ans[pp], max(X[x], Y[y])+1);
        }
        for(int k = j+1; k <= i; ++k) {
            int x = A[k].second.first, y = A[k].second.second;
            int p = x*m + y;
            X[x] = max(X[x], ans[find_set(p)]);
            Y[y] = max(Y[y], ans[find_set(p)]);
        }
        j = i;
    }
    for(int i = 0; i < M; ++i) {
        printf("%d ", ans[find_set(i)]);
        if(i % m == m-1) puts("");
    }
    return 0;
}
