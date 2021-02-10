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
const int N = 123;

int mber[N], nber[N];
int n, m, p;

int calc_zero(int x) {
    int c = 0;
    while(x) {
        c++;
        x = x&(x-1);
    }
    return c;
}

string sm[N], sn[N];
pii cnt[N];


int cal(string at) {
    for (int i = 0; i < m; ++i) {
        if (at == sm[i]) return inf;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            if (at[j] != sn[i][j]) ++ans;
        }
    }
    return ans;
}


int main()
{
#ifdef PIT
freopen("B.in", "r", stdin);
freopen("B2.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);
    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
        cin >> n >> m >> p;
        string s;

        // small
        /**
        for (int i = 0; i < n; ++i) {
            cin >> s;
            int b = 0;
            for (int j = 0; j < p; ++j) {
                b = (b << 1) + (s[j] - '0');
            }
            nber[i] = b;
        }

        for (int i = 0; i < m; ++i) {
            cin >> s;
            int b = 0;
            for (int j = 0; j < p; ++j) {
                b = (b << 1) + (s[j] - '0');
            }
            mber[i] = b;
        }
        sort(mber, mber+m);

        int ans = inf;
        int c = (1 << p) + 1;
        for (int i = 0; i < c; ++i) {
            int id = lower_bound(mber, mber+m, i) - mber;
            if (id != m && mber[id] == i) continue;

            int res = 0;
            for (int j = 0; j < n; ++j) {
                int x = nber[j] ^ i;
                res += calc_zero(x);
            }
            ans = min(ans, res);
        }
        cout << ans << endl;
        **/

        // large

        for (int i = 0; i < n; ++i) {
            cin >> sn[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> sm[i];
        }
        sort(sm, sm+m);

        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p; ++j) {
                cnt[j].fi += (sn[i][j] == '1');
                cnt[j].se = j;
            }
        }
        //sort (cnt, cnt+p);
        string at = "";
        int q = n / 2;
        for (int i = 0; i < p; ++i) {
            if (cnt[i].fi <= q) at = at + "0";
            else at = at + "1";
        }

        int ans = cal(at);

//        cout << at << endl;
//        cout <<  " ans: " << ans << endl;
//for (int i = 0; i < p; ++i) cout << cnt[i].fi << " "; cout << endl;
        if (ans != inf) {
            cout << ans << endl;
        }
        else {
            int res, ret = inf;
            for (int k = 0; k <= p; ++k) {
                string tp = at;
//                cout << "k = " << k <<  endl << tp << endl;
                for (int i = 0; i < k; ++i) {
                    if (tp[i] == '1') tp[i] = '0';
                    else tp[i] = '1';
                }
                //cout << tp << endl;
                res = cal(tp);
                //cout << "ret: " << ret << endl;
                ret = min(ret, res);
                //cout << res << "  ret: " << ret <<  endl;

                for (int i = k; i < p; ++i) {
                    int l = i - k;
                    if (tp[l] == '0') tp[l] = '1';
                    else  tp[l] = '0';

                    if (tp[i] == '1')  tp[i] = '0';
                    else  tp[i] = '1';

                    ret = min(ret, cal(tp));
                }
            }
            cout << ret << endl;
        }

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}