#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> field(n);
        for (int i = 0; i < n; i++)
            cin >> field[i];

        vector<vector<bool>> marked(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (field[i][j] == '*') {
                    int left = 0, r = i - 1, c = j - 1;
                    while (r >= 0 && c >= 0 && field[r][c] == '*')
                        left++, r--, c--;

                    int right = 0; r = i - 1, c = j + 1;
                    while (r >= 0 && j < m && field[r][c] == '*')
                        right++, r--, c++;

                    int aux = min(left, right);
                    if (aux < k) continue;

                    marked[i][j] = true;
                    for (int k = 1; k <= aux; k++)
                        marked[i - k][j - k] = marked[i - k][j + k] = true;
                }

        bool possible = true;
        for (int i = 0; i < n && possible; i++)
            for (int j = 0; j < m && possible; j++)
                if (field[i][j] == '*' && !marked[i][j])
                    possible = false;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}