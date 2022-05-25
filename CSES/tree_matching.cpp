#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> tree;
vector<vector<int>> memo;

int max_matching(bool match, int node = 0, int parent = -1) {
    if (tree[node].empty()) return 0;

    int &ans = memo[match][node];
    if (~ans) return ans;

    ans = 0;
    for (auto child: tree[node])
        if (child != parent)
            ans += max_matching(true, child, node);

    if (!match) return ans;

    int sum = ans;
    for (auto child: tree[node])
        if (child != parent)
            ans = max(ans, sum - max_matching(true, child, node) + max_matching(false, child, node) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    memo.assign(2, vector<int>(n, -1));

    int ans = max(max_matching(true), max_matching(false));
    cout << ans << "\n";
}