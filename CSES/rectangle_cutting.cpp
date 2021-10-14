#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> memo;

int moves(int a, int b) {
    if (a == b) return 0;

    int &ans = memo[a][b];
    if (~ans) return ans;

    ans = INT_MAX;
    for (int i = 1; i < a; i++)
        ans = min(ans, moves(i, b) + moves(a - i, b) + 1);

    for (int i = 1; i < b; i++)
        ans = min(ans, moves(a, i) + moves(a, b - i) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    memo.assign(a + 5, vector<int>(b + 5, -1));

    int ans = moves(a, b);
    cout << ans << "\n";
}