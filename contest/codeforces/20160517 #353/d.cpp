#include <bits/stdc++.h>

#define rep(i,j,k) for(int i = (int) j; i < (int) k; ++i)
#define mp make_pair
#define ll long long
using namespace std;

const int N = 100100;

struct P{
    int l, r;
    int v;
    int id;
    void in(int i) { scanf("%d", &v); id = i; }
}p[N], q[N];

inline bool cmp(P a, P b) {return a.v < b.v;}

int n;

vector<int > vec;

int qfind(int z) {
    int l = 0, r = n, m;
    while(l <= r) {
        m = l + r >> 1;
        if(q[m].v > z) r = m - 1;
        else if(q[m].v == z) break;
        else l = m + 1;
    }
    return q[m].id;
}

int main()
{
#ifdef PIT
freopen("d.in", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT

    scanf("%d", &n);
    rep(i, 0, n) p[i].in(i), p[i].l = p[i].r = 0;
    rep(i, 0, n) q[i] = p[i];
    sort(q, q+n, cmp);
    vec.clear();
    vec.push_back(p[0].v);
    rep(i, 1, n) {
//printf("%d =  %d: ", p[i].v, vec.size());
//rep(j,0,vec.size()) printf("%d ", vec[j]); puts("");
        if(p[i].v < vec[0]) {
            int y = qfind(vec[0]);
            p[y].l = p[i].v;
            printf("%d ", vec[0]);
            vec.insert(vec.begin(), p[i].v);
        }
        else if(p[i].v > vec[vec.size()-1]) {
            int y = qfind(vec[vec.size()-1]);
            p[y].r = p[i].v;
            printf("%d ", vec[vec.size()-1]);
            vec.push_back(p[i].v);
        }
        else {
            int x = lower_bound(vec.begin(), vec.end(), p[i].v) - vec.begin();
            int y = qfind(vec[x-1]), z = qfind(vec[x]);
            if(p[y].r == 0) {
                p[y].r = p[i].v;
                printf("%d ", vec[x-1]);
            }
            else {
                p[z].l = p[i].v;
                printf("%d ", vec[x]);
            }
            vec.insert(vec.begin()+x, p[i].v);
        }

    }
    puts("");
    return 0;
}
