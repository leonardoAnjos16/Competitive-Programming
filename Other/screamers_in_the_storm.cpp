#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int D, R;
vector<vector<int>> cnt, sum;

pair<int, int> total_sum(int i = 0, int curr_sum = 0) {
    if (curr_sum > R * R) return make_pair(0, 0);
    if (i >= D) return make_pair(1, 0);

    if (cnt[i][curr_sum] != -1)
        return make_pair(cnt[i][curr_sum], sum[i][curr_sum]);

    cnt[i][curr_sum] = sum[i][curr_sum] = 0;
    for (int x = -R; x <= R; x++) {
        auto [c, s] = total_sum(i + 1, curr_sum + x * x);
        cnt[i][curr_sum] = (cnt[i][curr_sum] + c) % MOD;

        int aux = (1LL * c * abs(x) + s) % MOD;
        sum[i][curr_sum] = (sum[i][curr_sum] + aux) % MOD;
    }

    return make_pair(cnt[i][curr_sum], sum[i][curr_sum]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> R;

    cnt.assign(D + 5, vector<int>(R * R + 5, -1));
    sum.assign(D + 5, vector<int>(R * R + 5, -1));

    auto [_, ans] = total_sum();
    cout << ans << "\n";
}