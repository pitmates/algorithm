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

string s[55];
int a[55];

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

		int n, mx = 0, id = -1;
		cin >> n;
		for (int i = 0; i < n; ++i) {
		    cin >> s[i];
		    int sz = s[i].size();
		    if (sz > mx) {
		        mx = sz;
		        id = i;
		    }
		}
		string str = s[id];
		int f = 1;
		reverse(str.begin(), str.end());
		for (int i = 0; i < n; ++i) {
		    reverse(s[i].begin(), s[i].end());
		    for (int j = 0; j < s[i].size()-1; ++j) {
		        if (str[j] != s[i][j]) f = 0;
		    }
		    if (!f) break;
		}
		if (!f) cout << "*" << endl;
		else {
		    string sub = str.substr(0, mx-1);
		    reverse(sub.begin(), sub.end());
		    cout << sub << endl;
		}


    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}