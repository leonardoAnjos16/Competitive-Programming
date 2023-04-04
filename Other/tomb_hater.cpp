#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

struct Trie {
private:
    int nodes;
    vector<bool> end;
    vector<vector<int>> nxt;

public:
    Trie(): nodes(1) {
        end.push_back(false);
        nxt.emplace_back(26, -1);
    }

    void insert(string &s) {
        int node = 0, idx = 0;
        while (idx < (int) s.size()) {
            if (nxt[node][s[idx] - 'A'] == -1) {
                nxt[node][s[idx] - 'A'] = nodes++;
                nxt.emplace_back(26, -1);
                end.push_back(false);
            }

            node = nxt[node][s[idx++] - 'A'];
        }

        end[node] = true;
    }

    bool terminal(int node) {
        return end[node];
    }

    int next(int node, char c) {
        return nxt[node][c - 'A'];
    }

    int size() {
        return nodes;
    }
};

int m, n;
Trie trie;
vector<vector<char>> grid;
vector<vector<vector<vector<int>>>> memo;

int shortest_route(int row, int col, int node = 0, int from = 0) {
    if (col < 0 || col >= n || node == -1) return INF;
    if (row >= m) return trie.terminal(node) ? 0 : INF;

    int &ans = memo[from][row][col][node];
    if (~ans) return ans;

    ans = shortest_route(row + 1, col, trie.next(node, grid[row][col]));
    if (from != 2) ans = min(ans, shortest_route(row, col - 1, trie.next(node, grid[row][col]), 1));
    if (from != 1) ans = min(ans, shortest_route(row, col + 1, trie.next(node, grid[row][col]), 2));
    ans++;

    if (trie.terminal(node))
        ans = min(ans, shortest_route(row, col, 0, from));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> m >> n >> k;

    grid.assign(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        string word; cin >> word;
        trie.insert(word);
    }

    memo.assign(5, vector<vector<vector<int>>>(m + 5, vector<vector<int>>(n + 5, vector<int>(trie.size() + 5, -1))));

    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, shortest_route(0, i));

    if (ans >= INF) cout << "impossible\n";
    else cout << ans << "\n";
}