#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

string a, b;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    if(a == b) cout << a << endl;
    else cout << '1' << endl;
    return 0;
}
