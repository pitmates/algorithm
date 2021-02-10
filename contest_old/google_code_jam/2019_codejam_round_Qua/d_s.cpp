//
// Created by pitmates on 2019-04-07.
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
		int n, b, f;
		cin >> n >> b >> f;
		string s, ty = "";
		vector<int > p;
		p.push_back(0);
		p.push_back(n / 2);
		p.push_back(n-1);
		int ct = 0;
		for (int i = 0; i < n; ++i) {
		    int j;
		    for (j = 0; j < p.size(); ++j) {
		        if (i >= p[j]) break;
		    }
		    if (j&1) ty += "1";
		    else ty += "0";
		}
		ct += 1;
		cout << ty << endl;
		while(cin >> s) {
		    if (s == "-1") break;
		    vector<int > q;
		    q.push_back(0);
		    for (int i = 1; i <= ct; ++i) {
		        q.push_back((p[i]+p[i-1])/2);
		        q.push_back(p[i]);
		        q.push_back((p[i+1]+p[i])/2);
		    }
		    q.push_back(n-1);

		    ty = "";
            for (int i = 0; i < n; ++i) {
                int j;
                for (j = 0; j < p.size(); ++j) {
                    if (i >= p[j]) break;
                }
                if (j&1) ty += "1";
                else ty += "0";
            }
            ct += 1;
            cout << ty << endl;
		}

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}