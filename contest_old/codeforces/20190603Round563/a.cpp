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

int a[N], b[N];
int n;


int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    int suma = 0, sumb = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], suma += a[i];
    for (int i = 0; i < n; ++i) cin >> b[i], sumb += b[i];
    if (suma != sumb) {
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        for (int i = 0; i < n; ++i) cout << b[i] << " ";
        cout << endl;
    }
    else {
        int f = 0;
        for (int i = 0; i < n; ++i) if (!f){
            for (int j = 0; j < n; ++j) {
                if (a[i] != b[j]) {
                    swap(a[i], b[j]);
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1) {
            for (int i = 0; i < n; ++i) cout << a[i] << " ";
            for (int i = 0; i < n; ++i) cout << b[i] << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }


#ifdef PIT
flush(cout);
cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif //PIT
    return 0;
}
