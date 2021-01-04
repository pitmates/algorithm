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

   int T; cin >> T;
   while (T--) {
       int n; cin >> n;
       vector<int> a(n);
       for (int i = 0; i < n; ++i) cin >> a[i];
       sort(a.begin(), a.end());
       reverse(a.begin(), a.end());
       ll alice = 0, bob = 0;
       for (int i = 0; i < n; ++i) {
           if (i & 1) {
               if (a[i] & 1) {
                   bob += a[i];
               }
           } 
           else {
               if (a[i] % 2 == 0) {
                   alice += a[i];
               }
           }
       }
       if (alice > bob) cout << "Alice" << endl;
       else if (alice < bob) cout << "Bob" << endl;
       else cout << "Tie" << endl;
   }

   return 0;
}
