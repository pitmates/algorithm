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
   ios_base::sync_with_stdio(false); cin.tie(0);

   int t;
   cin >> t;
   while (t--) {
       int w, h, n;
       cin >> w >> h >> n;
       int ans = 1;
       while (w % 2 == 0) {
           ans *= 2;
           w /= 2;
       }
       while (h % 2 == 0) {
           ans *= 2;
           h /= 2;
       }
       if (ans >= n) {
           cout << "YES" << endl;
       }
       else {
           cout << "NO" << endl;
       }
   }

   return 0;
}
