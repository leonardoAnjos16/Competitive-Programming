#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for (int i = 0; i < n; i++)
        cin >> field[i];

    long ans = 0LL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] == '*') {
                int up = 0, right = 0, down = 0, left = 0;
                for (int k = j - 1; k >= 0; k--) if (field[i][k] == '*') up++;
                for (int k = i + 1; k < n; k++) if (field[k][j] == '*') right++;
                for (int k = j + 1; k < m; k++) if (field[i][k] == '*') down++;
                for (int k = i - 1; k >= 0; k--) if (field[k][j] == '*') left++;

                ans += up * right;
                ans += right * down;
                ans += down * left;
                ans += left * up;
            }

    cout << ans << "\n";
}