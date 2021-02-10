//
// Created by pitmates on 2018/7/29.
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

ll x[N];
ll s[N];

ll ans[N];

int main()
{
#ifdef PIT
freopen("A-large-practice.in", "r", stdin);
freopen("A-large-practice.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		ll n, o, d;
		ll a, b, c, m, l, x1, x2;
		cin >> n >> o >> d;
		cin >> x1 >> x2 >> a >> b >> c >> m >> l;
		x[1] = x1;
		x[2] = x2;
		ans[1] = s[1] = x1 + l;
		s[2] = x2 + l;
		s[0] = ans[0] = 0LL;
		ans[2] = ans[1] + s[2];
		for (int i = 3; i <= n; ++i) {
		    x[i] = (a * x[i-1] % m  + b * x[i-2] % m + c) % m;
		    s[i] = x[i] + l;
		    ans[i] = s[i] + ans[i-1];
		}
//        n = 8; o = 1; d = 13;
//        x[0] = 0; x[1] = 19; x[2] = 10; x[3] = 6; x[4] = 8;
//        x[5] = -5; x[6] = 2; x[7] = 2; x[8] = 17;
//        l = 0;
		//ans[0] = s[0] = 0;

//		for (int i = 1; i <= n; ++i) cout << s[i] << " ";
//		cout << endl;

		set<pair<ll, int > > st;
		st.clear();
		st.insert(mp(0LL, 0));

		int od = 0, left = 0;
		ll rs = -INF;
		for (int right = 1; right <= n; ++right) {
		    od += s[right] & 1;
		    while (od > o) {
                od -= s[left+1] & 1;
                st.erase(mp(ans[left], left));
                ++left;
		    }

		    auto p = st.lower_bound(mp(ans[right]-d, -1));
		    if (p != st.end()) {
                rs = max(rs, ans[right] - p->first);
            }
            st.insert(mp(ans[right], right));


        }
		if (rs == -INF) cout << "IMPOSSIBLE" << endl;
		else cout << rs << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
2
330208 0 -302714877190147
424494997 424494997 0 0 424494997 1000000000 0
310279 0 535318376473205
939238575 939238575 0 0 939238575 1000000000 0
 */