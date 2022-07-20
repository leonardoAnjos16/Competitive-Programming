#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> color;

bool bicolorable(int v, int c = 0) {
    if (color[v] != -1)
        return color[v] == c;
    
    color[v] = c;
    for (int u: g[v])
        if (!bicolorable(u, 1 - c))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        bool possible = true;
        vector<vector<int>> pairs(n);

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            if (a == b) possible = false;

            pairs[a - 1].push_back(i);
            pairs[b - 1].push_back(i);
        }

        for (int i = 0; i < n && possible; i++)
            if ((int) pairs[i].size() > 2)
                possible = false;

        if (!possible) cout << "NO\n";
        else {
            g.assign(n, vector<int>());
            for (int i = 0; i < n; i++)
                for (int j = 0; j < (int) pairs[i].size(); j++)
                    for (int k = j + 1; k < (int) pairs[i].size(); k++) {
                        g[pairs[i][j]].push_back(pairs[i][k]);
                        g[pairs[i][k]].push_back(pairs[i][j]);
                    }

            color.assign(n, -1);
            for (int i = 0; i < n && possible; i++)
                if (color[i] == -1)
                    possible = bicolorable(i);
            
            cout << (possible ? "YES" : "NO") << "\n";
        }
    }
}