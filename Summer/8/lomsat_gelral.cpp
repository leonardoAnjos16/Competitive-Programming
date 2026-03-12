#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int mx_cnt; llong sum;
vector<vector<int>> tree;
vector<int> c, nodes, cnt;
vector<llong> ans;

void get_nodes(int node = 0, int parent = -1) {
    nodes[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            get_nodes(child, node);
            nodes[node] += nodes[child];
        }
}

void add(int node, int parent, int big, int v) {
    cnt[c[node]] += v;
    if (cnt[c[node]] == mx_cnt) sum += c[node] + 1LL;
    else if (cnt[c[node]] > mx_cnt) mx_cnt = cnt[c[node]], sum = c[node] + 1LL;

    for (int child: tree[node])
        if (child != parent && child != big)
            add(child, node, big, v);
}

void solve(int node = 0, int parent = -1, bool keep = true) {
    int mx = 0, big = -1;
    for (int child: tree[node])
        if (child != parent && nodes[child] > mx)
            mx = nodes[child], big = child;

    for (int child: tree[node])
        if (child != parent && child != big)
            solve(child, node, false);

    if (big != -1) solve(big, node);

    add(node, parent, big, 1);
    ans[node] = sum;

    if (!keep) {
        add(node, parent, -1, -1);
        mx_cnt = INT_MIN;
        sum = 0LL;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }

    tree.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;

        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }

    nodes.resize(n);
    get_nodes();

    sum = 0LL;
    mx_cnt = INT_MIN;
    cnt.assign(n, 0);
    ans.resize(n);

    solve();
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}