#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> a, p;
vector<vector<pair<int, int>>> tree;
vector<long> memo;

void get_parents(int node = 0, int parent = -1) {
    p[node] = parent;
    for (auto [child, length]: tree[node])
        if (child != parent)
            get_parents(child, node);
}

long score(int node, int parent) {
    long &ans = memo[node];
    if (~ans) return ans;

    ans = 0;
    for (auto [child, length]: tree[node])
        if (child != parent)
            if (score(child, node) + a[child] - length > 0)
                ans += score(child, node) + a[child] - length;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    tree.assign(N, vector<pair<int, int>>());
    for (int i = 1; i < N; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        l <<= 1;

        tree[u - 1].emplace_back(v - 1, l);
        tree[v - 1].emplace_back(u - 1, l);
    }

    p.resize(N);
    get_parents();

    memo.assign(N + 5, -1LL);

    long ans = 0LL;
    for (int i = 0; i < N; i++)
        ans = max(ans, score(i, p[i]) + a[i]);

    cout << ans << "\n";
}