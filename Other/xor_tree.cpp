#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<int> init, goal;
vector<int> operations;

int count(int node = 0, int parent = -1, bool is_even = true, bool even = false, bool odd = false) {
    int curr = is_even ? (even ? 1 - init[node] : init[node]) : (odd ? 1 - init[node] : init[node]);
    bool change = curr != goal[node];

    int ans = change;
    if (ans) operations.push_back(node + 1);

    for (auto child: tree[node])
        if (child != parent) {
            bool new_even = !change ? even : (is_even ? !even : even);
            bool new_odd = !change ? odd : (is_even ? odd : !odd);
            ans += count(child, node, !is_even, new_even, new_odd);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    init.resize(n);
    for (int i = 0; i < n; i++)
        cin >> init[i];

    goal.resize(n);
    for (int i = 0; i < n; i++)
        cin >> goal[i];

    int cnt = count();
    cout << cnt << "\n";

    assert((int) operations.size() == cnt);

    for (int i = 0; i < cnt; i++)
        cout << operations[i] << "\n";
}