#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int p, q;
vector<vector<vector<int>>> memo;

int total(int rows, int cols, bool black) {
    if (!(rows & 1) || !(cols & 1)) return 0;
    return black ? 1 : -1;
}

int score(int turn, int i, int j) {
    if (i >= q || j < 0) return 0;

    int &ans = memo[turn][i][j];
    if (ans != INT_MIN) return ans;

    if (!turn) {
        int sum = 0;
        for (int k = i; k < q; k++) {
            if (!(j & 1)) sum += (k & 1) ? -1 : 1;
            ans = max(ans, sum + (total(j + 1, q - k - 1, k & 1) - score(1 - turn, k + 1, j)));
        }

        return ans;
    }

    int sum = 0;
    for (int k = j; k >= 0; k--) {
        if ((q - i) & 1) sum += (q & 1) && !(k & 1) ? 1 : (!(q & 1) && (k & 1) ? 1 : -1);
        ans = max(ans, sum + (total(k, q - i, !(i & 1)) - score(1 - turn, i, k - 1)));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> q;

    memo.assign(2, vector<vector<int>>(q + 5, vector<int>(p + 5, INT_MIN)));

    int ans = score(0, 0, p - 1);
    ans = 2 * ans - total(p, q, true);
    cout << ans << "\n";
}