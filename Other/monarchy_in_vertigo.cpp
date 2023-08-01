#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
    }

    void add(int i, int v) {
        if (!i) tree[i] += v;
        else {
            while (i < n) {
                tree[i] += v;
                i += LSO(i);
            }
        }
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

private:
    int LSO(int i) {
        return i & -i;
    }

    int sum(int i) {
        if (i < 0) return 0;

        int ans = tree[0];
        while (i) {
            ans += tree[i];
            i -= LSO(i);
        }

        return ans;
    }
};

vector<int> tree[MAX];
vector<int> pos, monarch;

void init(int &vis, int node = 0) {
    pos[node] = vis;
    monarch[vis++] = node;

    for (int child: tree[node])
        init(vis, child);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;

    int id = 1;
    vector<int> queries;

    while (Q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) tree[x - 1].push_back(id++);
        else queries.push_back(x - 1);
    }

    int vis = 0;
    pos.resize(id);
    monarch.resize(id);
    init(vis);

    FenwickTree solver(id);
    for (int x: queries) {
        solver.add(pos[x], 1);

        int l = 0, r = id - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (solver.sum(0, mid) >= mid + 1) l = mid + 1;
            else r = mid - 1, ans = monarch[mid] + 1;
        }

        assert(ans != -1);
        cout << ans << "\n";
    }
}