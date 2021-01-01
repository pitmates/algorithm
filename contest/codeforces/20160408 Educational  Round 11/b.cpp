#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x = 0, y, z = 0;
    cin >> n >> m;
    x = n+n;

    for(int i = 1; i <= x; ++i) {
        if(x+i <= m) cout << x+i << " ";
        if(i <= m) cout << i << ' ';
    }
    return 0;
}
