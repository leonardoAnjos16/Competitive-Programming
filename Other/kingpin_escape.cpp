#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> tree;
vector<int> leaves;

void get_leaves(int node, int parent = -1) {
    if ((int) tree[node].size() <= 1) leaves.push_back(node);

    for (int child: tree[node])
        if (child != parent)
            get_leaves(child, node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    get_leaves(h);
    int num_leaves = leaves.size();

    vector<pair<int, int>> ans;
    for (int i = 0; i < num_leaves / 2; i++)
        ans.emplace_back(leaves[i], leaves[i + (num_leaves + 1) / 2]);

    if (num_leaves & 1) ans.emplace_back(leaves[num_leaves / 2], h);

    int m = ans.size();
    cout << m << "\n";

    for (auto [a, b]: ans)
        cout << a << " " << b << "\n";
}