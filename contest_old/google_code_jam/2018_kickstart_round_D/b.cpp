//
// Created by pitmates on 2018/7/29.
//

#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define u first
#define v second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 123456;

int n, k;
ll p[N], h[N], x[N], y[N];
int vis[N];
ll A1, B1, C1, M1;
ll A2, B2, C2, M2;
ll A3, B3, C3, M3;
ll A4, B4, C4, M4;



pair<ll, ll > tw[N], bo[N];

int pre[N], suf[N];

int main()
{
#ifdef PIT
//freopen("B-large-practice.in", "r", stdin);
//freopen("B-large-practice.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    cin >> T;
    for( ; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
        cin >> n >> k;
        cin >> p[1] >> p[2] >> A1 >> B1 >> C1 >> M1;
        cin >> h[1] >> h[2] >> A2 >> B2 >> C2 >> M2;
        cin >> x[1] >> x[2] >> A3 >> B3 >> C3 >> M3;
        cin >> y[1] >> y[2] >> A4 >> B4 >> C4 >> M4;

        for (int i = 3; i <= n; ++i) {
            p[i] = (A1 * p[i-1] % M1 + B1 * p[i-2] % M1 + C1) % M1 + 1;
            h[i] = (A2 * h[i-1] % M2 + B2 * h[i-2] % M2 + C2) % M2 + 1;
        }
        for (int i = 3; i <= k; ++i) {
            x[i] = (A3 * x[i-1] % M3 + B3 * x[i-2] % M3 + C3) % M3 + 1;
            y[i] = (A4 * y[i-1] % M4 + B4 * y[i-2] % M4 + C4) % M4 + 1;
        }

        int ans = 0;
/*
1
957 973
790728044 952243456 730505039 714159711 412512610 145962246
7620042 7196648 7501680 5198289 3327269 3843764
81639194 794307974 692913637 311586729 46926142 187560035
8240440 3308948 6183812 8639157 6270546 2540514

*/
/*
        // small
        cout << endl;
        for (int i = 1; i <= k; ++i) {
            int f = 0;
            for (int j = 1; j <= n; ++j) {
                if (h[j] >= y[i]) {
                    ll d = abs(x[i] - p[j]);
                    if (h[j] - y[i] >= d) {
                        ans ++;
                        f = 1;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;

        ans = 0;
**/

        for (int i = 1; i <= n; ++i) {
            tw[i].u = p[i];
            tw[i].v = h[i];
        }
        sort(tw+1, tw+n+1);
        for (int i = 1; i <= k; ++i) {
            bo[i].u = x[i];
            bo[i].v = y[i];
        }
        //for (int i = 1; i <= n; ++i) cout << "i: "<< i << "( " <<  tw[i].u << " " << tw[i].v << endl;

        //sort(bo+1, bo+1+k, cmp);
        pre[1] = 0;
        suf[n] = n+1;
        for (int i = 2; i <= n; ++i) {
            int tp = i-1;
            pre[i] = i;
            while(tp) {
                if (tw[tp].v > tw[i].v) {
                    pre[i] = tp;
                    break;
                }
                else {
                    tp = pre[tp];
                }
            }
            if (pre[i] == i) pre[i] = 0;
        }
        for (int i = n-1; i; --i) {
            int tp = i+1;
            suf[i] = i;
            while(tp <= n) {
                if (tw[tp].v > tw[i].v) {
                    suf[i] = tp;
                    break;
                }
                else tp = suf[tp];
            }
            if (suf[i] == i) suf[i] = n+1;
        }


        for (int i = 1; i <= k; ++i) {
            int id;
            if (x[i] >= tw[n].u) id = n;
            else if (x[i] <= tw[1].u) id = 1;
            else id = int(lower_bound(tw+1, tw+1+n, mp(x[i], 0LL)) - tw);
            id -= 1;
            for (int j = 0; j < 2; ++j) {
                //cout << id << "ssss" << endl;
                int nt = id+j, f = 0;
                if (nt < 1) nt = 1;
                else if (nt > n) nt = n;
                int tmp = nt;
                while (nt <= n) {
                    ll d = abs(tw[nt].u - x[i]);
                    if (tw[nt].v - y[i] >= d) {
                        f = 1;
                        break;
                    }
                    nt = suf[nt];
                }
                if (f == 0) {
                    nt = pre[tmp];
                    while (nt > 0) {
                        ll d = abs(-tw[nt].u + x[i]);
                        if (tw[nt].v - y[i] >= d) {
                            f = 1;
                            break;
                        }
                        nt = pre[nt];
                    }
                }
                if (f) {++ans; break;}
            }
        }
        cout << ans << endl;
    }

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}