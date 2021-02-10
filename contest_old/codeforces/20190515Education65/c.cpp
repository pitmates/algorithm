//
// Created by pitmates on 2018/11/23.
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

const int N = 512345;

int fa[N];
int n, m;


int find_set(int x) {
    if (fa[x] == x) return x;
    fa[x] = find_set(fa[x]);
    return fa[x];
}

void union_set(int x, int y) {
    int xx = find_set(x);
    int yy = find_set(y);
    if (xx != yy) fa[yy] = xx;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; ++i) fa[i] = i;

    for (int ic = 0; ic < m; ++ic) {
        int k, x, y;
        cin >> k;
        if (k == 0) continue;
        if (k == 1) {
            cin >> x;
            continue;
        }
        cin >> x;
        for (int i = 1; i < k; ++i) {
            cin >> y;
            union_set(x, y);
        }
    }

    for (int i = 1; i <= n; ++i) fa[i] = find_set(i);
    map<int, int > mpp;
    for (int i = 1; i <= n; ++i) {
        mpp[fa[i]] ++;
    }
    for (int i = 1; i <= n; ++i) {
        cout << mpp[fa[i]] << " ";
    }
    cout << endl;

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
