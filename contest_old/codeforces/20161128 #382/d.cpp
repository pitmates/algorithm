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
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;

bool isprime(int x) {
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return 0;
    return 1;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    if(n&1) {
        if(isprime(n)) cout << 1 << endl;
        else if(isprime(n-2)) cout << 2 << endl;
        else cout << 3 << endl;
    }
    else if(n == 2) cout << 1 << endl;
    else cout << 2 << endl;
    return 0;
}
