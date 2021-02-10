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
const int N = 123456;

int X[N][2], Y[N][2];

int main()
{
#ifdef PIT
freopen("in.txt", "r", stdin);
freopen("a.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;

        zero(X); zero(Y);
        int P, Q;
        cin >> P >> Q;
        for (int i = 0; i < P; ++i) {
            int x, y;
            string dir;
            cin >> x >> y >> dir;
            if (dir == "S") {

                Y[0][0]++; Y[y-1][1]--;
            }
            else if (dir == "N") {
                Y[y+1][0]++; Y[Q][1]--;
            }
            else if (dir == "E") {
                X[x+1][0]++; X[Q][1]--;
            }
            else if (dir == "W") {
                X[0][0]++; X[x-1][1]--;
            }
        }

        int u = 0, cntx = 0, ansx = 0;
        for (int i = 0; i <= Q; ++i) {
            cntx += X[i][0];
            if (cntx > ansx) {
                ansx = cntx;
                u = i;
            }
            cntx += X[i][1];
        }

        int v = 0, cnty = 0, ansy = 0;
        for (int i = 0; i <= Q; ++i) {
            cnty += Y[i][0];
            if (cnty > ansy) {
                ansy = cnty;
                v = i;
            }
            cnty += Y[i][1];
        }
        cout << u << " " << v << endl; // "  ++: " << ansx + ansy << endl;

    }

#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
