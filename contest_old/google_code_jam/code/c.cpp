//
// coded by lp.z
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define piii pair<int, pii >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

bool cmp(const piii& a, const piii& b) {
    if (a.first != b.first) return a.first < b.first;
    return   a.second.first < b.second.first;
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
		int n;
		cin >> n;
		vector<piii > times(n+n);
		for (int i = 0; i < n; ++i) {
		    int s, e;
		    cin >> s >> e;
		    times[i<<1] = {s, {1, i}};
		    times[i<<1|1] = {e, {-1, i}};
		}
		sort(times.begin(), times.end(), cmp);
		int flag = 0;
		string ans = "";
		for (int i = 0; i < n; ++i) ans += "C";
		vector<char > status(n, -1);
		int C = -1, J = -1;
		int now = 0, pre = 0;
		for (auto& t: times) {
		    int tt = t.first, st = t.second.fi, id = t.se.se;
//		    cout << tt << " " << st << "  " << id << endl;
		    now += st;
		    pre = now;
		    if (now > 2) {
		        flag = 1;
                break;
		    }
		    if (st == 1) {
		        if (C == -1) {
		            C = id;
		            status[C] = id;
		            ans[id] = 'C';
		        }
		        else {
		            J = id;
		            status[J] = id;
		            ans[id] = 'J';
		        }
		    }
		    else {
		        if (J == id) J = -1;
		        else C = -1;
		    }

		}
		if (flag) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
1
3
360 480
420 540
600 660

 */