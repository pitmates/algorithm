//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
using namespace std;

int main()
{
    #ifdef PIT
//    freopen("", "r", stdin);
//    freopen(".out", "w", stdout);
    #endif // PIT
    ios_base::sync_with_stdio(false);

    int g, n;
    string b;
    cin >> g;
    while(g--) {
        cin >> n;
        cin >> b;
        int flag[30], f_ = 0;
        memset(flag, 0, sizeof flag);
        for(int i = 0; i < n; ++i) {
            if(b[i] == '_') f_++;
            else flag[b[i]-'A']++;
        }
        int f = 0;
        for(int i = 0; i < 26; ++i) if(flag[i] == 1) {
            f = 1;
            break;
        }
        if(f) cout << "NO" << endl;
        else {
            if(f_) cout << "YES" << endl;
            else {
                int v = b[0] - 'A', t = 1, fl = 0;
                for(int i = 1; i < n; ++i) {
                    if(b[i] - 'A' == v) {
                        t++;
                    }
                    else {
                        if(t == 1) {
                            fl = 1;
                            break;
                        }
                        else {
                            t = 1;
                            v = b[i] - 'A';
                        }
                    }
                }
                if(t == 1) fl = 1;
                if(fl) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
        }
    }
    return 0;
}
