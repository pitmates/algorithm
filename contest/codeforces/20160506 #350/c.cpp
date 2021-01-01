#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5+5;

pair<int, int > sci[N]; //f:lan, s:num
pair<int, int > cam[N]; //f:a_la, s:s_lan
int ts;
int n, m;
int sc[N];

int binsearch(int lan) {
    int l = 0, r = ts, mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(sci[mid].first > lan) r = mid - 1;
        else if(sci[mid].first == lan) return mid;
        else l = mid + 1;
    }
    return mid;
}

void pt(pair<int, int > s[], int le) {
    rep(i, 0, le) {
        printf("(%d %d)\n", s[i].first, s[i].second);
    }
}

void solve() {
    sort(sci, sci+ts);
//pt(sci, ts);
    int x = 0, y = 0, z = 0, id;
    int sati = 0, plea = 0;
    rep(i, 0, m) {
        id = binsearch(cam[i].first);
        if(sci[id].first == cam[i].first) x = sci[id].second;
        id = binsearch(cam[i].second);
        if(sci[id].first == cam[i].second) y = sci[id].second;
        if(plea < x || (plea == x && sati < y)) {
            plea = x;
            sati = y;
            z = i;
        }
//        printf("i:%d x:%d y:%d === plea:%d sati:%d z:%d\n", i, x, y, plea, sati, z);
        x = y = 0;
    }
    printf("%d\n", z+1);
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT

    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", sc+i);
    sort(sc, sc+n);
    ts = 0;
    sc[n] = inf;
    int v = 1;
    rep(i, 1, n+1) {
        if(sc[i] == sc[i-1]) ++v;
        else {
            sci[ts++] = mp( sc[i-1], v);
            v = 1;
        }
    }
    scanf("%d", &m);
    int x;
    rep(i, 0, m)  {
        scanf("%d", &x);
        cam[i].first = x;
    }
    rep(i, 0, m) {
        scanf("%d", &x);
        cam[i].second = x;
    }
    solve();
    return 0;
}
