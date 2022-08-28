#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

int n, m;
vector<string> grid;
vector<vector<int>> memo;

bool possible(int row, int curr, int last) {
    int idx = 0, cnt = 0;
    while (idx < m) {
        if (curr & (1 << idx)) cnt++;
        else if (cnt & 1) return false;
        else cnt = 0;

        idx++;
    }

    if (cnt & 1) return false;

    for (int i = 0; i < 2 && row - i >= 0; i++)
        for (int j = 0; j < m; j++)
            if (grid[row - i][j] == '#' && !(curr & (1 << j)))
                return false;

    idx = cnt = 0;
    while (idx < m) {
        if (!(curr & (1 << idx))) cnt = 0;
        else {
            cnt++;
            if ((cnt & 1) && !((last & (1 << idx)) || (idx + 1 < m && (last & (1 << (idx + 1)))))) return false;
            else if (!(cnt & 1) && !((last & (1 << idx)) || (idx - 1 >= 0 && (last & (1 << (idx - 1)))))) return false;
        }

        idx++;
    }

    return true;
}

int count(int mask) {
    int idx = 0, cnt = 0, ans = 0;
    while (idx < m) {
        if (mask & (1 << idx)) cnt++;
        else ans += cnt / 2, cnt = 0;

        idx++;
    }

    ans += cnt / 2;
    return ans;
}

int boxes(int row, int last) {
    if (row < 0) return 0;

    int &ans = memo[row][last];
    if (~ans) return ans;

    ans = INF;
    for (int i = 0; i < (1 << m); i++)
        if (possible(row, i, last))
            ans = min(ans, count(i) + boxes(row - 2, i));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    memo.assign(n + 5, vector<int>((1 << m) + 5, -1));

    int ans = boxes(n - 1, (1 << m) - 1);
    cout << ans << "\n";
}