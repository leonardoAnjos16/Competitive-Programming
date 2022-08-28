#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> M(m + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> M[i][j];

    int s, f, r;
    cin >> s >> f >> r;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (M[i][j] == s) {
                bool possible = false;
                for (int k = 0; k < 4 && !possible; k++)
                    if (M[i + dy[k]][j + dx[k]] == f && M[i + dy[(k + 1) % 4]][j + dx[(k + 1) % 4]] == r)
                        possible = true;

                if (possible) cout << (i - 1) << " " << (j - 1) << "\n";
            }
}