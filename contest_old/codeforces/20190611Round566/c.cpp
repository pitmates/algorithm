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
#define piii pair<pii, int >
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;


char vowels[] = {'a', 'e', 'i', 'o', 'u'};

int judge(char c) {
    for (int i = 0; i < 5; ++i) if (c == vowels[i]) return i;
    return -1;
}


bool cmp(piii a, piii b) {
    return a.fi.fi < b.fi.fi || (a.fi.fi == b.fi.fi && a.fi.se < b.fi.se);
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
    vector<piii > rec(n, {{0, 0}, -1});
    vector<string > S(n+1, "");
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        S[i] = s;
        int len = s.size();
        int last = -1, ct = 0;
        for (int j = 0; j < len; ++j) {
            int jg = judge(s[j]);
            if (jg == -1) continue;
            last = jg;
            ++ct;
        }
//        if (ct == 0) continue;
//cout << "{{ " << ct << ", " << last << "},  " << i << "}" << endl;
        rec[i] = {{ct, last}, i};
    }

    sort(rec.begin(), rec.end(), cmp);

    for (int i = 0; i < n; ++i) {
        int ct = rec[i].fi.fi, last = rec[i].fi.se, id = rec[i].se;
  //      cout << "{{ " << ct << ", " << last << "},  " << id << "}" << endl;
    }

    vector<int > g(n+3, 0);

    vector<pii > ans_idx;

    int sec = 0;
    for (int i = 1; i < rec.size(); ++i) {
        int pre_len = rec[i-1].fi.fi, pre_l = rec[i-1].fi.se;
        int len = rec[i].fi.fi, l = rec[i].fi.se;
        int pre_id = rec[i-1].se, id = rec[i].se;
        if (pre_len != len) continue;
        if (pre_l == l) {
            ans_idx.pb({-1, pre_id}); ans_idx.pb({-1, id});
            g[i-1] = 1; g[i] = 1;
            ++i; sec += 2;
        }
    }
/*
    for (int i = 0; i < sec; ++i) {
        cout << ans_idx[i].fi << " , " << ans_idx[i].se << endl;
    }
    cout << " ------ " << endl;

    for (int i = 0; i < n; ++i) cout << g[i] << " ";
    cout << endl;
*/
    vector<piii > relic;
    for (int i = 0; i < rec.size(); ++i) if (g[i] != 1) {
        relic.pb(rec[i]);
    }

/*
    for (int i = 0; i < relic.size(); ++i) {
        int ct = relic[i].fi.fi, last = relic[i].fi.se, id = relic[i].se;
        cout << "{{ " << ct << ", " << last << "},  " << id << "}" << endl;
    }
*/

    int fir = 0;
    for (int i = 1; i < relic.size(); ++i) {
        int pre_len = relic[i-1].fi.fi, pre_l = relic[i-1].fi.se;
        int len = relic[i].fi.fi, l = relic[i].fi.se;
        int pre_id = relic[i-1].se, id = relic[i].se;
        if (pre_len != len) continue;

        if (fir >= sec) break;
        ans_idx[fir++].fi = pre_id; ans_idx[fir++].fi = id;
        ++i;

        /*
        if (pre_l == l) {
            ans_idx.pb({-1, i-1}); ans_idx.pb({-1, i});
            ++i;
            sec += 2;
        }
        else {
            if (fir < sec) {
                ans_idx[fir++].fi = i-1;
                ans_idx[fir++].fi = i;
            }
            else {
                ans_idx.pb({i-1, -1});
                ans_idx.pb
            }
        }
         */
    }

/*
    cout << fir << "   " << sec << endl;
    for (int i = 0; i < sec; ++i) cout << ans_idx[i].fi << " , " << ans_idx[i].se << endl;

    cout << " ==== " << endl;
*/


    --sec; --fir;
    while (sec > fir) {
        ans_idx[++fir].fi = ans_idx[sec--].se;
        ans_idx[++fir].fi = ans_idx[sec--].se;
    }

    int res = (min(fir, sec)+1) ;
    cout << res/2 << endl;
    for (int i = 0; i < res; ++i) {
        int f = ans_idx[i].fi, s = ans_idx[i].se;
        cout << S[f] << " " << S[s] << endl;
    }



#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
