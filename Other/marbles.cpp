#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int memo[MAX][MAX];

int grundy(int i, int j) {
    if (!i && !j) return 0;
    if (!i || !j || i == j) return 2 * MAX;

    int &ans = memo[i][j];
    if (~ans) return ans;

    bool seen[4 * MAX] = {0};
    for (int k = i - 1; k >= 0; k--)
        seen[grundy(k, j)] = true;

    for (int k = j - 1; k >= 0; k--)
        seen[grundy(i, k)] = true;

    for (int d = 1; i - d >= 0 && j - d >= 0; d++)
        seen[grundy(i - d, j - d)] = true;

    for (int k = 0; k < 4 * MAX && ans == -1; k++)
        if (!seen[k]) ans = k;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    memset(memo, -1, sizeof memo);

    int ans = 0;
    while (N--) {
        int l, c;
        cin >> l >> c;
        ans ^= grundy(l, c);

        if (l == c) {
            cout << "Y\n";
            return 0;
        }
    }

    cout << (ans ? "Y" : "N") << "\n";
}