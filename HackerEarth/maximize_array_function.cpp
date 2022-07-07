#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> A;
vector<vector<long>> memo;

long max_value(int i = 0, int j = 0) {
    if (i >= N) return 0LL;

    long &ans = memo[i][j];
    if (~ans) return ans;

    ans = max_value(i + 1, j);
    ans = max(ans, (j + 1LL) * A[i] + max_value(i + 1, j + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        memo.assign(N, vector<long>(N, -1));

        long ans = max_value();
        cout << ans << "\n";
    }
}