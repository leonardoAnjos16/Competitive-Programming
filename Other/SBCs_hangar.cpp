#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 51;

int N, K;
vector<long> W, ps;
long comb[MAX][MAX];
long A, B;

long solve(int i = 0, int k = 0, long sum = 0LL) {
    if (sum > B) return 0LL;
    if (k >= K) return sum >= A;
    if (i >= N || sum + ps[N] - ps[i] < A) return 0LL;
    if (sum >= A && sum + ps[N] - ps[i] <= B) return comb[N - i][K - k];
    return solve(i + 1, k, sum) + solve(i + 1, k + 1, sum + W[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    W.resize(N);
    for (int i = 0; i < N; i++)
        cin >> W[i];

    sort(W.rbegin(), W.rend());

    ps.assign(N + 1, 0);
    for (int i = 1; i <= N; i++)
        ps[i] = ps[i - 1] + W[i - 1];

    cin >> A >> B;

    for (int i = 0; i < MAX; i++)
        comb[i][0] = comb[i][i] = 1LL;

    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < i; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];

    long ans = solve();
    cout << ans << "\n";
}