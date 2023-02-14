#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<int> b;
vector<vector<int>> tree;
vector<vector<llong>> memo;

llong beauty(int out = 0, int node = 0, int parent = -1) {
    llong &ans = memo[out][node];
    if (~ans) return ans;

    llong sum = 0LL;
    vector<llong> changes;

    for (int child: tree[node])
        if (child != parent) {
            sum += beauty(1, child, node);
            changes.push_back(beauty(0, child, node) - beauty(1, child, node));
        }

    llong aux = 0LL;
    int degree = out;
    sort(changes.rbegin(), changes.rend());

    ans = sum + b[out];
    for (llong c: changes) {
        aux += c;
        degree++;
        ans = max(ans, sum + aux + b[degree]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    memo.assign(2, vector<llong>(n + 5, -1LL));

    llong ans = beauty();
    cout << ans << "\n";
}