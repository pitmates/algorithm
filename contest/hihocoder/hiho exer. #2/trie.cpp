#include <bits/stdc++.h>
using namespace std;

struct Trie{
    int cnt;
    int next[26];
    bool isw;
    void init() {
        cnt = 0; isw = 0;
        memset(next, -1, sizeof next);
    }
}T[1000100];
int t;

void insert(char* s) {
    int x, p = 0;
    while(*s) {
        x = *s - 'a';
        if(T[p].next[x] == -1) {
            T[t].init();
            T[p].next[x] = t++;
        }
        p = T[p].next[x];
        T[p].cnt++;
        ++s;
    }
    T[p].isw = 1;
}

int query(char* s) {
    int x, p = 0;
    while(*s) {
        x = *s - 'a';
        if(T[p].next[x] == -1) return 0;
        p = T[p].next[x];
        ++s;
    }
    return T[p].cnt;
}

int main()
{
    char c[12];
    int n;
    t = 1; T[0].init();
    for(scanf("%d", &n); n; --n) {
        scanf("%s", c);
        insert(c);
    }
    for(scanf("%d", &n); n; --n) {
        scanf("%s", c);
        printf("%d\n", query(c));
    }
    return 0;
}

/**
#include <bits/stdc++.h>
using namespace std;

typedef struct Trie {
    int cnt; // the number of pre
    struct Trie* next[26]; //指向各个子树的指针
    bool isw; // 是否为一个单词
} Trienode, *trie;

Trienode* creat() {
    Trienode* node = new Trienode[sizeof(Trienode)];
    node->cnt = 0;
    node->isw = 0;
    memset(node->next, 0, sizeof node->next);
    return node;
}

void insert(trie root, char* word) {
    trie node = root;
    char *p = word;
    int id;
    while(*p) {
        id = *p - 'a';
        if(node->next[id] == NULL) {
            node->next[id] = creat();
        }
        node = node->next[id];
        ++p;
        node->cnt += 1;
    }
    node->isw = 1;
}

int search(trie root, char * word) {
    trie node = root;
    char* p = word;
    int id;
    while(*p) {
        id = *p - 'a';
        node = node->next[id];
        ++p;
        if(node == NULL) return 0;
    }
    return node->cnt;
}

int main()
{
    trie root = creat();
    char c[12];
    int n;
    for(scanf("%d", &n); n; --n) {
        scanf("%s", c);
        insert(root, c);
    }
    for(scanf("%d", &n); n; --n) {
        scanf("%s", c);
        printf("%d\n", search(root, c));
    }
    return 0;
}
**/
