#include <iostream>

using namespace std;


int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int u = 0, r = 0;
        for(int j = i; j < n; ++j) {
            if(s[j] == 'U') ++u;
            else if(s[j] == 'D') --u;
            else if(s[j] == 'L') --r;
            else if(s[j] == 'R') ++r;
            if(!r && !u) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
