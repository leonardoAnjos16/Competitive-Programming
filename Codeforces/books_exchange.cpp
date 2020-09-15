#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

vector<int> ds, sz;

int find(int i) {
    if (ds[i] == i) return i;
    else ds[i] = find(ds[i]);
    return ds[i];
}

void unite(int i, int j) {
    int r1 = find(i), r2 = find(j);
    if (r1 != r2) {
        if (sz[r1] < sz[r2]) ds[r1] = r2, sz[r2] += sz[r1];
        else ds[r2] = r1, sz[r1] += sz[r2];
    }
}

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);

        ds.assign(n, 0);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            ds[i] = i;

        for (int i = 0; i < n; i++) {
            int p; scanf("%d", &p);
            unite(i, p - 1);
        }

        for (int i = 0; i < n; i++)
            printf("%d ", sz[find(i)]);

        printf("\n");
    }
}