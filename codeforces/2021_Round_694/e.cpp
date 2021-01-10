#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


int query(int q) {
    cout << "? " << q << endl;
    int x;
    cin >> x;
    return x;
}

int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(query(1) > k) {
        cout << "! " << n << endl;
        return 0;
    }

    int l = 1, r = 1, now = 2;

    for (int i = 0; i < 460; ++i) {
        while (now > n) now -= n;
        int x = query(now);
        if (x > k) break;
        l = r + 1;
        r = l + i - 1;
        now = r + 1;
        while (r > n) r -= n;
    }
    for (int i = now-1; ; --i) {
        if (i == 0) i = n;
        int x = query(i);
        if (x == k) {
            cout << "! " << i << endl;
            return 0;
        }
    }

    return 0;
}
