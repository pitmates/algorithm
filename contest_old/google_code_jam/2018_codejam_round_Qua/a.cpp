//
// Created by pitmates on 2018/4/7.
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
int d[33];

int main()
{
#ifdef PIT
//    freopen("", "r", stdin);
//    freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
        int D;
        string P;
        cin >> D >> P;
        P = '0' + P;
        int n = P.size();
        vector<int > id;
        d[0] = 1;
        int s = 0;
        for (int i = 1; i < n; ++i) {
            if (P[i] == 'S') id.push_back(i), d[i] = d[i-1], s += d[i];
            else {
                d[i] = d[i-1] << 1;
            }
        }
//        for (int i = 0; i < n; ++i) cout << d[i] << " "; cout << endl;
        if (s <= D || id.size() == 0) cout << 0 << endl;
        else if (id.size() > D) cout << "IMPOSSIBLE" << endl;
        else {
            int k = id.size() - 1, m = 0;
            while(s > D) {
                int i = k;
                for (; i > 0; --i) if (id[i] - id[i-1] > 1) break;
//                printf("i = %d  s:%d d:%d\n", i, s, D);
                id[i] = id[i] - 1;
                s -= d[id[i]] / 2;
                d[id[i]-1] = d[id[i]-2];
                ++m;
            }
            cout << m << endl;
        }

    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
7
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS
1 CCCC

 */