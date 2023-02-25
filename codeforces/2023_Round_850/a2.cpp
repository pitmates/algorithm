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
    // freopen("./files/a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int aliceW = 0, aliceB = 0, bobW = 0, bobB = 0, now = 0, left = 0;

        for (int i = 1; i < 12345; ++i)
        {
            left = now + i >= n ? n - now : i;
            if ((i >> 1) & 1) {
                if (left&1) {
                    if (now & 1) bobB += (left + 1) / 2, bobW += left / 2;
                    else bobW += (left + 1) / 2, bobB += left / 2;
                }
                else bobB += left / 2, bobW += left / 2;
            }
            else {
                if (left&1) {
                    if (now & 1) aliceB += (left + 1) / 2, aliceW += left / 2;
                    else aliceW += (left + 1) / 2, aliceB += left / 2;
                }
                else aliceB += left / 2, aliceW += left / 2;
            }
            now += i;
            if (left != i || now >= n)
                break;
        }
        cout << aliceW << " " << aliceB << " " << bobW << " " << bobB << endl;
    }

    return 0;
}
