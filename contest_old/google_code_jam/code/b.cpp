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

int b[32];
int ba[32];
int bs[32];


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

	b[0] = ba[0] = bs[0] = 1;
	for (int i = 1; i < 31; ++i) {
	    b[i] = b[i-1] * 2;
	    ba[i] = b[i] + i;
	    bs[i] = b[i] + bs[i-1];
	}
//	for (int i = 0; i < 31; ++i) printf("%d %d %d\n", b[i], ba[i], bs[i]);
    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
//        cout << "Case #" << ic << ": ";
		cout << "Case #" << ic << ":" << endl;
		int n; cin >> n;
		int bo = 0;
		for (int i = 0; i < 31; ++i) {
		    if (ba[i] < n && bs[i] >= n) {
		        bo = i;
                break;
		    }
		}
        vector<pii > ans;
		if (n <= 500) {
		    for (int i = 0; i < n; ++i) {
		       cout << i+1 << " " << 1 << endl;
		    }
            continue;
		}

		for (int i = 0; i < bo; ++i) ans.pb({i, 0});
		for (int i = 0; i <= bo; ++i) ans.pb({bo, i});
		int pos = -1;
		n -= ba[bo--];
		while (n > 0) {
            if (n >= b[bo] - 1) {
                n -= b[bo] - 1;
                if (pos == -1) {
                    for (int i = bo; i; --i) {
                        ans.pb({bo, i});
                    }
                    pos = 1;
                } else {
                    for (int i = 1; i <= bo; ++i) {
                        ans.pb({bo, i});
                    }
                    pos = -1;
                }
            } else {
                if (pos == -1) n -= 1;
                else n -= (bo + 1);
                bo -= 1;
            }
        }
		for (auto x : ans) {
		    cout << x.fi+1 << " " << x.se+1 << endl;
		}


    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}