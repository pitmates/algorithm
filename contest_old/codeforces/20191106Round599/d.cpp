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


unordered_map<int, vector<int > > mv;


void bfs(int u, set<int > &st) {
    queue<int > q;
    q.push(u);
    st.erase(u);
    set<int > s;
    s.clear();
//    cout << "u == " << u << endl;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (auto v : mv[f]) {
            if (find(st.begin(), st.end(), v) == st.end()) continue;
            st.erase(v);
            s.insert(v);
        }
//        cout << f << "  ooo " << endl;
//        for (auto v : st) cout << v << " "; cout << endl;
//        for (auto v : s) cout << " " << v; cout << endl;
        for (auto v : st) q.push(v);
        st = s;
//        for (auto v : st) cout << "  " << v; cout << endl;
        s.clear();
    }
    return;
}


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    mv.clear();
    set<int > remains;
    for (int i = 1; i <= n; ++i) remains.insert(i);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        mv[x].push_back(y);
        mv[y].push_back(x);
    }
    for (auto &z : mv) sort(z.second.begin(), z.second.end());
    
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (find(remains.begin(), remains.end(), i) == remains.end()) continue;
        ++ans;
        bfs(i, remains);

//        for (auto v : remains) cout << v << " "; cout << " ====" << endl;
    }
    cout << ans << endl;



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
