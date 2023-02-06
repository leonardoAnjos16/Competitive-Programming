#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, m;
vector<string> grid;

void get_dists_and_moves(vector<pair<int, int>> sources, vector<vector<int>> &dists, vector<vector<char>> &moves) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    moves.assign(n, vector<char>(m, '-'));
    dists.assign(n, vector<int>(m, -1));

    for (auto [i, j]: sources) {
        q.emplace(i, j);
        vis[i][j] = true;
        dists[i][j] = 0;
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int di = -1; di <= 1; di++)
            for (int dj = -1; dj <= 1; dj++)
                if ((di || dj) && !(di && dj)) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] != '#') {
                        q.emplace(ni, nj);
                        vis[ni][nj] = true;
                        dists[ni][nj] = dists[i][j] + 1;
                        moves[ni][nj] = ni > i ? 'D' : (ni < i ? 'U' : (nj > j ? 'R' : 'L'));
                    }
                }
    }
}

bool safe(vector<vector<int>> &adists, vector<vector<int>> &mdists, int i, int j) {
    return adists[i][j] != -1 && (mdists[i][j] == -1 || adists[i][j] < mdists[i][j]);
}

void print_moves(vector<vector<char>> &amoves, int i, int j) {
    string ans = "";
    while (amoves[i][j] != '-') {
        char move = amoves[i][j];
        ans += move;

        if (move == 'D') i--;
        else if (move == 'U') i++;
        else if (move == 'R') j--;
        else j++;
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";

    int size = ans.size();
    cout << size << "\n";

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    grid.resize(n);
    pair<int, int> start;
    vector<pair<int, int>> monsters;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = make_pair(i, j);
            else if (grid[i][j] == 'M') monsters.emplace_back(i, j);
        }
    }

    vector<vector<int>> adists;
    vector<vector<char>> amoves;
    get_dists_and_moves({ start }, adists, amoves);

    vector<vector<int>> mdists;
    vector<vector<char>> mmoves;
    get_dists_and_moves(monsters, mdists, mmoves);

    for (int i = 0; i < n; i++) {
        if (safe(adists, mdists, i, 0)) {
            print_moves(amoves, i, 0);
            return 0;
        }

        if (safe(adists, mdists, i, m - 1)) {
            print_moves(amoves, i, m - 1);
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (safe(adists, mdists, 0, i)) {
            print_moves(amoves, 0, i);
            return 0;
        }

        if (safe(adists, mdists, n - 1, i)) {
            print_moves(amoves, n - 1, i);
            return 0;
        }
    }

    cout << "NO\n";
}