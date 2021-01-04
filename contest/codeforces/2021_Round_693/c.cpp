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
       int n;
       cin >> n;
       vector<ll> e(n+1);
       for (int i = 1; i <= n; ++i) {
           cin >> e[i];
       }

       for (int i = n; i; i--) {
           ll pos = i + e[i];
           if (pos <= n) {
               e[i] = e[i] + e[pos];
           }
       }

    //    for (int i = 1; i <= n; ++i) cout << e[i] << " "; cout << endl;

       cout << *max_element(e.begin()+1, e.end()) << endl;

   }

   return 0;
}
