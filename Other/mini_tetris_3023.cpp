#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

vector<vector<vector<int>>> memo;

int max_cols(int b, int c, int rows = 0) {
    int &ans = memo[b][c][rows];
    if (~ans) return ans;

    if (rows == 0) {
        ans = 0;
        if (c >= 1) {
            ans = max(ans, max_cols(b, c - 1, 1) + 1);
            ans = max(ans, max_cols(b, c - 1, 2) + 1);
        }

        return ans;
    }
    
    if (rows == 1) {
        ans = -INF;
        if (c >= 1)
            ans = max(ans, max_cols(b, c - 1, 0) + 2);

        return ans;
    }

    ans = -INF;
    if (b >= 1)
        ans = max(ans, max_cols(b - 1, c, 2) + 2);

    if (c >= 1)
        ans = max(ans, max_cols(b, c - 1, 0) + 2);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    while (a--) ans += 2;

    memo.assign(b + 5, vector<vector<int>>(c + 5, vector<int>(5, -1)));

    ans += max_cols(b, c);
    cout << ans << "\n";
}