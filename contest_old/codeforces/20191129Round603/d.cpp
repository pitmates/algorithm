//
// coded by lp.z
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

unordered_map<char, int > um;

void init() {
    for (int i = 0; i < 26; ++i) {
        um[i+'a'] = i;
    }
    return;
}

int find(int x) {
    if (x == um[x+'a']) return x;
    return find(um['a'+x]);
}

void union_set(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) um['a' + fy] = fx;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    init();
    vector<char > cs;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int m = s.size();
        for (auto c : s) cs.push_back(c);
        if (m == 1) continue;
        int cx = s[0] - 'a';
        for (int i = 1; i < m; ++i) {
            int cy = s[i] - 'a';
            union_set(cx, cy);
        }
    }
    vector<int > ans;
    for (auto c : cs) {
        ans.push_back(find(c-'a'));
    }
    sort(ans.begin(), ans.end());
    auto ed = unique(ans.begin(), ans.end());
    ans.resize(std::distance(ans.begin(), ed));
    cout << ans.size() << endl;


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
