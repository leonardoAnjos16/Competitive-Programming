#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int N;
vector<string> grid;
vector<bitset<MAX>> vis;

void visit(int i, int j) {
    vis[i][j] = true;
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if ((k || l) && (!k || !l)) {
                int ni = i + k;
                int nj = j + l;

                if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] != '.' && !vis[ni][nj])
                    visit(ni, nj);
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;

        grid.resize(N);
        for (int i = 0; i < N; i++)
            cin >> grid[i];

        vis.assign(N, bitset<MAX>());

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 'x' && !vis[i][j])
                    ans++, visit(i, j);

        cout << "Case " << t << ": " << ans << "\n";
    }
}