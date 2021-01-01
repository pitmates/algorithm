#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define SZ(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 1<<20;

struct node{
    int l, r, id;
}Q[N];

int pos[N];
bool cmp(node a, node b) {
    if(pos[a.l] == pos[b.l]) return a.r < b.r;
    return pos[a.l] < pos[b.l];
}

ll ans[N], flag[N];
int pre[N];
int L = 1, R = 0;
ll Ans = 0;
int n, m, k;

void add(int x) {
    Ans += flag[pre[x]^k];
    flag[pre[x]]++;
}
void del(int x) {
    flag[pre[x]]--;
    Ans -= flag[pre[x]^k];
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    int sz = sqrt(n);
    rep(i, 1, n+1) {
        cin >> pre[i];
        pre[i] = pre[i] ^ pre[i-1];
        pos[i] = i / sz;
    }
    rep(i, 1, m+1) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q+1, Q+1+m, cmp);
    flag[0] = 1;
    rep(i, 1, m+1) {
        while(L < Q[i].l) { del(L-1); L++; }
        while(L > Q[i].l) { L--; add(L-1); }
        while(R < Q[i].r) { R++; add(R);   }
        while(R > Q[i].r) { del(R); R--;   }
        ans[Q[i].id] = Ans;
    }
    rep(i, 1, m+1) cout << ans[i] << endl;
    return 0;
}
