#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    vector<int> assignment(n);
    iota(assignment.begin(), assignment.end(), 0);

    int ans = INT_MIN;
    do {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += s[i][assignment[i]];

        ans = max(ans, sum);
    } while (next_permutation(assignment.begin(), assignment.end()));

    cout << ans << "\n";
}