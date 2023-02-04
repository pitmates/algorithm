#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


bool compare(string s, vector<pair<string, int>> ss) {
    for (auto z : ss) {
        string zs = z.first;
        int score = z.second;
        int sc = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == zs[i]) ++sc;
        }
        if (sc != score) return false;
    }
    return true;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int icase = 1; icase <= T; ++icase) {
        cout << "Case #" << icase << ": ";
        int n, q; cin >> n >> q;
        vector<pair<string, int>> ss(n);
        for (int i = 0; i < n; ++i) {
            string s; int score;
            cin >> s >> score;
            ss[i] = {s, score};
        }

        int m = (1 << q);
        vector<string> ans; 
        for (int i = 0; i < m; ++i) {
            string s_t = "";
            for (int j = 0; j < q; ++j) {
                if (i & (1 << j)) s_t += 'T';
                else s_t += 'F';
            }
            if (compare(s_t, ss)) ans.push_back(s_t);
        }

        // for (auto z : ans) cout << z << " "; cout << endl;

        vector<int> g(m, 0);
        int cnt = ans.size();
        for (auto z : ans) {
            for (int i = 0; i < z.size(); ++i) {
                if (z[i] == 'T') ++g[i];
            }
        }

        string res;
        int score = 0;
        for (int i = 0; i < q; ++i) {
            int y = cnt - g[i];
            if (g[i] >= y) res += 'T';
            else  res += 'F';
            score += max(g[i], y);
        }

        int gcd = __gcd(score, cnt);

        cout << res << " " << score/gcd << "/" << cnt/gcd << endl;
    }

    return 0;
}
