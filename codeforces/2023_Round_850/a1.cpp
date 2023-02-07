#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int main()
{
//freopen("./files/a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int alice = 0, bob = 0, now = 0, left = 0;
        for (int i = 1; i < 10000; ++i) {
            left = now + i >= n ? n - now : i;
            now += i;
            if ((i>>1)&1) bob += left;
            else alice += left;
            if (left != i || now >= n) break;
        }
        cout << alice << " " << bob << endl;
    }

    return 0;
}
