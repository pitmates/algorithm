#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define PB push_back
#define zero(x) memset((x), 0, sizeof (x))

using namespace std;

const int N = 100100;
int n, m;
int d[N], a[N];
vector<int > v[N];

bool solve(int y) {
    int u[N];
    memset(u, 0, sizeof u);
//printf("------ mid == %d ++++\n", y);
    rep(x, 1, m+1) {
//rep(q, 0, v[x].size()) printf("(%d %d) ", q, v[x][q]);
        if(v[x].empty()) return false;
        int i = lower_bound(v[x].begin(), v[x].end(), y) - v[x].begin();
        int z = v[x][i];
//printf("i:%d z:%d >> ", i, z);
        if(z != y) {
            if(i == 0) {
//                    puts("");
                    return false;
            }
            else z = v[x][i-1];
        }
//printf("i:%d  z:%d\n", i, z);
        u[z] = a[x] + 1;
    }
//rep(i, 1, n) printf("i:%d  ui:%d\n", i, u[i]);
    int s = 0;
    rep(i, 1, y+1) {
        s += u[i];
//printf("i:%d  u[i]:%d  s:%d\n", i, u[i], s);
        if(s > i) return false;
    }
    return true;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 1, n+1) cin >> d[i], v[d[i]].PB(i);
    rep(i, 1, m+1) cin >> a[i];
    int l = 0, r = n, mid;
    while(l + 1 != r) {
        mid = l + r >> 1;
        if(solve(mid)) r = mid;
        else l = mid;
    }
    if(r == n && !solve(r)) cout << "-1";
    else cout << r;

    return 0;
}
