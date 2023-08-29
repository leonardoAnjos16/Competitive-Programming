#include <bits/stdc++.h>

using namespace std;

const int LOG = 20;
const int MAX = 1e5 + 5;

struct FenwickTree {
private:
    int n;
    vector<int> tree;

public:
    FenwickTree() {}
    FenwickTree(int n) {
        this->n = n + 1;
        tree.assign(n + 1, 0);
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

vector<int> A;
vector<vector<int>> tree;
vector<vector<int>> up, Ls;
FenwickTree solver;
vector<int> ans;

int kth_ancestor(int node, int k) {
    for (int i = 0; i < LOG; i++)
        if (k & (1 << i))
            node = up[i][node];

    return node;
}

void solve(int node) {
    for (int L: Ls[node])
        solver.add(L, 1);

    ans[node] = solver.sum(1, A[node]);
    for (int child: tree[node])
        solve(child);

    for (int L: Ls[node])
        solver.add(L, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N);
    vector<int> B(N);
    tree.assign(N, vector<int>());

    int root = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (i == --B[i]) root = i;
        else tree[B[i]].push_back(i);
    }

    assert(root != -1);

    up.assign(LOG, vector<int>(N));
    for (int i = 0; i < N; i++)
        up[0][i] = B[i];

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < N; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];

    Ls.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int O, L, R;
        cin >> O >> L >> R;

        int l = 1, r = N, lift = 0;
        while (l <= r) {
            int mid = (l + r) / 2;

            int ancestor = kth_ancestor(O - 1, mid);
            if (A[ancestor] > R) r = mid - 1;
            else l = mid + 1, lift = mid;
        }

        Ls[kth_ancestor(O - 1, lift)].push_back(L);
    }

    solver = FenwickTree(MAX);
    ans.resize(N);
    solve(root);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}