#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n;
vector<vector<int>> tree;
vector<int> dists;

void get_dists(int node = 0, int parent = -1) {
    for (int child: tree[node])
        if (child != parent) {
            dists[child] = dists[node] + 1;
            get_dists(child, node);
        }
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

    dists.assign(n, 0);
    get_dists();

    int node = max_element(dists.begin(), dists.end()) - dists.begin();
    dists.assign(n, 0);
    get_dists(node);

    vector<int> ans = dists;

    node = max_element(dists.begin(), dists.end()) - dists.begin();
    dists.assign(n, 0);
    get_dists(node);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        ans[i] = max(ans[i], dists[i]);
        cout << ans[i];
    }

    cout << "\n";
}