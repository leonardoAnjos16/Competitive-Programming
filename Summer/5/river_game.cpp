#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<int> memo;

int mex(vector<int> &nimbers) {
    sort(nimbers.begin(), nimbers.end());
    if (nimbers.empty() || nimbers[0]) return 0;

    for (int i = 1; i < (int) nimbers.size(); i++)
        if (nimbers[i] > nimbers[i - 1] + 1)
            return nimbers[i - 1] + 1;

    return nimbers.back() + 1;
}

int grundy(vector<int> &adjacent, int blocked = 0) {
    int size = adjacent.size();
    if (blocked + 1 == (1 << size)) return 0;

    int &ans = memo[blocked];
    if (~ans) return ans;

    vector<int> nimbers;
    for (int i = 0; i < size; i++)
        if (!(blocked & (1 << i)))
            nimbers.push_back(grundy(adjacent, blocked | adjacent[i] | (1 << i)));

    return ans = mex(nimbers);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    vector<vector<pair<int, int>>> shores;
    vector<vector<bool>> vis(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!vis[i][j] && grid[i][j] == '*') {
                queue<pair<int, int>> q;
                q.emplace(i, j);

                vis[i][j] = true;
                set<pair<int, int>> adjacent;

                while (!q.empty()) {
                    auto [row, col] = q.front(); q.pop();
                    for (int drow = -1; drow <= 1; drow++)
                        for (int dcol = -1; dcol <= 1; dcol++)
                            if ((drow || dcol) && !(drow && dcol)) {
                                int nrow = row + drow, ncol = col + dcol;
                                if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < N && !vis[nrow][ncol]) {
                                    if (grid[nrow][ncol] == '.') adjacent.emplace(nrow, ncol);
                                    else if (grid[nrow][ncol] == '*') {
                                        q.emplace(nrow, ncol);
                                        vis[nrow][ncol] = true;
                                    }
                                }
                            }
                }

                for (auto [row, col]: adjacent)
                    if (!vis[row][col]) {
                        q.emplace(row, col);
                        vis[row][col] = true;

                        vector<pair<int, int>> shore;
                        while (!q.empty()) {
                            tie(row, col) = q.front(); q.pop();
                            shore.emplace_back(row, col);

                            for (int drow = -1; drow <= 1; drow++)
                                for (int dcol = -1; dcol <= 1; dcol++)
                                    if ((drow || dcol) && !(drow && dcol)) {
                                        int nrow = row + drow, ncol = col + dcol;
                                        if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < N && !vis[nrow][ncol] && adjacent.count(make_pair(nrow, ncol))) {
                                            q.emplace(nrow, ncol);
                                            vis[nrow][ncol] = true;
                                        }
                                    }
                        }

                        shores.push_back(shore);
                    }
            }

    int ans = 0;
    for (auto shore: shores) {
        int size = shore.size();
        vector<int> adjacent(size, 0);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                auto [r1, c1] = shore[i];
                auto [r2, c2] = shore[j];

                if (abs(r2 - r1) + abs(c2 - c1) == 1)
                    adjacent[i] |= (1 << j);
            }

        memo.assign((1 << size) + 5, -1);

        ans ^= grundy(adjacent);
    }

    cout << (ans ? "First" : "Second") << " player will win\n";
}