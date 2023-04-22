#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

string s, order;
vector<vector<int>> memo;

int moves(int i = 0, int j = 0) {
    if (j >= (int) s.size()) return 0;
    if (i >= 4) return INF;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = min(moves(i + 1, j), moves(i, j + 1) + 1);
    if (s[j] == order[i])
        ans = min(ans, moves(i, j + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    order = "cdhs";
    int ans = INT_MAX;

    do {
        memo.assign(5, vector<int>((int) s.size() + 5, -1));
        ans = min(ans, moves());
    } while (next_permutation(order.begin(), order.end()));

    cout << ans << "\n";
}