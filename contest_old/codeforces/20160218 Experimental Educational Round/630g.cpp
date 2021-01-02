#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;


int main()
{
    ll n;
    cin >> n;
    ll res = (n+4) * (n + 3) / 2 * (n +2) / 3 * (n + 1) / 4 * n / 5 * (n+2) * (n+1) / 2 * n / 3;
    cout << res << endl;
    return 0;
}
