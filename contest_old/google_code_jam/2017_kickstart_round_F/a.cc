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
const int N = 10010;

int n;
int a[N];
int flag;

void quicksort(int l, int r) {
	vector<int > big, small;
	if (l  >=  r || flag == 0) {
		return ;
	}
	big.clear();
	small.clear();
	int m = (r+l) / 2, tmp = a[m];
	for (int i = l; i <= r; ++i) if(i != m) {
		if(a[i] > tmp) big.pb(a[i]);
		else small.pb(a[i]);
	}
	int sm = small.size();
	int sb = big.size();

	if(sm == 0 || sb == 0) flag &= 1;
	else flag &= 0;
// cout <<  sm << " sb: " << sb << "  fl: " << flag << endl;
// for (int i = 0; i < sm; ++i) cout << small[i] << " "; cout << endl;
// for (int j = 0; j < sb; ++j) cout << big[j] << " "; cout << endl;
	for (int i = 0; i < sm; ++i) a[i+l] = small[i];
	a[l+sm] = tmp;
	for (int i = 0; i < sb; ++i) a[l+sm+1+i] = big[i];
	quicksort(l, l+sm-1);
	quicksort(l+sm+1, r);
}


int main()
{
#ifdef PIT
freopen("A-large.in", "r", stdin);
freopen("A-large.out", "w", stdout);
#endif // PIT
	ios_base::sync_with_stdio(false); cin.tie(0);

    int ic = 1, T;
    for(cin >> T; ic <= T; ++ic){
        cout << "Case #" << ic << ": ";
		//cout << "Case #" << ic << ":" << endl;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        flag = 1;
        quicksort(0, n-1);
    	
    	if(flag) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}