#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int N, M, H, W, row, col;
vector<vector<bool>> vis;

int paint(int i, int j) {
    if (i > N || j > M || vis[i][j]) return 0;
    if (i < row || i >= row + H || j < col || j >= col + W) return 0;

    int ans = 1;
    vis[i][j] = true;

    ans += paint(i - 1, j);
    ans += paint(i + 1, j);
    ans += paint(i, j - 1);
    ans += paint(i, j + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> N >> M >> H >> W >> Q;
    vis.assign(N + 1, vector<bool>(M + 1, false));

    vector<set<int>> rows(M + 1, set<int>());
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            rows[i].insert(j);

    int ans = N * M;
    while (Q--) {
        if (!ans) {
            cout << "0\n";
            continue;
        }

        cin >> row >> col;
        auto begin = rows[col].lb(row);
        auto end = rows[col].lb(row + H);

        for (auto it = begin; it != end; it++)
            ans -= paint(*it, col);

        rows[col].erase(begin, end);
        cout << ans << "\n";
    }
}