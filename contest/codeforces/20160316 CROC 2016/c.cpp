#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

struct P{
    int id;
    char s[50];
    char s1[25];
    void read(int i) { gets(s); id = i; }
    void print() {printf("%d  %s+%s\n", id, s1, s); }
};

bool cmp(P a, P b) {return strcmp(a.s1, b.s1) < 0 || (strcmp(a.s1, b.s1)==0 && strcmp(a.s, b.s) < 0);}
bool cmp2(P a, P b) {return strcmp(a.s, b.s) < 0;}
bool cmp3(P a, P b) {return a.id < b.id;}
bool operator == (P a, P b) {return strcmp(a.s, b.s) == 0;}

P web1[N], web2[N];

pair<string, int > web[N];
int n;
vector<int > v[N];

void deal() {
    for(int i = 0, j, k; i < n; ++i) {
        P p = web1[i];
        k = strlen(p.s);
        int f = 0, r = 0, l = 0;
        for(j = 7; j < k; ++j) {
            if(!f && p.s[j] != '/') {
                web2[i].s1[l++] = web1[i].s[j];
                continue ;
            }
            else if(p.s[j] == '/') f = 1;
            web2[i].s[r++] = p.s[j];

        }
        if(r == 0) web2[i].s[0] = ' ';
        web2[i].id = web1[i].id;
    }
    return ;
}

void solve() {
    if(n == 1) {
        puts("0");
        return ;
    }
    sort(web1, web1+n, cmp2);
    n = unique(web1, web1+n) - web1;
    for(int i = 0; i < n; ++i) web1[i].id = i;
    deal();
//for(int i = 0; i < n; ++i) web2[i].print();
    sort(web2, web2+n, cmp);
//for(int i = 0; i < n; ++i) web2[i].print();

    int t = 0;
    string w(web2[0].s);
    web[t].first = w;
    P p = web2[0];
    web[t].second = p.id;
    for(int i = 1; i < n; ++i) {
        if(strcmp(web2[i].s1, p.s1) == 0) web[t].first += string(web2[i].s);
        else {
            ++t;
            p = web2[i];
            web[t].first = string(p.s);
            web[t].second = p.id;
        }
    }
    ++t;
    sort(web2, web2+n, cmp3);
//puts("_+_+_+_+_+_+_+");
//for(int i = 0; i < n; ++i) web2[i].print();
    sort(web, web+t);
//printf("t = %d\n", t);
//for(int i = 0; i < t; ++i) cout << web[i].first <<  " " << web[i].second << endl;
    v[0].clear();
    int e = 0;
    v[e].push_back(web[0].second);
    for(int i = 1, flag = 1; i < t; ++i) {
        string e1 = web[i].first, e2 = web[i-1].first;
        int le1 = web[i].first.size(), le2 = web[i-1].first.size();
        if(le1 == le2) {
            for(int j = 0; j < le1 && flag; ++j) if(e1[i] != e2[i]) flag = 0;
        }
        else flag = 0;
        if(flag) {
            v[e].push_back(web[i].second);
        } else {
            if(v[e].size() == 1) {
                v[e].pop_back();
                v[e].push_back(web[i].second);
            }
            else {
                v[++e].push_back(web[i].second);
            }
            flag = 1;
        }
    }
    if(e == 0 && v[e].size() < 2) {
        puts("0");
        return ;
    }
    ++e;
//printf("++++\n");
//for(int i = 0; i < e; ++i) {
//    printf("%d   ", v[i].size());
//    for(int j = 0; j < v[i].size(); ++j) printf("%d ", v[i][j]);
//    for(int j = 0; j < v[i].size(); ++j) printf("http://%s+%s ", web2[v[i][j]].s1, web2[v[i][j]].s ); puts("");
//    puts("");
//}
    printf("%d\n", e);
    for(int i = 0; i < e; ++i) {
        if(v[i].size() == 1) continue;
        printf("http://%s", web2[v[i][0]].s1);
        for(int j = 1; j < v[i].size(); ++j) printf(" http://%s", web2[v[i][j]].s1);
        puts("");
    }
    return ;
}

int main()
{
freopen("c.in", "r", stdin);
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; ++i) web1[i].read(i);
    solve();
    return 0;
}
