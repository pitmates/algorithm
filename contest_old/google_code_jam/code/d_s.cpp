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

    int ic = 1, T, B;
    for(cin >> T >> B; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;

        cout << 1 << endl;
        int r0, rs, re;
        cin >> r0;
        cout << 1 << endl;
        cin >> rs;
        cout << 10 << endl;
        cin >> re;
        cout.flush();

        int k = 0;
        if (rs != r0) k = 1;

        string s = "0000000000";
        s[0] = rs + '0';
        s[9] = re + '0';

        int f = 0;
        for (int i = 2; i < 6; ++i) {
            cout << i << endl;
            cin >> rs;
            cout << 11 - i << endl;
            cin >> re;
            s[i] = rs + '0';
            s[11-i] = re + '0';
            if (rs == re) {
                if (f == 0) f = 1;
                else f = 3;
            }
            else {
                if (f == 0) f = 2;
                else f = 3;
            }
        }
        if (k == 0) cout << s << endl;
        else {
            for (int i = 0; i < 10; ++i) {
                if (s[i] == '0') s[i] = '1';
                else s[i] = '0';
            }
        }

        cout.flush();
        cin >> r0;


    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}


