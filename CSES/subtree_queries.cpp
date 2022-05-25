#include <bits/stdc++.h>

using namespace std;

#define long long long int

int t = 0;
vector<int> in, out;
vector<vector<int>> tree;
vector<int> v;

struct FenwickTree {
private:
    int n;
    vector<long> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0LL);
    }

    void add(int i, int v) {
        if (!i) tree[0] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    long sum(int i) {
        if (i < 0) return 0LL;

        long ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

void tour(int node = 0, int parent = -1) {
    in[node] = t++;
    for (int child: tree[node])
        if (child != parent)
            tour(child, node);

    out[node] = t++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    in.resize(n);
    out.resize(n);
    tour();

    FenwickTree solver(t);
    for (int i = 0; i < n; i++)
        solver.add(in[i], v[i]);

    while (q--) {
        int op, s;
        cin >> op >> s;

        if (op == 1) {
            int x; cin >> x;

            solver.add(in[s - 1], x - v[s - 1]);
            v[s - 1] = x;
        } else {
            long ans = solver.sum(in[s - 1], out[s - 1]);
            cout << ans << "\n";
        }
    }
}