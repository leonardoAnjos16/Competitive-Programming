#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct DSU {
private:
    int n;
    bool bipartite;
    vector<int> ds, sz, c;
    vector<vector<int>> children;

public:
    DSU(int n) {
        this->n = n;
        bipartite = true;

        c.assign(n, 0);
        sz.assign(n, 1);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);

        children.assign(n, vector<int>(1));
        for (int i = 0; i < n; i++)
            children[i][0] = i;
    }

    bool is_bipartite() {
        return bipartite;
    }

    int color(int i) {
        return c[i];
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        if (find(i) == find(j) && c[i] == c[j]) bipartite = false;
        else if (find(i) != find(j)) {
            bool change = c[i] == c[j];

            i = find(i); j = find(j);
            if (sz[i] > sz[j]) swap(i, j);
            sz[j] += sz[i];
            ds[i] = ds[j];

            for (int v: children[i]) {
                children[j].push_back(v);
                if (change) c[v] = 1 - c[v];
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> roads(M);
    for (int i = 0; i < M; i++) {
        int x, y, b;
        cin >> x >> y >> b;
        roads[i] = make_tuple(b, x - 1, y - 1);
    }

    sort(roads.rbegin(), roads.rend());

    int l = 0;
    DSU solver(N);
    vector<int> ans;

    while (l < M && solver.is_bipartite()) {
        int r = l + 1;
        while (r < M && get<0>(roads[r]) == get<0>(roads[l])) r++;

        bool possible = false;
        for (int i = l; i < r && i < l + 3 && !possible; i++)
            for (int j = i + 1; j < r && !possible; j++) {
                auto [_, u1, v1] = roads[i];
                auto [__, u2, v2] = roads[j];

                if (u1 == u2 || u1 == v2 || v1 == u2 || v1 == v2) continue;
                if (solver.find(u1) == solver.find(v1) && solver.color(u1) != solver.color(v1)) continue;
                if (solver.find(u2) == solver.find(v2) && solver.color(u2) != solver.color(v2)) continue;

                int c1 = solver.find(u1) == solver.find(v1) ? solver.color(u1) : -1;
                int c2 = solver.find(u2) == solver.find(v2) ? solver.color(u2) : -1;

                if (c1 == -1 && c2 == -1) {
                    if (solver.find(u1) != solver.find(u2) && solver.find(u1) != solver.find(v2)) possible = true;
                    else if (solver.find(v1) != solver.find(u2) && solver.find(v1) != solver.find(v2)) possible = true;
                    else if (solver.find(u1) == solver.find(u2) && solver.color(u1) != solver.color(u2)) possible = true;
                    else if (solver.find(u1) == solver.find(v2) && solver.color(u1) != solver.color(v2)) possible = true;
                }
                else if (c1 == -1 || c2 == -1 || c1 != c2) possible = true;
            }

        if (possible) ans.push_back(get<0>(roads[l]));

        for (int i = l; i < r; i++) {
            auto [_, u, v] = roads[i];
            solver.join(u, v);
        }

        l = r;
    }

    if (solver.is_bipartite()) ans.push_back(0);

    if (ans.empty()) cout << "IMPOSSIBLE\n";
    else {
        reverse(ans.begin(), ans.end());
        for (int w: ans) cout << w << "\n";
    }
}