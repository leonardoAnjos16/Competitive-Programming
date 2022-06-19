#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 998244853;

int K;
vector<int> A;
vector<vector<int>> digits;
vector<int> memo;

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans = (1LL * ans * ans) % MOD;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
    return exp(a, m - 2);
}

int expected_number(int i = 0) {
    if (i + 1 >= K) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = 0;
    int cnt = 0;

    for (int w: digits[i]) {
        int aux = (1LL * w * exp(10, K - i - 2)) % MOD;
        aux = (aux + expected_number(i + 1)) % MOD;

        ans = (ans + aux) % MOD;
        cnt++;
    }

    ans = (1LL * ans * mod_mult_inv(cnt, MOD)) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> g(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u - 1].emplace_back(v - 1, w);
        g[v - 1].emplace_back(u - 1, w);
    }

    A.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }

    int idx = 0;
    bool possible = true;
    digits.resize(K);

    while (idx + 1 < K && possible) {
        possible = false;
        for (auto [v, w]: g[A[idx]])
            if (v == A[idx + 1]) {
                possible = true;
                digits[idx].push_back(w);
            }

        idx++;
    }

    if (!possible) cout << "Stupid Msacywy!\n";
    else {
        memo.assign(K + 5, -1);

        int ans = expected_number();
        cout << ans << "\n";
    }
}