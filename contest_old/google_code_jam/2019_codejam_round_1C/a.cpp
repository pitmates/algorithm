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
const int N = 555;

int val[N];
string op[N];
int n;


void invalid(char Q, int lo) {
    for (int i = 0; i < n; ++i) {
        if (op[i][lo%op[i].size()] == Q) continue;
        val[i] = 0;
    }
    return ;
}

string judge() {
    string s = "";
    int a[3];
    for (int p = 0; p < N; ++p) {
        int f = 0;
        a[0] = a[1] = a[2] = 0;
        for (int i = 0; i < n; ++i) {
            if (val[i] == 0) continue;

            f = 1;
            if (op[i][p%op[i].size()] == 'R') a[0] = 1;
            else if (op[i][p%op[i].size()] == 'P') a[1] = 1;
            else a[2] = 1;
        }
        if (f == 0) break;
        if (a[0] && a[1] && a[2]) return "IMPOSSIBLE";
        if (a[0] && a[1]) {
            s += "P";
            invalid('P', p);
        }
        else if (a[0] && a[2]) {
            s += "R";
            invalid('R', p);
        }
        else if (a[1] && a[2]) {
            s += "S";
            invalid('S', p);
        }
        else if (a[0]) {
            s += "P";
            break;
        }
        else if (a[1]) {
            s += "S";
            break;
        }
        else if (a[2]) {
            s += "R";
            break;
        }
        //else break;
    }
    return s;
}

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

        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> op[i];
            val[i] = 1;
        }

        string S = judge();
        cout << S << endl;

    }
#ifdef PIT
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}