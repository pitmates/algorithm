//
// Created by pitmates on 2019/10/19.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<int > > G;
vector<bool > visit;
stack<int > st;
vector<int > DFN, LOW;
int idx;


void init(int n) {

    G.resize(n+1);
    visit.resize(n+1, 0);
    DFN.resize(n+1, 0);
    LOW.resize(n+1, 0);
    idx = 0;
}


void println(int n) {
    for (int u = 1; u <= n; ++u) {
        for (auto v : G[u]) {
            cout << "(" << u << ", " << v << "),  ";
        }
        cout << endl;
    }
}


void add (int u, int v) {
    G[u].push_back(v);
}


void tarjan (int x) {
    DFN[x] = LOW[x] = ++idx;
    st.push(x);
    visit[x] = true;
    for (auto v : G[x]) {
        if (!DFN[v]) {
            tarjan(v);
            LOW[x] = min(LOW[x], LOW[v]);
        }
        else if (visit[v]) {
            LOW[x] = min(LOW[x], DFN[v]);
        }
    }
    if (DFN[x] == LOW[x]) {
        int tp;
        do {
            tp = st.top();
            cout << tp << " ";
            visit[tp] = false;
            st.pop();
        } while (x != tp);
        cout << endl;
    }
}

#include <unistd.h>
int main()
{
#ifdef PIT
//freopen("../text.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    init(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) if (!DFN[i]) {
        tarjan(i);
    }

    return 0;
}
