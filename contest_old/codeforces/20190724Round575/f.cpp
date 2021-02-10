//
// coded by zhuangliupeng
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

struct P{
    int x, y;
    ll w;

    P(int x=0, int y=0, ll w=0): x(x), y(y), w(w) {}
    bool operator < (const P& a) const {
        return  w < a.w;
    }
    void in() {
        cin >> x >> y >> w;
    }
    void out(int i) {
        cout << i << ": " << x << " " << y << " " << w << endl;
    }
};


void warshall(int n, vector<P > p, int k) {
    vector<int > vertice; vertice.clear();
    for (auto z : p) {
        vertice.push_back(z.x);
        vertice.push_back(z.y);
    }
    sort(vertice.begin(), vertice.end());
    vector<int >::iterator it = unique(vertice.begin(), vertice.end());
    vertice.resize(distance(vertice.begin(), it));

    n = vertice.size();

//    cout << "n -: " << n << endl;
//    for (auto x : vertice) cout << x << " "; cout << endl;

    vector<vector<ll > > d(n, vector<ll > (n, INF));
    for (auto z : p) {
        int x = z.x, y = z.y;
        ll w = z.w;
        int xx = lower_bound(vertice.begin(), vertice.end(), x) - vertice.begin();
        int yy = lower_bound(vertice.begin(), vertice.end(), y) - vertice.begin();
//        cout << xx << " " << yy << endl;
        d[xx][yy] = d[yy][xx] = w;
    }
    for (int i = 0; i < n; ++i) d[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<ll > dis; dis.clear();
    dis.push_back(0);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dis.push_back(d[i][j]);
        }
    }
    sort(dis.begin(), dis.end());
//    cout << dis.size() << endl;
//    for (auto x:dis) cout << x << " "; cout << endl;
    cout << dis[k] << endl;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<P > p(m);
    for (int i = 0; i < m; ++i) p[i].in();
    sort(p.begin(), p.end());

//    int q = 0;
//    for (auto x: p) x.out(q++);

    vector<P > use;
    for (int i = 0; i < m && i < k; ++i) {
        use.push_back(p[i]);
    }

//    q = 0;
//    for (auto x:use) x.out(q++);

    int sz = use.size();
    warshall(sz, use, k);


#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
