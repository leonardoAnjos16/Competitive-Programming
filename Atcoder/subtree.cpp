#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int N, M;
vector<vector<int>> tree;
vector<int> ways, ans;

void get_ways(int node = 0, int parent = -1) {
    ways[node] = 1;
    for (int child: tree[node])
        if (child != parent) {
            get_ways(child, node);
            ways[node] = (1LL * ways[node] * ways[child]) % M;
        }

    ways[node]++;
    ways[node] %= M;
}

void solve(int node = 0, int parent = -1, int above = 1) {
    int prod = (ways[node] - 1 + M) % M;
    ans[node] = (1LL * prod * above) % M;

    vector<int> children;
    for (int child: tree[node])
        if (child != parent)
            children.push_back(ways[child]);

    int sz = children.size();
    vector<int> pp(sz + 1, 1);

    for (int i = 1; i <= sz; i++)
        pp[i] = (1LL * pp[i - 1] * children[i - 1]) % M;

    vector<int> sp(sz + 2, 1);
    for (int i = sz; i > 0; i--)
        sp[i] = (1LL * sp[i + 1] * children[i - 1]) % M;

    int idx = 1;
    for (int child: tree[node])
        if (child != parent) {
            int nabove = (1LL * pp[idx - 1] * sp[idx + 1]) % M;
            nabove = (1LL * nabove * above) % M;
            nabove = (nabove + 1) % M;

            solve(child, node, nabove);
            idx++;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    tree.assign(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;

        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }

    ways.resize(N);
    get_ways();

    ans.resize(N);
    solve();

    for (int i = 0; i < N; i++)
        cout << ans[i] << "\n";
}