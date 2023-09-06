#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 5;

string s;
int n, total_ones = 0;
vector<vector<vector<int>>> memo;

int zero_ones(int ones, int one_zeros) {
    int zeros = n - ones;
    int one_ones = ones * (ones - 1) / 2;
    int zero_zeros = zeros * (zeros - 1) / 2;
    return n * (n - 1) / 2 - one_zeros - one_ones - zero_zeros;
}

int swaps(int i = 0, int ones = 0, int one_zeros = 0) {
    if (i >= n) return ones == total_ones && one_zeros == zero_ones(ones, one_zeros) ? 0 : INF;

    int &ans = memo[i][ones][one_zeros];
    if (~ans) return ans;

    ans = swaps(i + 1, ones, one_zeros + ones);
    ans = min(ans, swaps(i + 1, ones + 1, one_zeros) + (s[i] != '1'));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            total_ones++;

    memo.assign(n + 5, vector<vector<int>>(n + 5, vector<int>(n * (n - 1) / 2 + 5, -1)));

    int ans = swaps();
    cout << ans << "\n";
}