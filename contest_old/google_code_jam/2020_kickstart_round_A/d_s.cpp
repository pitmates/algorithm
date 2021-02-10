//
// Created by pitmates on 2020/3/22.
//

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

bool cmp(string& a, string& b) {
    return a.size() > b.size();
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		int n, k;
		cin >> n >> k;
		vector<string > s(n), sub_str;
		vector<int > vis(n, 0);
		for (int i = 0; i < n; ++i) cin >> s[i];
		map<string, vector<int >> mv;
		mv.clear();
		for (int i = 0; i < n; ++i) {
		    int sz = s[i].size();
		    for (int j = 1; j <= sz; ++j) {
                string s_str = s[i].substr(0, j);
                mv[s_str].pb(i);
                sub_str.pb(s_str);
            }
		}
//		for (auto kv : mv) {
//		    cout << kv.first << " :  ";
//		    for (auto x : kv.second) cout << x << " "; cout << endl;
//		}

		sort(sub_str.begin(), sub_str.end(), cmp);
		int ans = 0;
		for (auto& str : sub_str) {
            auto ids = mv[str];
            if (ids.size() < k) continue;
            vector<int > trip;
		    for (auto& x : ids) {
		        if (vis[x]) continue;
		        trip.pb(x);
		        if (trip.size() == k) break;
		    }
		    if (trip.size() != k) continue;
//		    cout << str << ": ";
//		    for (auto x : ids) cout << x << " "; cout << endl;
		    for (auto& x : trip) vis[x] = 1;
		    ans += str.size();
		}
		cout << ans << endl;


    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}