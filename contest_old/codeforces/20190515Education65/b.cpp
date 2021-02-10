//
// Created by pitmates on 2018/11/23.
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
const int N = 10;



int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    int a[] = {4 , 8, 15, 16, 23, 42};
    vector<int > as[6];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            //cout << a[i] * a[j] << " ";
            as[i].push_back(a[i] * a[j]);
        }
        //cout << endl;
    }

    vector<int > resp;
    for (int ic = 2; ic < 6; ++ic) {
        cout << "? 1 " << ic << endl;
        cout.flush();

        int x;
        cin >> x;
        resp.push_back(x);
    }

    int id = -1, f = 1;
    for (int i = 0; i < 6; ++i) {
        f = 1;
        for (auto x: resp) {
            if (find(as[i].begin(), as[i].end(), x) == as[i].end()) {
                f = 0;
                break;
            }
        }
        if (f == 1) {
            id = i;
            break;
        }
    }

    vector<int > ans(6, 0);
    ans[0] = a[id];
    for (int i = 1; i < 5; ++i) ans[i] = resp[i-1] / ans[0];

    id = -1;
    for (int i = 0; i < 6; ++i) {
        f = 1;
        for (int j = 0; j < 5; ++j) {
            if (ans[j] == a[i]) {
                f = 0;
                break;
            }
        }
        if (f == 1) {
            id = i;
            break;
        }
    }
    ans[5] = a[id];

    cout << "!";
    for (int i = 0; i < 6; ++i) cout << " " << ans[i];
    cout << endl;




#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
