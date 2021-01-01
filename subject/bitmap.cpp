#include <bits/stdc++.h>

using namespace std;

const int SHIFT = 5;
const int MASK = 0x1f;
const int WORD = (1<<SHIFT);

const int N = 100;

unsigned int bitmap[1+N/WORD];

inline void clean(int i) {
    bitmap[i >> SHIFT] &= ~(1 << (i & MASK));
}

inline void bp(int i) {
    bitmap[i >> SHIFT] |= (1 << (i & MASK));
}

inline bool cal(int i) {
    return bitmap[i >> SHIFT] & (1 << (i & MASK));
}

int b[N];

int main()
{
#ifdef PIT
freopen("in.in", "r", stdin);
#endif // PIT
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < N; ++i) clean(i);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        b[i] = a;
        bp(a);
    }

    sort(b, b+n);
    for(int i = 0; i < n; ++i) printf("%d ", b[i]); puts("");

    for(int i = 0; i < N; ++i) if(cal(i)) printf("%d ", i); puts("");
    return 0;
}
