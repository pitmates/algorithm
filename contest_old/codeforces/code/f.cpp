#include <bits/stdc++.h>

using namespace std;
typedef long long INT;

#define NN 200010
int p[NN];
int B[NN];

void update(int u,int x){
    while(u<NN){
        B[u]+=x;
        u+=u&(-u);
    }
}

int calc(int u){
    int s=0;
    while(u>0){
        s+=B[u];
        u-=u&(-u);
    }
    return s;
}

INT ans[NN];
INT res[NN];
INT val[NN];
int id[NN];
int n,pos;

void find(){
    int tot=(calc(n)+1)/2;
    int st=0,ed=n;
    while(st+1<ed){
        int mid=(st+ed)>>1;
        if(calc(mid)>=tot) ed=mid;
        else st=mid;
    }
    pos=ed;
}

int main(){


    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        id[p[i]]=i;
    }
    for(int i=1;i<=n;i++){
        val[i]=i-1;
        if(i>1) val[i]+=val[i-2];
        int x=id[i];
        ans[i]=ans[i-1]+i-1-calc(x);
        if(i%2==0) find();
        update(x,1);
        if(i%2==1) find();
        res[i]=res[i-1]+abs(pos-x);
        cout << ans[i] << " " << res[i] << " " << val[i] << "   ";
        cout << pos << " " << x << " " << abs(pos-x) << endl;
    }
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]+res[i]-val[i]);
    return 0;
}

/*
5
3 2 5 1 4
 */