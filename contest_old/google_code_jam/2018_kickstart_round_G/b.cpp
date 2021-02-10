#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pli pair<ll, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 412345;

ll x[N], y[N], z[N];
ll L[N], R[N], K[N];

int Q, n;

ll A1, B1, C1, M1;
ll A2, B2, C2, M2;
ll A3, B3, C3, M3;

pli pK[N >> 2];
pli nd[N<<1];
ll ndx[N<<1];
ll ndy[N<<1];


bool cmp(pli a, pli b) {
    return a.first > b.first || (a.fi == b.fi && a.se < b.se);
}

ll calc(ll m) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) if (R[i] >= m) {
            cnt += R[i] - max(L[i], m) + 1;
        }
    return cnt;
}


int main()
{
#ifdef PIT
freopen("B-small-attempt0.in", "r", stdin);
freopen("B-small-attempt0.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);
    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;

		cin >> n >> Q;
		cin >> x[1] >> x[2] >> A1 >> B1 >> C1 >> M1;
		cin >> y[1] >> y[2] >> A2 >> B2 >> C2 >> M2;
		cin >> z[1] >> z[2] >> A3 >> B3 >> C3 >> M3;
		for (int i = 3; i <= n; ++i) {
            x[i] = (A1 * x[i - 1] % M1 + B1 * x[i - 2] % M1 + C1) % M1;
            y[i] = (A2 * y[i - 1] % M2 + B2 * y[i - 2] % M2 + C2) % M2;
        }
        for (int i = 3; i <= Q; ++i) {
            z[i] = (A3 * z[i-1] % M3 + B3 * z[i-2] % M3 + C3) % M3;
        }
        for (int i = 1; i <= n; ++i) {
            L[i] = min(x[i], y[i]) + 1;
            R[i] = max(x[i], y[i]) + 1;
        }
        for (int i = 1; i <= Q; ++i) {
            K[i] = z[i] + 1;
        }

//        for (int i = 1; i <= n; ++i) {
//            cout << "i: " << i << " ("  << L[i] << ", " << R[i] << ") " << K[i] << endl;
//        }

        ll ans = 0;
        ll LL = INF, RR = -INF;
        for (int i = 1; i <= n; ++i) {
            ans += R[i] - L[i] + 1;
            LL = min(LL, L[i]);
            RR = max(RR, R[i]);
        }
        ll res = 0;

        for (int i = 1; i <= Q; ++i) {
            pK[i-1] = {K[i], i};
        }
        sort(pK, pK+Q);

        int t = 0;
        for (int i = 1; i <= n; ++i) {
            nd[t++] = {L[i], -1};
            nd[t++] = {R[i], 1};
        }
        sort(nd, nd+t, cmp);
        memset(ndx, 0, sizeof ndx);
        memset(ndy, 0, sizeof ndy);

        ndx[0] = 0;
        ndy[0] = 1;
        for (int i = 1; i < t; ++i) {
            ndx[i] = (nd[i-1].fi - nd[i].fi) * ndy[i-1] + ndx[i-1];
            ndy[i] = ndy[i-1] + nd[i].se;
        }

        for (int k = 0; k < Q; ++k) {
            ll q = pK[k].fi;
            if (q > ans) continue;

            ll d = lower_bound(ndx, ndx+t, q);
            ll rem = d - q;


        }


        for (int k = 1; k <= Q; ++k) {
            ll lm = LL;
            ll rm = RR;
            ll q = K[k];
            if (q > ans) res += 0;
            else {
                while (lm <= rm) {
                    ll m = (lm + rm) / 2;
                    ll cnt = calc(m);
                    //cout << cnt << " l:" << lm << " r:" << rm  << " m:" << m << endl;
                    if (cnt >= q) lm = m + 1;
                    else rm = m - 1;
                }
                //cout << k << "  " << rm << endl;
                res += rm * k;
            }
//            cout << "res: " << res << endl;
        }
        cout << res << endl;
    }

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT

    return 0;
}