#include <bits/stdc++.h>
#define rep(i,j,k,step) for(int i=(int)j; i<(int)k; i+=(int)step)
using namespace std;
const int N = 2237;
const int M = 5000001;
int euler[M];
inline void pr_euler() {
    rep(i,1,M,1) euler[i] = i;

    rep(i,2,N,1) {
        if(euler[i] != i) continue;
        euler[i] = i-1;
        rep(j,i+i,M,i) euler[j] = euler[j] / i * (i-1);
    }
    return ;
}

int main()
{
    pr_euler();
    int L, R;
    scanf("%d %d", &L, &R);
    int id = L;
    rep(i,L+1,R+1,1) if(euler[id]>euler[i])
        id = i;
    printf("%d\n", id);
    return 0;
}
