#include <bits/stdc++.h>

using namespace std;

int K;
vector<vector<int>> g;
vector<int> ans;

int mex(vector<int> &used) {    
    int size = used.size();
    sort(used.begin(), used.end());

    if (!size || used[0] > 1)
        return 1;

    for (int i = 1; i < size; i++)
        if (used[i] > used[i - 1] + 1)
            return used[i - 1] + 1;

    return used[size - 1] + 1;
}

bool possible(int v) {
    vector<int> used;
    for (int u: g[v])
        if (ans[u])
            used.push_back(ans[u]);

    int f = mex(used);
    if (f > K) return false;

    ans[v] = f;
    for (int u: g[v])
        if (!ans[u] && !possible(u))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M >> K;

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    ans.assign(N, 0);

    bool pos = true;
    for (int i = 0; i < N && pos; i++)
        if (!ans[i] && !possible(i))
            pos = false;

    if (!pos) cout << "-1\n";
    else {
        for (int i = 0; i < N; i++)
            cout << ans[i] << "\n";
    }
}