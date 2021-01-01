#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define mp make_pair
#define ll long long
using namespace std;

const int N = 300300;

int s[N], e[N];
bool g[N];
pair<int, int > p[N];
int n, m;
ll t;

void print() {
    rep(i, 0, n) printf("(%d %d) -- (%d %d)\n", s[i], g[i], p[i].first, p[i].second);
}

int main()
{
    scanf("%d %d %I64d", &n, &m, &t);
    char c;
    rep(i, 0, n) {
        scanf("%d %c", s+i, &c); --s[i];
        g[i] = c == 'R';
        p[i] = mp(s[i], i);
    }
//print();
    ll shift = 0, v;
    rep(i, 0, n) {
        if(g[i]) {
            v = s[i] + t;
            e[i] = v % m;
            shift += (v - e[i]) / m;
        }
        else {
            v = s[i] - t;
            e[i] = (v % m + m) % m;
            shift += (v - e[i]) / m;
        }
        shift = (shift % n + n) % n;
//printf("%d %I64d %d %I64d\n", i, v, e[i], shift);
    }
    sort(p, p+n); //print();
    sort(e, e+n);
    rep(i, 0, n) s[p[i].second] = e[(i+shift)%n];
    rep(i, 0, n) printf("%d ", s[i]+1); puts("");
    return 0;
}
