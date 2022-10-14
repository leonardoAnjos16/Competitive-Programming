#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<string> grid;
vector<vector<int>> dists;
vector<vector<char>> moves;
 
void get_dists(int i, int j) {
    moves.assign(n, vector<char>(m, '-'));
    dists.assign(n, vector<int>(m, -1));
    dists[i][j] = 0;
 
    queue<pair<int, int>> q;
    q.emplace(i, j);
 
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        
        for (int di = -1; di <= 1; di++)
            for (int dj = -1; dj <= 1; dj++)
                if ((di || dj) && !(di && dj)) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != '#' && dists[ni][nj] == -1) {
                        q.emplace(ni, nj);
                        dists[ni][nj] = dists[i][j] + 1;
                        moves[ni][nj] = ni > i ? 'D' : (ni < i ? 'U' : (nj > j ? 'R' : 'L'));
                    }
                }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
 
    grid.resize(n);
    int ai, aj, bi, bj;
 
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') ai = i, aj = j;
            else if (grid[i][j] == 'B') bi = i, bj = j;
        }
    }
 
    get_dists(ai, aj);
 
    if (dists[bi][bj] == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << dists[bi][bj] << "\n";
 
        string ans = "";
        int i = bi, j = bj;
 
        while (moves[i][j] != '-') {
            ans += moves[i][j];
            int ni = i + (moves[i][j] == 'D' ? -1 : (moves[i][j] == 'U' ? 1 : 0));
            int nj = j + (moves[i][j] == 'R' ? -1 : (moves[i][j] == 'L' ? 1 : 0));
            i = ni; j = nj;
        }
 
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}