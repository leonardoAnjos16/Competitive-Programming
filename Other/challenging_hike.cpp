#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<vector<int>> tree;
vector<int> lis, ans;

void solve(int node = 0) {
    int prev = -1;
    int idx = lower_bound(lis.begin(), lis.end(), v[node]) - lis.begin();

    if (idx >= (int) lis.size()) lis.push_back(v[node]);
    else {
        prev = lis[idx];
        lis[idx] = v[node];
    }

    ans[node] = lis.size();
    for (int child: tree[node])
        solve(child);

    if (prev == -1) lis.pop_back();
    else lis[idx] = prev;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    tree.assign(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int p; cin >> p;
        tree[p - 1].push_back(i);
    }

    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    ans.assign(N, -1);
    solve();

    for (int i = 1; i < N; i++) {
        if (i > 1) cout << " ";

        assert(ans[i] != -1);
        cout << ans[i];
    }

    cout << "\n";
}