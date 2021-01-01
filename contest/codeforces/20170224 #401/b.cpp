#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 1010;
int gs[N], gc[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	string s, c;
	cin >> n;
	cin >> s >> c;
	for(int i = 0; i < n; ++i) gs[i] = s[i]-'0', gc[i] = c[i]-'0';
	sort(gs, gs+n);
	sort(gc, gc+n);
	int mi = 0, mx = 0;
	int i = n-1, j = n-1;
	
    while(j>=0&&i>=0){
        if(gc[j]<gs[i]){
            int k=i-1;
            for(k=i-1;k>=0;k--)
            {
                if(gs[k]<=gc[j]){

                    break;
                }
            }
            i=k;
            if(i<0)
                break;
        }
        if(gc[j]>=gs[i]){
            mi++;
            j--;
            i--;
        }
    }

    j=0;i=0;
    while(j<n&&i<n){
        if(gc[j]>gs[i])
        {
            mx++;
            j++;i++;
        }
        else
        {
            j++;
        }
    }

	cout << n-mi << endl << mx ;
	return 0;
}
