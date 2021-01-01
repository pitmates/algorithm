#include <bits/stdc++.h>
using namespace std;
const int N = 63;
int pt[N];
int ti[N];
int n, c;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> c;
    for(int i = 0; i < n; ++i) cin >> pt[i];
    for(int i = 0; i < n; ++i) cin >> ti[i];
    int t1, t2, ans, res;
    t1 = t2 = ans = res = 0;
    for(int i = 0; i < n; ++i) {
        t1 += ti[i]; t2 += ti[n-i-1];
        int s = pt[i] - t1*c;
        ans += max(0, s);
        s = pt[n-i-1] - t2*c;
        res += max(0, s);
    }
    if(ans == res) cout << "Tie" << endl;
    else if(ans > res) cout <<  "Limak" << endl;
    else cout << "Radewoosh" << endl;
    return 0;
}
