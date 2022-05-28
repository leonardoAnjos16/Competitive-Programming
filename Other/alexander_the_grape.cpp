#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int N;
vector<vector<tuple<int, int, int>>> tree;
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

int reachable(int node = 0, int parent = -1) {
    int &ans = memo[node];
    if (~ans) return ans;

    ans = 1;
    for (auto [child, P, Q]: tree[node])
        if (child != parent) {
            int prob = (1LL * P * mod_mult_inv(Q, MOD)) % MOD;
            int aux = (1LL * reachable(child, node) * prob) % MOD;
            ans = (ans + aux) % MOD;
        }

    return ans;
}

int solve(int value, int node = 0, int parent = -1) {
    int ans = value;
    for (auto [child, P, Q]: tree[node])
        if (child != parent) {
            int prob = (1LL * P * mod_mult_inv(Q, MOD)) % MOD;
            int aux = (1LL * reachable(child, node) * prob) % MOD;
            int new_value = (value - aux + MOD) % MOD;

            prob = (1LL * (Q - P) * mod_mult_inv(Q, MOD)) % MOD;
            aux = (1LL * new_value * prob) % MOD;
            new_value = (reachable(child, node) + aux) % MOD;

            ans = (ans + solve(new_value, child, node)) % MOD;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    tree.assign(N, vector<tuple<int, int, int>>());
    for (int i = 1; i < N; i++) {
        int A, B, P, Q;
        cin >> A >> B >> P >> Q;

        tree[A - 1].emplace_back(B - 1, P, Q);
        tree[B - 1].emplace_back(A - 1, Q - P, Q);
    }

    memo.assign(N, -1);

    int ans = solve(reachable());
    ans = (1LL * ans * mod_mult_inv(N, MOD)) % MOD;
    cout << ans << "\n";
}