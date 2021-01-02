#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define mp make_pair
using namespace std;

const int N = 250250;
int f[N];
char s[N/250];
bool rd[N];
int n, m;
int q;
pair<int, int > p[N];
int t, b;

inline int code(int x, int y) { return x * m + y; }

inline pair<int, int > decode(int x) {return mp(x/m, x%m);}


inline void makeset() {
    for(int i = 0; i < n*m; ++i) f[i] = i;
    f[n*m] = n*m; f[n*m+1] = n*m+1;
    return ;
}

int findset(int x) {
    if(f[x] == x) return x;
    f[x] = findset(f[x]);
    return f[x];
}

void unionset(int x, int y) {
    x = findset(x), y = findset(y);
    if(x != y) f[y] = x;
}

void solve() {
    makeset();
    int nm = n*m;
    for(int i = 0; i < m; ++i) {
        if(!rd[i]) f[findset(i)] = f[nm];
        if(!rd[nm-i-1]) f[findset(nm-i-1)] = f[nm+1];
    }

    for(int i = m; i < nm; ++i) {
        if(rd[i]) continue;
        if(!rd[i-m]) unionset(i-m, i);
        if(i%m && !rd[i-1]) unionset(i-1, i);
    }
    if(findset(nm) == findset(nm+1)) {
        puts("-1");
        return ;
    }
    int w = q, flag = 0;
    for(int i = q-1; i >= 0; --i) {
        int z = code(p[i].first, p[i].second);
        rd[z] = 0;
        if(z-m < 0) unionset(nm, z);
        if(z+m >= nm) unionset(nm+1, z);
        if(z-m >= 0 && !rd[z-m]) unionset(z-m, z);
        if(z+m < nm && !rd[z+m]) unionset(z+m, z);
        if(z%m && !rd[z-1]) unionset(z-1, z);
        if(z%m != m-1 && !rd[z+1]) unionset(z+1, z);
        if(findset(nm) == findset(nm+1)) {
            w = i; flag = 1;
            break;
        }
    }
    printf("%d\n", flag ? w+1 : 0);
}

int main()
{
#ifdef PIT
freopen("1003.in", "r", stdin);
#endif // PIT
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        t = b = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            for(int j = 0; j < m; ++j){
                rd[t++] = s[j] == '1' ;
            }
        }
        int x, y;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i) {
            scanf("%d %d", &x, &y);
            p[i] = mp(x, y);
            int z = code(x, y);
            rd[z] = 1;
        }
        solve();
    }
    return 0;
}
