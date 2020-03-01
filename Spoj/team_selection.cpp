#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define third second.second
#define scnd second.first

vector<int> bit;
int n;

int LSO(int i) { return (i & -i); }

void update(int i, int v) {
    while (i <= n)
        bit[i] = min(bit[i], v), i += LSO(i);
}

int query(int i) {
    int min_pos = INT_MAX;
    while (i > 0)
        min_pos = min(min_pos, bit[i]), i -= LSO(i);

    return min_pos;
}

int main() {
    scanf("%d", &n);

    vector<iii> ranks(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &ranks[i].first);

    for (int i = 0; i < n; i++)
        scanf("%d", &ranks[i].scnd);

    for (int i = 0; i < n; i++)
        scanf("%d", &ranks[i].third);

    sort(ranks.begin(), ranks.end());
    bit.assign(n + 1, INT_MAX);

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", ranks[i].first, ranks[i].scnd, ranks[i].third);

    int num_exc = 0;
    for (int i = 0; i < n; i++) {
        int min_pos = query(ranks[i].scnd);
        if (min_pos > ranks[i].third) num_exc++;
        update(ranks[i].scnd, ranks[i].third);
    }

    printf("%d\n", num_exc);
}