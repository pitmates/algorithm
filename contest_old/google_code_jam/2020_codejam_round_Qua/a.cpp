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

        vector<vector<int > > A(n, vector<int >(n));
        int k = 0, r = 0, c = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
            if (i == j) k += A[i][j];
        }

        for (int i = 0; i < n; ++i) {
            vector<int > v(n+1, 0);
            for (int j = 0; j < n; ++j) {
                v[A[i][j]]++;
                if (v[A[i][j]] > 1) {
                    ++r;
                    break;
                }
            }
            vector<int > vj(n+1, 0);
            for (int j = 0; j < n; ++j) {
                vj[A[j][i]] ++;
                if (vj[A[j][i]] > 1) {
                    ++c;
                    break;
                }
            }

        }
        cout << k << " " << r << " " << c << endl;


    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}