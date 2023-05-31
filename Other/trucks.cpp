#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct PersistentDSU {
private:
    int n;
    vector<int> ds, sz, tm;

public:
    PersistentDSU(int n) {
        this->n = n;
        sz.assign(n, 1);
        tm.assign(n, 0);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);
    }

    int find(int i, int t = INT_MAX) {
        if (ds[i] == i || tm[i] > t) return i;
        return find(ds[i], t);
    }

    void join(int i, int j, int t) {
        i = find(i); j = find(j);
        if (i == j) return;

        if (sz[i] > sz[j]) swap(i, j);
        sz[j] += sz[i];
        ds[i] = j;
        tm[i] = t;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S;
    cin >> N >> M >> S;

    vector<tuple<int, int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        edges[i] = make_tuple(W, A - 1, B - 1);
    }

    sort(edges.rbegin(), edges.rend());

    PersistentDSU tree(N);
    for (int i = 0; i < M; i++) {
        auto [w, u, v] = edges[i];
        tree.join(u, v, i);
    }

    while (S--) {
        int L, H;
        cin >> L >> H;

        int l = 0, r = M - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (tree.find(L - 1, mid) != tree.find(H - 1, mid)) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        assert(ans != -1);
        ans = get<0>(edges[ans]);

        cout << ans << "\n";
    }
}