#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int cnt = 0;
vector<vector<int>> tree;
vector<int> g, groups, ans;

void solve(int node) {
    if (groups[g[node]]++ == 0) cnt++;

    ans[node] = cnt;
    for (int child: tree[node])
        solve(child);

    if (--groups[g[node]] == 0) cnt--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int root = -1;
    tree.assign(N, vector<int>());

    for (int i = 0; i < N; i++) {
        int s; cin >> s;

        if (!s) root = i;
        else tree[s - 1].push_back(i);
    }

    assert(root != -1);

    g.resize(N);
    for (int i = 0; i < N; i++)
        cin >> g[i];

    groups.assign(N + 1, 0);
    ans.resize(N);
    solve(root);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}