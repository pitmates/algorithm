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

   int T;
   cin >> T;
   while (T--) {
       int n, c;
       cin >> n;
       
       int w = 0, one = 0;
       for (int i = 0; i < n; ++i) {
           cin >> c;
           w += c;
           if (c == 1) ++one;
       }
       if (w & 1) {
           cout << "NO" << endl;
           continue;
       }
       if ((n & 1) && (one == 0)) {
           cout << "NO" << endl;
       } 
       else {
           cout << "YES" << endl;
       }

   }

   return 0;
}
