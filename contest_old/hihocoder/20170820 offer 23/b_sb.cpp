#include <bits/stdc++.h>
using namespace std;

const int M=2500000;
string inp;
struct Node {
    string key;
    vector<int> sons;
} tr[M];
int tot=0;
string s;

void ins(int rt,int l)
{
    int r=l+1;
    while (r!=s.length()&&s[r]!='/') r++;
    if (r==s.length()) return;
    string dir=s.substr(l+1,r-l-1);
//    cout<<dir<<"\n";
    int f=0;
    for (int x:tr[rt].sons) {
        if (tr[x].key==dir) {
            ins(x,r);
            f=1;
        }
    }
    if (!f) {
        tr[rt].sons.push_back(++tot);
        tr[tot].key=dir;
        ins(tot,r);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s;
        s += '/';
        ins(0,0);
    }
    for(int i = 0; i < tot; ++i) {
    cout << " i == " << i << "   key:  " << tr[i].key << endl;
    for(auto& u : tr[i].sons) cout << u << "  "; cout << endl;
}
    printf("%d\n",tot);
    return 0;
}

