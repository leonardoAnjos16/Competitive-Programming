#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct DSU {
private:
    int n;
    vector<int> sz, ds;

public:
    DSU(int n) {
        this->n = n;
        sz.assign(n, 1);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return false;

        if (sz[i] > sz[j]) swap(i, j);
        sz[j] += sz[i];
        ds[i] = j;

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> bits(N);
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        while (k--) {
            int c; cin >> c;
            bits[c - 1].push_back(i);
        }
    }

    DSU tree(M);
    int rank = 0;

    for (int i = 0; i < N; i++) {
        assert((int) bits[i].size() == 2);
        int u = bits[i][0], v = bits[i][1];
        rank += tree.join(u, v);
    }

    cout << rank << "\n";
}