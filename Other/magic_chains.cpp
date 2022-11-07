#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;
vector<int> parent;

void get_dists() {
    parent.assign(n, -1);

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: g[v])
            if (u && parent[u] == -1) {
                q.push(u);
                parent[u] = v;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    unordered_map<string, int> idx;
    vector<string> dict(n);

    g.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> dict[i];

        string t = dict[i];
        for (int j = 0; j < (int) dict[i].size(); j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                t[j] = c;
                if (idx.count(t)) {
                    int k = idx[t];
                    g[i].push_back(k);
                    g[k].push_back(i);
                }

                t[j] = dict[i][j];
            }
        }

        idx[dict[i]] = i;
    }

    get_dists();

    if (parent[n - 1] == -1) cout << "FAIL";
    else {
        int v = n - 1;
        vector<int> ans;

        while (parent[v] != -1) {
            ans.push_back(v);
            v = parent[v];
        }

        ans.push_back(0);

        int size = ans.size();
        cout << size << "\n";

        for (int i = size - 1; i >= 0; i--)
            cout << dict[ans[i]] << "\n";
    }
}