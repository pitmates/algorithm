#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

string s;
int len;

stack<int > si;
stack<char > sc;

void cal() {
    if(s)
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    cin >> s;
    len = s.size();
    while(!si.empty()) si.pop();
    while(!sc.empty()) sc.pop();
    for(int i = 0; i < len; ) {
        int t = 0;
        while(s[i] >= '0' && s[i] <= '9') {
            t = t * 10 + s[i] - '0';
            ++i;
        }
        si.push(t);
        sc.push(s[i]);
        cal();
        ++i;
    }
    return 0;
}
