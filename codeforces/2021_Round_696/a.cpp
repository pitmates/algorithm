#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;


int main()
{
//freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string a, b = "";
        cin >> a;
        int x = 0;
        if (a[0] == '0') x = 1;
        else x = 2; 
        b += '1';
        for (int i = 1; i < n; ++i) {
            if (a[i] == '0') {
                if (x == 2) {
                    b += '1';
                    x = 1;
                }
                else if (x == 1) {
                    b += '0';
                    x = 0;
                }
                else {
                    b += '1';
                    x = 1;
                }
            }
            else {
                if (x == 2) {
                    b += '0';
                    x = 1;
                }
                else if (x == 1) {
                    b += '1';
                    x = 2;
                }
                else {
                    b += '1';
                    x = 2;
                }
            }
        }
        cout << b << endl;
    }

    return 0;
}
