#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int N;
vector<int> A;
vector<vector<int>> g;
vector<vector<int>> memo;

int albums(int i, int available) {
    if (!available) return A[i];

    int &ans = memo[i][available];
    if (~ans) return ans;

    int cnt = 0;
    for (int v: g[i])
        if (available & (1 << v))
            return ans = 0;

    ans = 0;
    for (int j = 0; j < N; j++)
        if (available & (1 << j))
            ans = (ans + albums(j, available ^ (1 << j))) % MOD;

    ans = (1LL * ans * A[i]) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    g.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        g[A - 1].push_back(B - 1);
    }

    memo.assign(N + 5, vector<int>((1 << N) + 5, -1));

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = (ans + albums(i, ((1 << N) - 1) ^ (1 << i))) % MOD;

    cout << ans << "\n";
}