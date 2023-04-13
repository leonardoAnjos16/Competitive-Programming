#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<bool>> attend(n, vector<bool>(5, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++) {
            int can; cin >> can;
            attend[i][j] = can;
        }

    bool possible = false;
    for (int i = 0; i < 5 && !possible; i++)
        for (int j = 0; j < 5 && !possible; j++)
            if (i != j) {
                int ci = 0, cj = 0, cij = 0;
                for (int k = 0; k < n; k++) {
                    if (attend[k][i] && attend[k][j]) cij++;
                    else if (attend[k][i]) ci++;
                    else if (attend[k][j]) cj++;
                }

                if (ci >= n / 2 && cj >= n / 2) possible = true;
                else if (ci <= n / 2 && cj <= n / 2 && cij >= n - ci - cj) possible = true;
            }

    cout << (possible ? "YES" : "NO") << "\n";
}