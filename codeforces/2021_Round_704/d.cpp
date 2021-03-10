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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, k;
    cin >> a >> b >> k;
    if (a == 0 && k > 0) {
        cout << "No" << endl;
    }
    else if (b == 1 && k > 0) {
        cout << "No" << endl;
    }
    else if (a + b > 1 && k > a+b-2) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < b; ++i) cout << "1";
        for (int i = 0; i < a; ++i) cout << "0"; cout << endl;

        if (k <= a) {
            for (int i = 0; i < b-1; ++i) cout << "1";
            for (int i = 0; i < k; ++i) cout << "0"; cout << "1";
            for (int i = k; i < a; ++i) cout << "0"; cout << endl;
        }
        else {
            int d = k-a;
            for (int i = 0; i < b-d-1; ++i) cout << "1"; cout << "0";
            for (int i = 0; i < d; ++i) cout << "1"; 
            for (int i = 1; i < a; ++i) cout << "0";
            cout << "1" << endl;
        }
    }

    return 0;
}
