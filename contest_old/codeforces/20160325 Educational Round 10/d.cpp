#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int b[N], ans[N];
int l[N], r[N];
int id[N];
int n;

inline bool cp1(int i, int j) { return r[i] < r[j];}
inline bool cp2(int i, int j) { return l[i] > l[j];}

inline void update(int x) {
    for( ; x <= n; x += x&-x) ++b[x];
    return ;
}

inline int query(int x) {
    int res = 0;
    for( ; x; x -= x&-x) res += b[x];
    return res;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", l+i, r+i);
        id[i] = i;
    }
    sort(id, id+n, cp1);
    for(int i = 0; i < n; ++i) r[id[i]] = i+1;
    sort(id, id+n, cp2);
    for(int i = 0; i < n; ++i) ans[id[i]] = query(r[id[i]]), update(r[id[i]]);
    for(int i = 0; i < n; ++i) printf("%d\n", ans[i]);
    return 0;
}
