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

const int N = 1234;
int n;
string s[N];
map<string, int > ms;


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

//	string q = "abcdefg";
//	cout << q.substr(1) << endl;
//map<string, int > mx;
//mx["abc"] = 1; mx["ab"] = 4; mx["ac"] = 1;
//for (auto a : mx) cout << a.first << " " << a.second << endl;
//for (auto a : mx) if (a.second < 2) mx.erase(a.first);
//cout << "+++++\n";
//for (auto a : mx) cout << a.first << " " << a.second << endl;


    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		cin >> n;
		ms.clear();
		for (int i = 0; i < n; ++i) {
		    string t;
		    cin >> t;
		    int len = t.size();
		    ms[t] += 1;
		    for (int l = 1; l < len; ++l) {
		        string sub = t.substr(l);
		        ms[sub] += 1;
		    }
		}

//for (auto it : ms) {
//    cout << it.first << " " << it.second << endl;
//}
		int ans = 0;
		while (true) {
		    int f = 0;
		    int mi = inf;
		    string tt = "";
		    for (auto si : ms) {
		        string t = si.first;
		        int cnt = si.second;
		        if (cnt < 2) {
		            ms.erase(t);
		            continue;
		        }
		        if (cnt > 1) f = 1;
		        if (mi > cnt) {
		            mi = cnt;
		            tt = t;
		        }
		        else if (mi == cnt) {
		            if (t.size() > tt.size()) {
		                tt = t;
		            }
		        }
		    }
            if (f == 0) break;

		    ans += 2;

		    ms.erase(tt);
		    for (int l = 1; l < tt.size(); ++l) {
		        string sub = tt.substr(l);
		        ms[sub] -= 2;
		    }

//cout << " ----------- " << endl;
//		    for (auto it : ms) {
//                cout << it.first << " " << it.second << endl;
//            }

		}

		cout << ans << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
5
2
TARPOL
PROL
3
TARPOR
PROL
TARPRO
6
CODEJAM
JAM
HAM
NALAM
HUM
NOLOM
4
PI
HI
WI
FI
6
CODEJAM
EJAM
HAM
NAHAM
HUM
NOLOM

 */