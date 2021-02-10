//
// Created by pitmates on 2019-04-06.
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

const int N = 12345;
int g[N], mu[123];

void pr() {
    zero(g);
    for (int i = 2; i < N; ++i) if (!g[i]) {
        for (int j = i+i; j < N; j += i) g[j] = 1;
    }
    return ;
}


int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

	pr();
    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
		int n, t;
		cin >> n >> t;
		for (int i = 0; i < t; ++i) {
		    cin >> mu[i];
		}
		vector <int > p(t+1, 0);
		int a, b, c, y;
		for (int i = 0; i < t-1; ++i) {
			if (mu[i] != mu[i+1]) {
				y = i;
				break;
			}
		}
		c = mu[y];
		for (int i = 2; i <= n; ++i) if (!g[i]){
		    if (c % i == 0) {
		        a = i;
		        b = c / i;
		        break;
		    }
		}
		if (mu[1+y] % a == 0) {
			swap(a, b);
		}
		p[y] = a, p[y+1] = b;
		for (int i = y-1, u = a, v = b; i >= 0; --i) {
			p[i] = v;
			swap(u, v);
		}
		a = b;
		for (int i = y+1; i < t; ++i) {
		    p[i+1] = (mu[i] / a);
		    a = mu[i] / a;
		}
		vector<int > u(t+1, 0);
		for (int i = 0; i <= t; ++i) {
		    u[i] = p[i];
		}
		sort(p.begin(), p.end());
		p.erase(unique(p.begin(), p.end()), p.end());
		string S = "";
		for (int i = 0; i < u.size(); ++i) {
		    int x = u[i];
		    int d = lower_bound(p.begin(), p.end(), x) - p.begin();
		    S += 'A' + d;
		}
		cout << S << endl;

    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}

/*
SUBDERMATOGLYPHICFJKNQVWXZ
SUBDERMATOGLYPHICFJKNQVWXZ
 */