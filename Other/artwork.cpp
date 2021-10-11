#include <bits/stdc++.h>

using namespace std;

struct DSU {
private:
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

long double dist(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    vector<tuple<int, int, int>> sensors(K);
    for (int i = 0; i < K; i++) {
        int X, Y, S;
        cin >> X >> Y >> S;
        sensors[i] = make_tuple(X, Y, S);
    }

    DSU tree(K);
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            if (i != j) {
                auto [xi, yi, si] = sensors[i];
                auto [xj, yj, sj] = sensors[j];

                if (dist(xi, yi, xj, yj) <= si + sj)
                    tree.join(i, j);
            }

    map<int, vector<int>> components;
    for (int i = 0; i < K; i++) {
        int root = tree.find(i);
        components[root].push_back(i);
    }

    for (auto [root, component]: components) {
        bool up = false, right = false, down = false, left = false;
        for (auto i: component) {
            auto [x, y, s] = sensors[i];
            up |= x - s <= 0;
            right |= y + s >= N;
            down |= x + s >= M;
            left |= y - s <= 0;
        }

        bool ans = up && down;
        ans |= up && left;
        ans |= right && down;
        ans |= right && left;

        if (ans) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
}