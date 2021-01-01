#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1001 ;
const int inf = 1<<30 ;
int map[maxn][maxn],visit[maxn],dis[maxn] ;
int n,m ;
int dij()
{
      for (int i=1 ; i<=n ; i++)  map[i][i] = inf ;
      for (int i=1 ; i<=n ; i++)  dis[i] = map[1][i] ;
      for (int k=1 ; k<=n ; k++){
            int p=-1 ;
            for (int j=1 ; j<=n ; j++){
                  if (!visit[j] && (p==-1 ||dis[p]<dis[j])) p=j ;
            }
            visit[p]=1 ;
            for (int i=1 ; i<=n ; i++){
                  if (!visit[i] && dis[i]<min(dis[p],map[p][i])){
                        dis[i] = min(dis[p],map[p][i]) ;
                  }
            }
printf("p == %d   ", p); for(int i = 1; i <= n; ++i) printf("%d ", dis[i]); puts("");
      }
      return dis[n] ;
}
int main()
{
#ifdef PIT
freopen("poj1797.in", "r", stdin);
#endif // PIT
      int t,order=0 ;
      scanf("%d",&t) ;
      while (t--){
            order++ ;
            scanf("%d%d",&n,&m) ;
            memset(map,0,sizeof(map)) ;
            memset(visit,0,sizeof(visit)) ;
            memset(dis,0,sizeof(dis)) ;
            for (int i=1 ; i<=m ; i++){
                  int a,b ;
                  scanf("%d%d",&a,&b) ;
                  scanf("%d",&map[a][b]) ;
                  map[b][a] = map[a][b] ;
            }
            printf("Scenario #%d:\n",order) ;
            printf("%d\n",dij()) ;
            if (t) printf("\n") ;
      }
    return 0;
}
