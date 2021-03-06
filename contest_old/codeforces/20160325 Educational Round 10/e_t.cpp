#include<stdio.h>
#include<cstring>
#include<algorithm>
#define N 600005
using namespace std;
struct node {
	int x,y,z;
}a[N];
int i,j,k,T,r,l,s[N],n,m,id[N],tot,last[N],next[N],to[N],val[N],low[N],dfn[N],q[N],v[N],ans[N],st,en;
inline void add(int o,int p,int w) {
	next[++tot]=last[o]; last[o]=tot; to[tot]=p; val[tot]=w;
}
inline void tarjan(int o,int fa) {
	dfn[o]=low[o]=++tot;
	q[++r]=o;
	for (int i=last[o];i;i=next[i]) {
		if (to[i]==fa) continue;
		if (!dfn[to[i]]) tarjan(to[i],o),low[o]=min(low[o],low[to[i]]);
		else low[o]=min(low[o],dfn[to[i]]);
	}
	if (low[o]==dfn[o]) {
		++T;
		while (q[r]!=o) id[q[r--]]=T;
		id[q[r--]]=T;
	}
}
inline void bfs(int o) {
	int l=0,r=1; q[1]=o; v[o]=1; ans[o]=s[o];
	while (l<r) {
		int k=q[++l];
		for (int i=last[k];i;i=next[i]) {
			if (v[to[i]]) continue;
			v[q[++r]=to[i]]=1; ans[to[i]]=ans[k]|val[i]|s[to[i]];
		}
	}
for(int i = 0; i < 10; ++i) printf("%d ", id[i]); puts("");
for(int i = 0; i < 10; ++i) printf("%d ", ans[i]); puts("");
	if (ans[id[en]]) puts("YES");
	else puts("NO");
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),add(a[i].x,a[i].y,a[i].z),add(a[i].y,a[i].x,a[i].z);
	scanf("%d%d",&st,&en);
	tot=0;
	tarjan(1,0);
for( i = 0; i < 10; ++i) printf("%d ", id[i]); puts("");
	memset(last,0,sizeof(last));
	tot=0;
	for (i=1;i<=m;i++) if (id[a[i].x]==id[a[i].y]) s[id[a[i].x]]=max(s[id[a[i].x]],a[i].z);
	else add(id[a[i].x],id[a[i].y],a[i].z),add(id[a[i].y],id[a[i].x],a[i].z);
	if (id[st]==id[en]) {
		if (s[id[st]]) puts("YES");
		else puts("NO");
		return 0;
	}
	bfs(id[st]);
}
