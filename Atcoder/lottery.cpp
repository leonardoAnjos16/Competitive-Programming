#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 60;
const int MOD = 998244353;

int facts[MAX], invs[MAX];

int N, M, K;
vector<int> p;
vector<vector<vector<int>>> memo;

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

int comb(int n, int k) {
    int num = facts[n];
    int den = (1LL * invs[k] * invs[n - k]) % MOD;
    return (1LL * num * den) % MOD;
}

int prob(int i = 0, int draws = 0, int diff = 0) {
    if (diff > M) return 0;
    if (draws >= K) return diff == M;
    if (i >= N || K - draws < M - diff) return 0;

    int &ans = memo[i][draws][diff];
    if (~ans) return ans;

    ans = 0;
    for (int take = 0; take <= K - draws; take++) {
        int aux = (1LL * exp(p[i], take) * prob(i + 1, draws + take, diff + (take > 0))) % MOD;
        aux = (1LL * aux * comb(K - draws, take)) % MOD;
        ans = (ans + aux) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts[0] = invs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (1LL * facts[i - 1] * i) % MOD;
        invs[i] = mod_mult_inv(facts[i], MOD);
    }

    cin >> N >> M >> K;

    int sum = 0;
    vector<int> W(N);

    for (int i = 0; i < N; i++) {
        cin >> W[i];
        sum += W[i];
    }

    p.resize(N);
    int sum_inv = mod_mult_inv(sum, MOD);

    for (int i = 0; i < N; i++)
        p[i] = (1LL * W[i] * sum_inv) % MOD;

    memo.assign(N + 5, vector<vector<int>>(K + 5, vector<int>(M + 5, -1)));

    int ans = prob();
    cout << ans << "\n";
}