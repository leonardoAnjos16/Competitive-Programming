#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

vector<vector<int>> g;
bitset<MAX> vis;

void traverse(int ignore = -1, int v = 0) {
    if (v == ignore) return;

    vis[v] = true;
    for (auto u: g[v])
        if (!vis[u])
            traverse(ignore, u);
}

void print_row_sep(int N) {
    cout << "+";
    for (int i = 1; i < 2 * N; i++)
        cout << "-";

    cout << "+\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        g.assign(N, vector<int>());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int edge; cin >> edge;
                if (edge) g[i].push_back(j);
            }
        }

        vis.reset();
        traverse();

        bitset<MAX> reachable = vis;
        vector<vector<char>> ans(N, vector<char>(N));
        
        for (int i = 0; i < N; i++) {
            vis.reset();
            traverse(i);

            bitset<MAX> new_reachable = vis;
            for (int j = 0; j < N; j++)
                ans[i][j] = (reachable[j] && !new_reachable[j] ? 'Y' : 'N');
        }

        cout << "Case " << t << ":\n";
        print_row_sep(N);

        for (int i = 0; i < N; i++) {
            cout << "|";
            for (int j = 0; j < N; j++)
                cout << ans[i][j] << "|";

            cout << "\n";
            print_row_sep(N);
        }
    }
}