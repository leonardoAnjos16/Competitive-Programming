#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
vector<vector<int>> tree;
vector<int> depth, nodes;
vector<long> ans;

void get_depth_and_nodes(int node = 0, int parent = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            depth[child] = depth[node] + 1;
            get_depth_and_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

void solve(long sum, int node = 0, int parent = -1) {
    ans[node] = sum;
    for (int child: tree[node])
        if (child != parent)
            solve(sum + n - 2 * nodes[child], child, node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    nodes.resize(n);
    depth.assign(n, 0);
    get_depth_and_nodes();

    long sum = 0LL;
    for (int i = 0; i < n; i++)
        sum += depth[i];

    ans.resize(n);
    solve(sum);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}