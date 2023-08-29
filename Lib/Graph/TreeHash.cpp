int get_hash(int node, int parent = -1) {
    sz[node] = 1;
    vector<pair<int, int>> children;

    for (int child: tree[node])
        if (child != parent) {
            children.emplace_back(get_hash(child, node), child);
            sz[node] += sz[child];
        }

    sort(children.begin(), children.end());

    int ans = 1;
    for (auto [h, child]: children) {
        int p = pow(2, 2 * sz[child]);
        ans = (1LL * ans * p) % MOD;
        ans = (ans + h) % MOD;
    }

    ans = (2LL * ans) % MOD;
    return ans;
}
