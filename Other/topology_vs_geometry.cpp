#include <bits/stdc++.h>

using namespace std;

#define long long long int

typedef tuple<int, int, int, int, int, int> line;

struct DSU {
private:
    int groups;
    vector<int> ds, sz;

public:
    DSU(int n) {
        groups = n;
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
        if (i == j) return;

        if (sz[i] > sz[j]) swap(i, j);
        sz[j] += sz[i]; ds[i] = j;
        groups--;
    }

    bool connected() {
        return groups == 1;
    }
};

line get_line(int x1, int y1, int z1, int x2, int y2, int z2) {
    auto p1 = make_tuple(x1, y1, z1), p2 = make_tuple(x2, y2, z2);
    return p1 < p2 ? make_tuple(x1, y1, z1, x2, y2, z2) : make_tuple(x2, y2, z2, x1, y1, z1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("triangles.in", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        map<line, int> ids; int id = 0;
        vector<tuple<int, int, int>> triangles(N);

        for (int i = 0; i < N; i++) {
            int x1, y1, z1, x2, y2, z2, x3, y3, z3;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;

            line l1 = get_line(x1, y1, z1, x2, y2, z2);
            if (!ids.count(l1)) ids[l1] = id++;

            line l2 = get_line(x1, y1, z1, x3, y3, z3);
            if (!ids.count(l2)) ids[l2] = id++;

            line l3 = get_line(x2, y2, z2, x3, y3, z3);
            if (!ids.count(l3)) ids[l3] = id++;

            triangles[i] = make_tuple(ids[l1], ids[l2], ids[l3]);
        }

        DSU dsu(id);
        for (int i = 0; i < N; i++) {
            int l1, l2, l3;
            tie(l1, l2, l3) = triangles[i];

            dsu.join(l1, l2);
            dsu.join(l2, l3);
        }

        cout << (dsu.connected() ? "Yes" : "No") << "\n";
    }
}