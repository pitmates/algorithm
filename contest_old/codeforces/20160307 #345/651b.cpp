#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(n == 1) {
        cout << 0 << endl;
    }
    else {
        sort(a, a+n);
        int k = 0, t = a[0];
        a[k] = 1;
        for(int i = 1; i < n; ++i) {
            if(a[i] == t) a[k]++;
            else t = a[i], a[++k] = 1;
        }
        int s = 0;
        while(1) {
            int v = 0;
            for(int i = 0; i <= k; ++i) if(a[i]) --a[i], ++v;
            if(v > 1) s += v-1;
            else break;
        }
        cout << s << endl;
    }
    return 0;
}
