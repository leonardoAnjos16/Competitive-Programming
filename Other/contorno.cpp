#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<vector<int>> g;
vector<int> color;

bool intersect(int a, int b, int c, int d) {
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }

    if (d < b || c > b) return false;
    return true;
}

bool bicolorable(int v, int c = 0) {
    if (color[v] != -1) return color[v] == c;

    color[v] = c;
    for (int u: g[v])
        if (!bicolorable(u, 1 - c))
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vector<int>> colors(N, vector<int>());
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        colors[c - 1].push_back(i);
    }

    int edges = 0;
    bool possible = true;
    vector<vector<int>> edge(N, vector<int>(N));

    for (int i = 0; i < N && possible; i++) {
        int sz = colors[i].size();
        if (sz > 4) possible = false;
        else {
            for (int j = 0; j < sz; j++)
                for (int k = j + 1; k < sz; k++)
                    edge[colors[i][j]][colors[i][k]] = edges++;
        }
    }

    if (!possible) cout << "N\n";
    else {
        g.assign(edges, vector<int>());
        for (int i = 0; i < N; i++) {
            if ((int) colors[i].size() == 4) {
                int u = edge[colors[i][0]][colors[i][2]];
                int v = edge[colors[i][1]][colors[i][3]];

                g[u].push_back(v);
                g[v].push_back(u);
            }

            for (int j = i + 1; j < N; j++)
                for (int k = 0; k < (int) colors[i].size(); k++)
                    for (int l = k + 1; l < (int) colors[i].size(); l++)
                        for (int m = 0; m < (int) colors[j].size(); m++)
                            for (int n = m + 1; n < (int) colors[j].size(); n++)
                                if (intersect(colors[i][k], colors[i][l], colors[j][m], colors[j][n])) {
                                    int u = edge[colors[i][k]][colors[i][l]];
                                    int v = edge[colors[j][m]][colors[j][n]];

                                    g[u].push_back(v);
                                    g[v].push_back(u);
                                }
        }

        color.assign(edges, -1);
        for (int i = 0; i < edges && possible; i++)
            if (color[i] == -1 && !bicolorable(i))
                possible = false;

        cout << (possible ? "S" : "N") << "\n";
    }
}