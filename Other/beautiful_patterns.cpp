#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int N, M;
vector<vector<int>> yard;
vector<vector<int>> memo;

int black(int last_row, int curr_row, int idx) {
    int cnt = !(last_row & (1 << (idx - 1)));
    cnt += !(curr_row & (1 << (idx - 1)));
    cnt += !(last_row & (1 << idx));
    cnt += !(curr_row & (1 << idx));
    return cnt;
}

int patterns(int row = 0, int last_row = 0) {
    if (row >= N) return 1;

    int &ans = memo[row][last_row];
    if (~ans) return ans;

    ans = 0;
    for (int curr_row = 0; curr_row < (1 << M); curr_row++) {
        bool possible = true;
        for (int i = 0; i < M && possible; i++) {
            if (yard[row][i] != -1 && !!(curr_row & (1 << i)) != yard[row][i]) possible = false;
            else if (row && i && black(last_row, curr_row, i) != 1 && black(last_row, curr_row, i) != 3) possible = false;
        }

        if (possible) ans = (ans + patterns(row + 1, curr_row)) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> M >> N >> K;

    yard.assign(N, vector<int>(M, -1));
    for (int i = 0; i < K; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        yard[y - 1][x - 1] = c;
    }

    memo.assign(N + 5, vector<int>((1 << M) + 5, -1));

    int ans = patterns();
    cout << ans << "\n";
}