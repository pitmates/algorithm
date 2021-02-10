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

int a[5];
vector<int > vi[5];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T, F;
    for(cin >> T >> F; ic <= T; ++ic){
        //cout << "Case #" << ic << ": ";
        //cout << "Case #" << ic << ":" << endl;

        int cnt = 0;
        zero(a);
        for (int i = 0; i < 5; ++i) vi[i].clear();
        for (int i = 0; i < 119; ++i) {
            int q = i*5 + 1;
            cout << q << endl;

            cout.flush();
            string r; cin >> r;
            vi[r[0]-'A'].push_back(q);
        }

        int miss = -1;
        for (int i = 0; i < 5; ++i) {
            if (vi[i].size() != 24) {
                miss = i;
            }
        }

        string res = "";
        res += miss+'A';
        a[miss] = 1;

        vector<int > v2[5];
        for (int i = 0; i < 5; ++i) v2[i].clear();
        for (int i = 0; i < vi[miss].size(); ++i) {
            int x = vi[miss][i];
            int q = x + 1;
            cout << q << endl;
            cout.flush();

            string r; cin >> r;
            v2[r[0]-'A'].push_back(q);
        }

        miss = -1;
        for (int i = 0; i < 5; ++i) {
            if (v2[i].size() < 6 && v2[i].size() > 0) {
                miss = i;
            }
        }
        res += miss+'A';
        a[miss] = 1;

        vector<int > v3[5];
        for (int i = 0; i < 5; ++i) v3[i].clear();
        for (int i = 0; i < v2[miss].size(); ++i) {
            int x = v2[miss][i];
            int q = x + 1;
            cout << q << endl;
            cout.flush();

            string r; cin >> r;
            v3[r[0]-'A'].push_back(q);
        }

        miss = -1;
        for (int i = 0; i < 5; ++i) {
            if (v3[i].size() == 1) {
                miss = i;
            }
        }
        res += miss+'A';
        a[miss] = 1;

        int q = v3[miss][0] + 1;
        cout << q << endl;
        cout.flush();

        string r; cin >> r;
        int idx = r[0] - 'A', xx;
        a[idx] = 1;

        for (int i = 0; i < 5; ++i) if (a[i] == 0) {
            xx = i;
        }

        res += xx+'A';
        res += idx+'A';



        cout << res << endl;
        cout.flush();
        string qq;
        cin >> qq;

    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}