#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const int N = 23456;
int g[N];
int p[N];

int get_prime() {
    memset(g, 0, sizeof g);
    int t = 0;
    for (int i = 2; i < N; ++i) {
        if (g[i]) continue;
        p[t++] = i;
        for (int j = i + i; j < N; j += i) {
            g[j] = 1;
        }
    }
    return t;
}


int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int m = get_prime();

    int T; cin >> T;
    while (T--) {
        int d;
        cin >> d;
        int f = -1, s;
        for (int i = 0; i < m; ++i) {
            if (p[i] - 1 >= d) {
                f = p[i];
                break;
            } 
        }
        for (int i = 0; i < m; ++i) {
            if (p[i] - f >= d) {
                s = p[i];
                break;
            } 
        }
        // cout << f << " " << s << endl;
        cout << f * s << endl;
    }

    return 0;
}
