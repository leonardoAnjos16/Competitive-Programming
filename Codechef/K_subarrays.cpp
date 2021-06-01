#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long INF = 1e18;

int N, K;
vector<long> A;
vector<vector<vector<long>>> memo;

long score(int in = 0, int i = 0, int k = 0) {
    if (k >= K) return 0LL;
    if (i >= N) return -INF;

    long &ans = memo[in][i][k];
    if (~ans) return ans;

    long aux = A[i] * (k + 1);
    ans = aux + score(1, i + 1, k);
    ans = max(ans, aux + score(0, i + 1, k + 1));
    ans = max(ans, score(0, i + 1, k + in));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N >> K;
        A.resize(N);

        for (int i = 0; i < N; i++)
            cin >> A[i];

        memo.assign(2, vector<vector<long>>(N, vector<long>(K, -1LL)));

        long ans = score();
        cout << ans << "\n";
    }
}