#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<bool> reachable;
vector<int> nodes;

void get_reachable_and_nodes(int X, int node = 0, int parent = -1) {
    if (node == X) reachable[node] = true;

    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            get_reachable_and_nodes(X, child, node);
            if (reachable[child]) reachable[node] = true;
            nodes[node] += nodes[child];
        }
}

int rides(int X, int node = 0, int parent = -1) {
    for (int child: tree[node])
        if (child == X) return 1;

    int ans = 0, nxt = -1;
    for (int child: tree[node])
        if (child != parent) {
            if (reachable[child]) nxt = child;
            else ans += 2 * nodes[child];
        }

    assert(nxt != -1);
    ans += rides(X, nxt, node) + 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X;
    cin >> N >> X;

    tree.assign(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int A, B;
        cin >> A >> B;

        tree[A - 1].push_back(B - 1);
        tree[B - 1].push_back(A - 1);
    }

    reachable.assign(N, false);
    nodes.resize(N);

    get_reachable_and_nodes(X - 1);

    int ans = rides(X - 1);
    cout << ans << "\n";
}