#include <bits/stdc++.h>

using namespace std;

struct DSU {
public:
    int n;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = n;
        ds.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++)
            ds[i] = i, sz[i] = 1;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] < sz[j]) swap(i, j);
        if (i != j) sz[i] += sz[j];
        ds[j] = i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int cnt = 0;
        DSU tree(2 * n);
        map<string, int> idx;

        while (n--) {
            string s, t;
            cin >> s >> t;

            if (!idx.count(s)) idx[s] = cnt++;
            if (!idx.count(t)) idx[t] = cnt++;

            tree.join(idx[s], idx[t]);
            cout << tree.sz[tree.find(idx[s])] << "\n";
        }
    }
}